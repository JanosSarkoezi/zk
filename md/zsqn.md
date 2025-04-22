# Left Anti JOIN

Ein Left Anti Join in MS SQL Server ist kein expliziter Join-Typ wie INNER JOIN
oder LEFT JOIN, aber du kannst ihn mit einer Kombination aus LEFT JOIN und
einer Bedingung auf NULL simulieren.

## Ziel eines Left Anti Join:

Du möchtest alle Zeilen aus der linken Tabelle, die keine Entsprechung in der
rechten Tabelle haben.

## Syntax mit LEFT JOIN und WHERE ... IS NULL

```sql
SELECT a.*
FROM TabelleA a
LEFT JOIN TabelleB b ON a.ID = b.ID
WHERE b.ID IS NULL;
```
Erklärung:
- LEFT JOIN bringt alle Zeilen aus TabelleA, und nur passende Zeilen aus
  TabelleB.
- WHERE b.ID IS NULL filtert genau die Zeilen heraus, bei denen keine
  Übereinstimmung in TabelleB gefunden wurde.

## Alternativ mit NOT EXISTS (oft performanter):

```sql
SELECT a.*
FROM TabelleA a
WHERE NOT EXISTS (
    SELECT 1
    FROM TabelleB b
    WHERE b.ID = a.ID
);
```
