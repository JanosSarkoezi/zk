# Generieren von changeSet

```sql
--/
DECLARE @Output NVARCHAR(MAX) = ''
DECLARE @CurrentListID INT

DECLARE ListCursor CURSOR FOR 
SELECT ListID FROM T_List WHERE ListID IN (1, 4, 7, 16, 22, 25, 28, 31, 34, 37, 40, 43, 46, 49, 52, 55, 61
)

OPEN ListCursor
FETCH NEXT FROM ListCursor INTO @CurrentListID

WHILE @@FETCH_STATUS = 0
BEGIN
    SET @Output = @Output + '    <changeSet id="DEV-4473.' + CAST(@CurrentListID AS VARCHAR) + '" author="saj">' + CHAR(13) + CHAR(10)
    SET @Output = @Output + '        <sql>' + CHAR(13) + CHAR(10)

    -- sp_add_list
    SELECT @Output = @Output + '            exec sp_add_list '
        + CONVERT(VARCHAR, ListID)
        + COALESCE(', ''' + REPLACE(Name, '''','''''') + '''', ', NULL')
        + COALESCE(', ''' + REPLACE(Description, '''','''''') + '''', ', NULL')
        + ', 1'
        + ', ' + CONVERT(VARCHAR, HibernateVersion)
        + COALESCE(', ''' + LabelI18n + '''', ', NULL') + CHAR(13) + CHAR(10)
    FROM T_List WHERE ListID = @CurrentListID

    -- sp_add_listelemente
    SELECT @Output = @Output + '            exec sp_add_listelement '
        + CONVERT(VARCHAR, ListelementID)
        + ', ' + CONVERT(VARCHAR, ListID)
        + COALESCE(', ''' + REPLACE(Name, '''','''''') + '''', ', NULL')
        + COALESCE(', ''' + REPLACE(Description, '''','''''') + '''', ', NULL')
        + COALESCE(', ' + CONVERT(VARCHAR, Rank), ', NULL')
        + ', 1'
        + COALESCE(', ''' + CONVERT(VARCHAR, AvailableFrom, 120) + '''', ', NULL')
        + COALESCE(', ''' + CONVERT(VARCHAR, AvailableTo, 120) + '''', ', NULL')
        + ', ' + CONVERT(VARCHAR, HibernateVersion)
        + COALESCE(', ''' + LabelI18n + '''', ', NULL') + CHAR(13) + CHAR(10)
    FROM T_Listelement WHERE ListID = @CurrentListID

    SET @Output = @Output + '        </sql>' + CHAR(13) + CHAR(10)
    SET @Output = @Output + '    </changeSet>' + CHAR(13) + CHAR(10) + CHAR(13) + CHAR(10)

    FETCH NEXT FROM ListCursor INTO @CurrentListID
END

CLOSE ListCursor
DEALLOCATE ListCursor

SELECT @Output AS LiquibaseExport
/
```
