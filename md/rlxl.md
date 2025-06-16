# Java 21 Stream-Optimierung für DTOs

Kann man mit Java-21 diese Zeilen in strem besser behandeln?
```java
private void createProcurementDtos(List<BusinessObjectContainer> boc) {
    procurements = new ArrayList<>();
    for (BusinessObjectContainer b : boc) {
        ProcurementDto dto = new ProcurementDto();

        dto.setId(b.getBusinessObject().getMainId());
        BusinessObjectAttribute boa = getAttributeByAttributeId(b, Beschaffung.ATTR_ID_ARTIKELNUMMER);

        dto.setOrderNumber(boa.getAttributeValue());
        dto.setProcess(map.get(b.getBusinessObject().getMainId()));
        BusinessObjectAttribute bo_title = getAttributeByAttributeId(b, Beschaffung.ATTR_ID_BEZEICHNUNG);
        if (bo_title != null && StringUtils.isNotBlank(bo_title.getAttributeValue())) {
            dto.setName(bo_title.getAttributeValue());
        }

        BusinessObjectAttribute bo_sum = b.getAttributeByPvaId(Beschaffung.PVAID_AUFTRAGSSUMME);
        if (bo_sum != null && StringUtils.isNotBlank(bo_sum.getAttributeValue())) {
            dto.setSum(bo_sum.getAttributeValue());
        }

        BusinessObjectAttribute bo_suminvoice = b.getAttributeByPvaId(Beschaffung.PVAID_SUMME_RECHNUNGSEINGANG);
        if (bo_suminvoice != null && StringUtils.isNotBlank(bo_suminvoice.getAttributeValue())) {
            dto.setSumInvoice(bo_suminvoice.getAttributeValue());
        }

        BusinessObjectAttribute bo_supplier = b.getAttributeByPvaId(Beschaffung.PVAID_LIEFERANT);
        if (bo_supplier != null && StringUtils.isNotBlank(bo_supplier.getAttributeValue())) {
            dto.setSupplier(bo_supplier.getAttributeValue());
        }

        BusinessObjectAttribute bo_date = getAttributeByAttributeId(b, Beschaffung.ATTR_ID_LIEFERTERMIN);
        if (bo_date != null && StringUtils.isNotBlank(bo_date.getAttributeValue())) {
            dto.setDeliveryDate(DateHelper.formatString(R.MSG.get("pattern.date.dash"), bo_date.getAttributeValue()));
        }

        BusinessObjectAttribute bo_amount = getAttributeByAttributeId(b, Beschaffung.ATTR_ID_MENGE);
        if (bo_amount != null && StringUtils.isNotBlank(bo_amount.getAttributeValue())) {
            dto.setAmount(Integer.valueOf(bo_amount.getAttributeValue()));
        }

        procurements.add(dto);
    }
    procurements.sort(Comparator.comparing((ProcurementDto d) -> d.id).reversed());
}
```

Ja, mit Java 21 und dem Einsatz von Streams lässt sich dieser Code deutlich
eleganter, lesbarer und weniger fehleranfällig gestalten.

Das Hauptproblem im aktuellen Code ist die **imperative Arbeitsweise**: Du
erstellst ein leeres Objekt und befüllst es Schritt für Schritt (Side-Effects).
Mit Streams wechseln wir zu einem **funktionalen Ansatz**.

### Optimierungsvorschlag (Stream-Ansatz)

Hier ist eine moderne Umsetzung, die `map` zur Transformation und `sorted` für
die Sortierung nutzt:

```java
private void createProcurementDtos(List<BusinessObjectContainer> boc) {
    this.procurements = boc.stream()
        .map(this::mapToDto)
        .sorted(Comparator.comparing(ProcurementDto::getId).reversed())
        .toList(); // Java 16+ Feature, erzeugt eine unmodifiable Liste
}

private ProcurementDto mapToDto(BusinessObjectContainer b) {
    ProcurementDto dto = new ProcurementDto();
    String mainId = b.getBusinessObject().getMainId();

    dto.setId(mainId);
    dto.setProcess(map.get(mainId));

    // Nutzung von Hilfsmethoden zur Reduzierung von Boilerplate
    setIfPresent(getAttributeByAttributeId(b, Beschaffung.ATTR_ID_ARTIKELNUMMER), dto::setOrderNumber);
    setIfPresent(getAttributeByAttributeId(b, Beschaffung.ATTR_ID_BEZEICHNUNG), dto::setName);
    setIfPresent(b.getAttributeByPvaId(Beschaffung.PVAID_AUFTRAGSSUMME), dto::setSum);
    setIfPresent(b.getAttributeByPvaId(Beschaffung.PVAID_SUMME_RECHNUNGSEINGANG), dto::setSumInvoice);
    setIfPresent(b.getAttributeByPvaId(Beschaffung.PVAID_LIEFERANT), dto::setSupplier);
    
    setIfPresent(getAttributeByAttributeId(b, Beschaffung.ATTR_ID_LIEFERTERMIN), 
        val -> dto.setDeliveryDate(DateHelper.formatString(R.MSG.get("pattern.date.dash"), val)));

    setIfPresent(getAttributeByAttributeId(b, Beschaffung.ATTR_ID_MENGE), 
        val -> dto.setAmount(Integer.valueOf(val)));

    return dto;
}

// Kleine Hilfsmethode für die Logik: "Wenn vorhanden und nicht leer, dann setze"
private void setIfPresent(BusinessObjectAttribute boa, Consumer<String> setter) {
    if (boa != null && StringUtils.isNotBlank(boa.getAttributeValue())) {
        setter.accept(boa.getAttributeValue());
    }
}

```

---

### Was wurde verbessert?

1. **Funktionale Trennung**: Die `createProcurementDtos`-Methode kümmert sich
   nur noch um den Datenfluss (Stream, Sortierung, Speicherung). Die Logik, wie
ein einzelnes DTO entsteht, liegt in einer eigenen Methode (`mapToDto`).
2. **`toList()` statt `ArrayList**`: Seit Java 16 (in Java 21 Standard) nutzt
   man `.toList()`, was kürzer ist als `.collect(Collectors.toList())`.
3. **Vermeidung von Code-Duplikaten**: Die wiederkehrende Prüfung auf `null`
   und `isNotBlank` wurde in die Hilfsmethode `setIfPresent` ausgelagert. Das
macht den Mapping-Code extrem sauber.
4. **Sortierung im Stream**: Anstatt die Liste am Ende manuell zu sortieren,
   ist die Sortierung nun Teil der Pipeline. Das ist intuitiver zu lesen.
5. **Reversed Sorting**: `Comparator.comparing(...).reversed()` ist der saubere
   Weg, um Abwärtssortierung zu implementieren.

### Ein Tipp zu Java 21 (Records)

Falls `ProcurementDto` nur ein reiner Datenträger ist und später nicht mehr
verändert wird (Immutable), könntest du prüfen, ob du ein **Java Record**
daraus machst. Records passen perfekt zum funktionalen Stream-Stil.

### Ein weiterer Schritt: Optional

Wenn du die `null`-Prüfungen noch "moderner" (aber manchmal etwas
schwerfälliger) gestalten willst, könntest du `Optional` in der Hilfsmethode
nutzen:

```java
private void setIfPresent(BusinessObjectAttribute boa, Consumer<String> setter) {
    Optional.ofNullable(boa)
            .map(BusinessObjectAttribute::getAttributeValue)
            .filter(StringUtils::isNotBlank)
            .ifPresent(setter);
}

```
