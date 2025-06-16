# Git Branch Unterschiede

## Frage

Wie kann ich die Unterschiede zwischen zwei git Branches ermitteln. Zum
Beispiel mein feature Branch gegen develop?

## Antwort

Um die Unterschiede zwischen zwei Git-Branches – z. B. deinem `feature`-Branch
und `develop` – zu ermitteln, gibt es mehrere Möglichkeiten, abhängig davon,
was genau du wissen willst (z. B. Commits, Dateien, Codeänderungen).

Hier sind die gängigsten Methoden:


### **1. Unterschiede im Code anzeigen (diff)**

Zeigt dir die Änderungen im Code zwischen zwei Branches:

```bash
git diff develop..feature
```

> Vertausche die Branches, um die Richtung der Änderungen zu ändern.

Wenn du wissen willst, welche Änderungen in `feature` im Vergleich zu `develop` enthalten sind.

### **2. Unterschiedliche Dateien anzeigen (nur Dateinamen)**

Nur geänderte/neu hinzugefügte/gelöschte Dateien:

```bash
git diff --name-status develop..feature
```

Oder nur Dateinamen:

```bash
git diff --name-only develop..feature
```

### **3. Unterschiedliche Commits anzeigen**

Welche Commits sind im `feature`-Branch, aber nicht in `develop`:

```bash
git log develop..feature
```

Oder umgekehrt:

```bash
git log feature..develop
```

Option für besseres Format:

```bash
git log develop..feature --oneline --graph
```

---

### **4. Zusammenfassung der Unterschiede**

Eine Zusammenfassung mit Anzahl der Änderungen:

```bash
git diff --stat develop..feature
```

---

### **Bonus: Was würde gemerged werden?**

Was würde passieren, wenn du `feature` in `develop` mergest:

```bash
git log develop..feature --oneline
```

Oder für eine präzise Vorschau auf einen Merge:

```bash
git diff develop...feature
```

> Der dreifache Punkt (`...`) zeigt Unterschiede zum gemeinsamen Vorfahren der beiden Branches – nützlich für Merge-Vorschau.

