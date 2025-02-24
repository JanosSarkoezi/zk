# Loeschen aus der Tabelle T_Property

```sql
DECLARE @id_list NVARCHAR(MAX);
SELECT @id_list = STUFF((
    SELECT ', ''' + PropKey + ''''
    FROM T_Property
    WHERE PropKey LIKE '%provision%' OR PropKey LIKE '%commission%'
    ORDER BY PropKey
    FOR XML PATH(''), TYPE).value('.', 'NVARCHAR(MAX)')
, 1, 1, '');

DECLARE @sql NVARCHAR(MAX);
SELECT 'DELETE FROM T_Property WHERE PropKey IN (' + @id_list + ')'
```

## Referenzen
- [SQL-Tricks](c66r.md)
