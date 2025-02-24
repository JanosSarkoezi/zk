# Aufruf der sp_add_listelement

```sql
SELECT 'exec sp_add_listelement '
    + CONVERT(VARCHAR, ListelementID)
    + ', ' + CONVERT(VARCHAR, ListID)
    + COALESCE(', ''' + Name + '''', ', NULL')
    + COALESCE(', ''' + REPLACE(Description, '''','''''') + '''', ', NULL')
    + COALESCE(', ' + CONVERT(VARCHAR, Rank), ', NULL')
    + ', 1'
    + COALESCE(', ''' + CONVERT(VARCHAR, AvailableFrom, 120) + '''', ', NULL')
    + COALESCE(', ''' + CONVERT(VARCHAR, AvailableTo, 120) + '''', ', NULL')
    + ', ' + CONVERT(VARCHAR, HibernateVersion)
    + COALESCE(', ''' + LabelI18n + '''', ', NULL')
FROM T_Listelement
WHERE (Name LIKE '%provision%' AND ListID IN (-108, -10, -25, -58) AND ListelementID < 0) OR ListID IN (-182, -170, -163, -87, -88)
```

## Referenzen
- [SQL-Tricks](c66r.md)
