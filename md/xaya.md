# Insert in die Tabelle T_Property

```sql
SELECT 'INSERT INTO T_Property ("PropKey", "PropValue", "Description", "Fixed", "ListelementTypeId", "HibernateVersion") VALUES ('
    + COALESCE('''' + PropKey + '''', ', NULL')
    + COALESCE(', ''' + PropValue + '''', ', NULL')
    + COALESCE(', ''' + REPLACE(Description, '''','''''') + '''', ', NULL')
    + COALESCE(', ' + CONVERT(VARCHAR, Fixed) , ', NULL')
    + ', ' + CONVERT(VARCHAR, ListelementTypeId)
    + ', ' + CONVERT(VARCHAR, HibernateVersion)
    + ')'
FROM T_Property
WHERE PropKey LIKE '%provision%' OR PropKey LIKE '%commission%'
```

## Referenzen
- [SQL-Tricks](c66r.md)
