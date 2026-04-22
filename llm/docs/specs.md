# Wiki Specs - Architektur & Technisches Mapping

Diese Spezifikation beschreibt die technische Umsetzung des LLM-Wiki Parsers, das Mapping von Markdown-Dateien auf SQLite-Strukturen und die Generierung von LaTeX-Dokumenten.

---

## 1. Verzeichnisstruktur (Source)

Das Projekt ist in drei Hauptbereiche unterteilt:

- `src/common/`: Gemeinsam genutzte Logik (Datenbank-Anbindung, Datenstrukturen, Utilities).
- `src/importer/`: Logik zum Einlesen und Parsen der Markdown-Dateien in `wiki/`.
- `src/exporter/`: Logik zur Extraktion und Konvertierung der Datenbankeinträge in LaTeX.

---

## 2. Datenstruktur (`Document`)

Die zentrale Struktur in `src/common/document.h` spiegelt die Felder der SQLite-Datenbank wider.

```c
typedef struct {
    char *key;      // Eindeutiger Primärschlüssel (aus Dateiname/Header)
    char *title;    // Titel des Eintrags
    char *type;     // Kategorie (satz, def, axiom, etc.)
    char *tags;     // Kommagetrennte Schlagworte
    char *refs;     // Referenzen auf andere Keys [key1, key2]
    char *content;  // Hauptinhalt (Satzbau)
    char *proof;    // Beweis oder technische Ausführung
} Document;
```

---

## 3. Importer & Parser-Ablauf

Der Importer (`src/importer/`) nutzt einen Zustandsautomaten in `import.c`, um die Markdown-Dateien zeilenweise zu verarbeiten:

1.  **START**: Suche nach dem ersten `---`.
2.  **HEADER**: Extrahiere YAML `key: value` Paare.
3.  **BODY**: Lese den Inhalt bis zum Separator `--proof--`.
4.  **PROOF**: Lese den Rest der Datei als Beweis-Block.

Zur effizienten Speicherverwaltung wird die `StringBuilder`-Utility aus `src/common/sb_helper.c` verwendet.

---

## 4. SQLite Mapping

Die Datenbank `wiki.db` enthält die Tabelle `entries`. Die Speicherung erfolgt in `src/common/database.c` mittels **Prepared Statements**, um Sonderzeichen (insb. LaTeX-Backslashes) sicher zu verarbeiten.

| Markdown Feld | Datenbank Spalte | Datentyp |
| :--- | :--- | :--- |
| `key` | `key` | `TEXT (PRIMARY KEY)` |
| `title` | `title` | `TEXT` |
| `type` | `type` | `TEXT` |
| `content` | `content` | `TEXT` |
| `proof` | `proof` | `TEXT` |

---

## 5. Exporter-Spezifikation

Der Exporter (`src/exporter/`) generiert aus Suchergebnissen ein kompilierbares LaTeX-Dokument.

### Funktionen & Logik
- **Dependency Resolution**: Mit `--refs` werden alle in `refs` genannten Keys automatisch in den Export aufgenommen.
- **Regex-Suche**: Alle Suchbegriffe werden mittels einer in C implementierten `REGEXP`-Funktion (via `sqlite3_create_function`) gegen alle Textspalten geprüft.
- **Theorem-Mapping**: Der `type` wird auf LaTeX-Umgebungen gemappt:
  - `satz`, `theorem`, `lemma` -> `\begin{satz} ... \end{satz}`
  - `def`, `definition` -> `\begin{definition} ... \end{definition}`
  - `axiom` -> `\begin{axiom} ... \end{axiom}`

### Sortierung & Deduplikation
- Einträge werden nach einer logischen Hierarchie sortiert: 1. Axiome, 2. Definitionen, 3. Sätze, 4. Sonstiges.
- Innerhalb der Gruppen erfolgt die Sortierung alphabetisch nach `title`.
- Eine interne `KeyList` verhindert, dass doppelt referenzierte Einträge mehrfach im Dokument erscheinen.

---

## 6. Hilfsprogramme (Common)

### StringBuilder (`sb_helper.c`)
Bietet dynamisch wachsenden Speicher für String-Operationen. Dies ist essenziell für die Verarbeitung beliebig langer Beweistexte.

```c
void sb_init(StringBuilder *sb, size_t initial_cap);
void sb_append(StringBuilder *sb, const char *str);
char* sb_finish(StringBuilder *sb); // Gibt den finalen Buffer zurück
```

