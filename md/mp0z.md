# Chatverlauf

## Frage

> Kann ich in einer MS SQL Datenban ein Attribut in einer Tabelle vom Typ NVARCHAR (String) den vorderen Teil von dem String ersetzen lassen. Diese Ersetzung sollte mit einem Update durchgefuehrt werden. Beispiel das String heisst a.b.c.Name und ersetzt werden soll es mit c.d.c.Name?

## Antwort

Ja, du kannst den vorderen Teil eines NVARCHAR-Werts in einer MS SQL-Tabelle mit einem UPDATE-Statement und der Funktion `STUFF()` oder `REPLACE()` ersetzen.

### **Lösung mit `STUFF()`**
Die `STUFF()`-Funktion ersetzt eine bestimmte Anzahl von Zeichen in einer Zeichenfolge an einer bestimmten Position:

```sql
UPDATE deine_tabelle
SET deine_spalte = STUFF(deine_spalte, 1, LEN('a.b.c'), 'c.d.c')
WHERE deine_spalte LIKE 'a.b.c.%';
```

- `STUFF(deine_spalte, 1, LEN('a.b.c'), 'c.d.c')` bedeutet:
  - Ersetze ab Position `1` (`1. Zeichen`)
  - Lösche die Anzahl der Zeichen, die `a.b.c` lang ist (`LEN('a.b.c')`)
  - Füge stattdessen `c.d.c` ein.
- `WHERE deine_spalte LIKE 'a.b.c.%'` sorgt dafür, dass nur Strings verändert werden, die mit `a.b.c.` beginnen.

---

### **Lösung mit `REPLACE()`**
Falls der zu ersetzende Teil immer gleich ist, kannst du auch `REPLACE()` nutzen:

```sql
UPDATE deine_tabelle
SET deine_spalte = REPLACE(deine_spalte, 'a.b.c', 'c.d.c')
WHERE deine_spalte LIKE 'a.b.c.%';
```

Das ersetzt **alle** Vorkommen von `a.b.c` in der Spalte durch `c.d.c`, nicht nur am Anfang.

Falls du sicherstellen willst, dass nur der Anfang geändert wird, kannst du `CASE` mit `LEFT()` nutzen:

```sql
UPDATE deine_tabelle
SET deine_spalte = 
    CASE 
        WHEN deine_spalte LIKE 'a.b.c.%' 
        THEN 'c.d.c' + RIGHT(deine_spalte, LEN(deine_spalte) - LEN('a.b.c'))
        ELSE deine_spalte
    END;
```

Diese Variante ändert nur den vorderen Teil und lässt den Rest unverändert.

---

### **Welche Lösung ist besser?**
- **`STUFF()`** ist gut, wenn du genau den Anfang eines Strings ersetzen willst.
- **`REPLACE()`** ersetzt alle Vorkommen – sei vorsichtig, falls `a.b.c` auch später im String auftaucht.
- **`CASE` mit `LEFT()` & `RIGHT()`** gibt dir die höchste Kontrolle.

Teste die Abfragen vorher mit `SELECT`, bevor du das `UPDATE` ausführst, um sicherzustellen, dass die Änderungen korrekt sind.


