# Insert in die Tabelle T_PermissionClass

```sql
SELECT 'INSERT INTO T_PermissionClass ("Name", "Description", "Label") VALUES ('
    + COALESCE('''' + Name + '''', ', NULL')
    + COALESCE(', ''' + REPLACE(Description, '''','''''') + '''', ', NULL')
    + COALESCE(', ''' + Label + '''', ', NULL')
    + ')'
FROM T_PermissionClass
WHERE Name LIKE '%commission%' ORDER BY Name
```

## Referenzen
- [SQL-Tricks](c66r.md)
