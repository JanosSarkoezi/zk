# Erstellen von DDLs fuer verschiedenen Tabellen.

Dieses SQL-Skript erstellr DDLs fuer die uebergebenen Tabellen. Am Anfang und
Ende des Skriptes sind fuer DBVisualizer typische Zeichen gesetzt, damit die
die einzelnen Statements ausfuehren kann. Diese sind `--/` am Anfang und `/` am
Ende.

```sql
--/
SET NOCOUNT ON;

-- 1. Temporäre Tabelle für deine Tabellenliste erstellen
IF OBJECT_ID('tempdb..#TargetTables') IS NOT NULL DROP TABLE #TargetTables;
CREATE TABLE #TargetTables (TableName NVARCHAR(256));

INSERT INTO #TargetTables (TableName) VALUES
('T_CommissionRule'),
('T_CommissionRuleAttribute'),
('T_Core_Attribute'),
('T_Core_ProductVariantAttribute');

-- Variables für die Generierung
DECLARE @SchemaName NVARCHAR(50) = 'dbo';
DECLARE @CurrentTable NVARCHAR(256);
DECLARE @SQL NVARCHAR(MAX);

-- 2. Cursor um die Tabellen nacheinander abzuarbeiten
DECLARE TableCursor CURSOR FOR 
SELECT TableName FROM #TargetTables;

OPEN TableCursor;
FETCH NEXT FROM TableCursor INTO @CurrentTable;

WHILE @@FETCH_STATUS = 0
BEGIN
    -- Prüfen, ob die Tabelle überhaupt in der DB existiert
    IF EXISTS (SELECT 1 FROM sys.tables t JOIN sys.schemas s ON t.schema_id = s.schema_id WHERE t.name = @CurrentTable AND s.name = @SchemaName)
    BEGIN
        SET @SQL = 'CREATE TABLE [' + @SchemaName + '].[' + @CurrentTable + '] (' + CHAR(13) + CHAR(10);
        
        -- Spalten-Metadaten einsammeln
        SELECT @SQL = @SQL + '    [' + c.name + '] ' + 
            tp.name + 
            CASE 
                WHEN tp.name IN ('varchar', 'nvarchar', 'char', 'nchar', 'binary', 'varbinary') THEN 
                    '(' + CASE WHEN c.max_length = -1 THEN 'MAX' ELSE CAST(c.max_length / CASE WHEN tp.name LIKE 'n%' THEN 2 ELSE 1 END AS VARCHAR(10)) END + ')'
                WHEN tp.name IN ('decimal', 'numeric') THEN 
                    '(' + CAST(c.precision AS VARCHAR(5)) + ',' + CAST(c.scale AS VARCHAR(5)) + ')'
                ELSE ''
            END +
            CASE WHEN c.is_identity = 1 THEN ' IDENTITY(' + CAST(ISNULL(ic.seed_value,1) AS VARCHAR(10)) + ',' + CAST(ISNULL(ic.increment_value,1) AS VARCHAR(10)) + ')' ELSE '' END +
            CASE WHEN c.is_nullable = 1 THEN ' NULL' ELSE ' NOT NULL' END + ',' + CHAR(13) + CHAR(10)
        FROM sys.columns c
        JOIN sys.tables t ON c.object_id = t.object_id
        JOIN sys.schemas s ON t.schema_id = s.schema_id
        JOIN sys.types tp ON c.user_type_id = tp.user_type_id
        LEFT JOIN sys.identity_columns ic ON c.object_id = ic.object_id AND c.column_id = ic.column_id
        WHERE t.name = @CurrentTable AND s.name = @SchemaName
        ORDER BY c.column_id;
        
        -- Letztes Komma entfernen und Klammer schließen
        SET @SQL = SUBSTRING(@SQL, 1, LEN(@SQL) - 2) + CHAR(13) + ');' + CHAR(13) + CHAR(10) + 'GO' + CHAR(13) + CHAR(10);
        
        -- Ausgabe im SSMS (unter "Ergebnisse als Text" anzeigen lassen)
        PRINT @SQL;
    END
    ELSE
    BEGIN
        PRINT '-- WARNUNG: Tabelle ' + @SchemaName + '.' + @CurrentTable + ' wurde in der Datenbank nicht gefunden.';
    END

    FETCH NEXT FROM TableCursor INTO @CurrentTable;
END;

CLOSE TableCursor;
DEALLOCATE TableCursor;

-- Aufräumen
DROP TABLE #TargetTables;
/
```
