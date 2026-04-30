# Wiki-Tools

Dieser Ordner enthält Hilfsprogramme zur Automatisierung und Pflege des Wikis.

## update_refs.py

Dieses Skript vernetzt die Markdown-Dateien im `wiki/`-Ordner automatisch, indem es Begriffe im Text in klickbare Querverweise umwandelt.

### Funktionsweise
1.  **Mapping**: Nutzt `mapping.txt`, um zu wissen, welcher `key` zu welchem `Titel` gehört.
2.  **Analyse**: Liest die `refs` aus dem YAML-Header jeder Datei.
3.  **Ersetzung**: Sucht im Content/Proof nach den Titeln der referenzierten Keys und ersetzt diese durch `[[key|Anzeigetext]]`.
4.  **Schutz**: Überspringt automatisch LaTeX-Formeln ($...$ und $$...$$), um die Syntax nicht zu beschädigen.

### Benutzung
Das Skript wird direkt aus dem `tools/`-Ordner oder dem Hauptverzeichnis aufgerufen:
```bash
python3 tools/update_refs.py
```

### mapping.txt
Diese Datei dient als Datenbank für das Skript. Format:
`key|Vollständiger Titel`

Wenn neue Dateien zum Wiki hinzugefügt werden, sollte deren Key und Titel hier eingetragen werden, damit die automatische Verlinkung funktioniert.
