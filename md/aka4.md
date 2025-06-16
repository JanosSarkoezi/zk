# SQL-Join-Erklärung und Beispiel mit T-SQL

## Frage

> Was ist der Unterschied zwischen den beiden SELECT-Statements?

```sql
-- Statement 1
SELECT *
FROM T_Event AS e
JOIN T_EventType AS et ON e.EventTypeId = et.EventTypeId
LEFT JOIN T_EventAttribute AS ea
  JOIN T_EventAttributeType AS eat ON ea.EventAttributeType = eat.EventAttributeTypeId
ON e.EventId = ea.EventId

-- Statement 2
SELECT *
FROM T_Event AS e
JOIN T_EventType AS et ON e.EventTypeId = et.EventTypeId
LEFT JOIN T_EventAttribute AS ea ON e.EventId = ea.EventId
JOIN T_EventAttributeType AS eat ON ea.EventAttributeType = eat.EventAttributeTypeId
```

## Antwort

Gute Frage! Beide SELECT-Statements sehen auf den ersten Blick ähnlich aus, aber sie unterscheiden sich in der Reihenfolge und Art der Verknüpfungen, was große Auswirkungen auf das Ergebnis der Abfrage haben kann. Schauen wir uns das im Detail an.

## Statement 1 (verschachtelter JOIN in der LEFT JOIN-Klausel):

```sql
SELECT *
FROM T_Event AS e
JOIN T_EventType AS et ON e.EventTypeId = et.EventTypeId
LEFT JOIN T_EventAttribute AS ea
  JOIN T_EventAttributeType AS eat ON ea.EventAttributeType = eat.EventAttributeTypeId
ON e.EventId = ea.EventId
```

**Interpretation:**

- T_Event wird mit T_EventType inner gejoined.
- Dann gibt es einen LEFT JOIN auf eine innere Verknüpfung von T_EventAttribute und T_EventAttributeType.
- Dieser innere JOIN (ea JOIN eat) passiert zuerst, bevor der LEFT JOIN mit T_Event gemacht wird.
- Das heißt: Nur die T_EventAttribute-Einträge, die auch eine passende Zeile in T_EventAttributeType haben, werden überhaupt in Betracht gezogen.
- Falls kein passender T_EventAttributeType vorhanden ist, fällt die ganze Kombination weg, selbst wenn ein T_EventAttribute zu T_Event existiert.

## Statement 2 (sequentielle JOINs):

```sql
SELECT *
FROM T_Event AS e
JOIN T_EventType AS et ON e.EventTypeId = et.EventTypeId
LEFT JOIN T_EventAttribute AS ea ON e.EventId = ea.EventId
JOIN T_EventAttributeType AS eat ON ea.EventAttributeType = eat.EventAttributeTypeId
```
**Interpretation:**
- Wieder beginnt es mit einem INNER JOIN zwischen T_Event und T_EventType.
- Dann gibt es einen LEFT JOIN von T_EventAttribute auf T_Event.
- Danach gibt es aber einen INNER JOIN mit T_EventAttributeType.
- Problem: Der JOIN mit eat ist ein INNER JOIN, aber auf das Ergebnis eines LEFT JOINs.
- Das bedeutet: Wenn kein passender ea (oder eat) vorhanden ist, fällt die ganze Zeile raus – also wird der LEFT JOIN faktisch zu einem INNER JOIN.

 ## Was solltest du nehmen?
- Wenn du alle Events sehen willst, auch wenn keine Attribute oder Attributtypen vorhanden sind, ist Statement 1 richtig.
- Wenn du nur Events mit vollständigen Attributen und Typen willst, kannst du Statement 2 nehmen – aber dann brauchst du keinen LEFT JOIN mehr, sondern gleich einen INNER JOIN überall.


