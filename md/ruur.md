# Doku der Tabelle T_PermissionClass

```sql
SELECT '| '
    + COALESCE(Name, ' | NULL')
    + COALESCE(' | ' + Description, ' | NULL')
    + ' |'
FROM T_PermissionClass
WHERE Name LIKE '%commission%' ORDER BY Name
```

## Referenzen
- [SQL-Tricks](c66r.md)
