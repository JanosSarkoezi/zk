# Doku der Spalten einer Tabelle

```sql
SELECT 
    '| ' + COLUMN_NAME + ' | ' + 
    UPPER(DATA_TYPE) + 
    CASE 
        WHEN DATA_TYPE IN ('CHAR', 'NCHAR', 'VARCHAR', 'NVARCHAR') 
            THEN '(' + CAST(CHARACTER_MAXIMUM_LENGTH AS NVARCHAR) + ')'
        WHEN DATA_TYPE IN ('DECIMAL', 'NUMERIC') 
            THEN '(' + CAST(NUMERIC_PRECISION AS NVARCHAR) + ',' + CAST(NUMERIC_SCALE AS NVARCHAR) + ')'
        ELSE ''
    END + 
    ' | ' + CASE WHEN IS_NULLABLE = 'YES' THEN 'NULL' ELSE 'NOT NULL' END + ' |  |' AS Attribut_Info
FROM INFORMATION_SCHEMA.COLUMNS
WHERE TABLE_NAME = 'T_CommissionRulePersonTreeNodeAttribute'
ORDER BY ORDINAL_POSITION;
```

## Referenzen
- [SQL-Tricks](c66r.md)
