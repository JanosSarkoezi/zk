# Update der T_Global_PluginClass

```sql
UPDATE T_Global_PluginClass
SET TechnicalName = STUFF(TechnicalName, 1, LEN('at.intervista.collactive.sellactive.plugin.provi.'), 'at.intervista.collactive.commission.plugin.')
WHERE TechnicalName LIKE 'at.intervista.collactive.sellactive.plugin.provi.%';
```

## Referenzen
- [SQL-Tricks](c66r.md)
