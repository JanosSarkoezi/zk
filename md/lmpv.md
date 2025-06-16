# SQL: Differenz zweier SELECT-Statements in MS SQL Server

## Frage

> Wie kann ich in MS SQL die Differenz von zwei SELECT Statements von einer Tabelle ermitteln?

## Antwort

In **MS SQL Server** kannst du die Differenz zwischen zwei `SELECT`-Statements aus einer Tabelle auf verschiedene Arten berechnen, je nach Art der Differenz, die du benötigst. Hier sind ein paar Ansätze:

---

### 1. `EXCEPT` verwenden (Zeilen-Differenz)
Falls du **Zeilen aus dem ersten `SELECT` entfernen** möchtest, die auch im zweiten vorkommen:

```sql
SELECT Spalte1, Spalte2, ...
FROM DeineTabelle
WHERE Bedingung1
EXCEPT
SELECT Spalte1, Spalte2, ...
FROM DeineTabelle
WHERE Bedingung2;
```

👉 `EXCEPT` gibt alle Zeilen aus dem ersten `SELECT` zurück, die nicht im zweiten `SELECT` enthalten sind.  
🔹 Falls du auch die Differenz in die andere Richtung brauchst, führe das gleiche `EXCEPT` in umgekehrter Reihenfolge aus.

---

### 2. `LEFT JOIN` mit `NULL`-Filter (Zeilen-Differenz mit mehr Kontrolle)
Falls du **sehen möchtest, welche Zeilen in einem `SELECT` fehlen**, kannst du ein `LEFT JOIN` mit `NULL`-Filter nutzen:

```sql
SELECT a.*
FROM (SELECT * FROM DeineTabelle WHERE Bedingung1) a
LEFT JOIN (SELECT * FROM DeineTabelle WHERE Bedingung2) b
ON a.Primärschlüssel = b.Primärschlüssel
WHERE b.Primärschlüssel IS NULL;
```

👉 Findet alle Zeilen aus `Bedingung1`, die nicht in `Bedingung2` vorkommen.  
🔹 Kann auch mit `RIGHT JOIN` umgedreht werden.

---

### 3. Differenz von Summen oder aggregierten Werten
Falls du die **Differenz von Summen oder anderen aggregierten Werten** brauchst:

```sql
SELECT 
    (SELECT SUM(Wert) FROM DeineTabelle WHERE Bedingung1) -
    (SELECT SUM(Wert) FROM DeineTabelle WHERE Bedingung2) AS Differenz;
```

👉 Hier wird die Differenz der Summen der Spalte `Wert` berechnet.  
🔹 Funktioniert genauso mit `COUNT()`, `AVG()`, etc.

---

### 4. `FULL OUTER JOIN` für eine komplette Differenz-Analyse
Falls du **alle Unterschiede aus beiden `SELECT`-Statements sehen möchtest**, nutze einen `FULL OUTER JOIN`:

```sql
SELECT 
    COALESCE(a.Primärschlüssel, b.Primärschlüssel) AS ID,
    a.Wert AS Wert1,
    b.Wert AS Wert2,
    ISNULL(a.Wert, 0) - ISNULL(b.Wert, 0) AS Differenz
FROM (SELECT * FROM DeineTabelle WHERE Bedingung1) a
FULL OUTER JOIN (SELECT * FROM DeineTabelle WHERE Bedingung2) b
ON a.Primärschlüssel = b.Primärschlüssel;
```

👉 Zeigt sowohl fehlende als auch geänderte Werte in beiden `SELECT`-Statements.  
🔹 `COALESCE()` sorgt dafür, dass keine Werte verloren gehen.

---

### Zusammenfassung

| Ziel                          | Methode               |
|------------------------------|------------------------|
| Zeilenunterschied anzeigen   | `EXCEPT`, `LEFT JOIN` |
| Aggregierte Werte vergleichen| `SUM()`, `COUNT()`     |
| Zeilen- und Wertvergleich    | `FULL OUTER JOIN`     |

---

Wenn du ein konkretes Beispiel hast, kann ich dir auch direkt den passenden SQL-Code dazu schreiben 😊


