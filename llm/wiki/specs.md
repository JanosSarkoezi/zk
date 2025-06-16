# Wiki Specs - C-Parser & SQL Mapping

Das ist ein klassisches Problem: Du hast **Frontmatter** (YAML), **Inhalt**
(Markdown) und eine **spezifische Trennung** (`--proof--`). 

In C erfordert das ein sauberes String-Handling. Da C keine native
YAML-Unterstützung hat, ist es am effizientesten, die Datei Zeile für Zeile zu
lesen und eine einfache "State Machine" (Zustandsautomat) zu verwenden.

Hier ist der Entwurf für die Struktur deines C-Programms:

---

## 1. Die Datenstruktur (`struct`)
Zuerst definieren wir eine Struktur, die genau deine Datenbankfelder widerspiegelt.

```c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char *key;
    char *title;
    char *type;
    char *tags;  // Als kommagetrennter String für SQLite
    char *refs;
    char *content;
    char *proof;
} Document;
```

---

## 2. Der Parser-Ablauf (Logik)
Der Parser durchläuft die Datei in vier Phasen:
1.  **START**: Suche nach dem ersten `---`.
2.  **HEADER**: Extrahiere `key: value` Paare bis zum zweiten `---`.
3.  **BODY**: Lese den Satz ein, bis `--proof--` erscheint.
4.  **PROOF**: Lese den Rest der Datei als Beweis ein.

### Skizze der Implementierung

```c
void parse_file(const char *filename, Document *doc) {
    FILE *file = fopen(filename, "r");
    char line[1024];
    int state = 0; // 0: Suche Header, 1: Im Header, 2: Im Inhalt, 3: Im Beweis

    while (fgets(line, sizeof(line), file)) {
        // 1. Header-Grenzen erkennen
        if (strncmp(line, "---", 3) == 0) {
            state = (state == 0) ? 1 : 2;
            continue;
        }

        // 2. Beweis-Separator erkennen
        if (strncmp(line, "--proof--", 9) == 0) {
            state = 3;
            continue;
        }

        // 3. Daten verarbeiten je nach State
        switch (state) {
            case 1: // YAML Header
                extract_yaml_value(line, doc);
                break;
            case 2: // Satz-Inhalt
                append_string(&doc->content, line);
                break;
            case 3: // Beweis-Inhalt
                append_string(&doc->proof, line);
                break;
        }
    }
    fclose(file);
}
```

---

## 3. SQLite Integration
Für die Speicherung in SQLite nutzt du am besten **Prepared Statements**. Das
verhindert SQL-Injection (besonders wichtig bei LaTeX-Sonderzeichen) und ist
performant.

```c
#include <sqlite3.h>

void save_to_db(Document *doc, sqlite3 *db) {
    const char *sql = "INSERT INTO entries (key, title, type, content, proof) VALUES (?, ?, ?, ?, ?);";
    sqlite3_stmt *res;

    sqlite3_prepare_v2(db, sql, -1, &res, 0);
    
    // Bindet die C-Strings an die SQL-Platzhalter (?)
    sqlite3_bind_text(res, 1, doc->key, -1, SQLITE_STATIC);
    sqlite3_bind_text(res, 2, doc->title, -1, SQLITE_STATIC);
    sqlite3_bind_text(res, 3, doc->type, -1, SQLITE_STATIC);
    sqlite3_bind_text(res, 4, doc->content, -1, SQLITE_STATIC);
    sqlite3_bind_text(res, 5, doc->proof, -1, SQLITE_STATIC);

    sqlite3_step(res);
    sqlite3_finalize(res);
}
```

---

## Empfehlungen für die Umsetzung

| Komponente | Empfehlung |
| :--- | :--- |
| **String-Buffer** | Da die Texte lang sein können, nutze `realloc` in einer Hilfsfunktion `append_string`, um den Speicher dynamisch zu vergrößern. |
| **YAML-Parsing** | Wenn die Header komplexer werden (verschachtelt), nimm eine Library wie `libyaml`. Für einfache `key: value` Paare reicht `strtok` oder `sscanf`. |
| **LaTeX Sicherheit** | SQLite speichert die Formeln wie $$a^2 + b^2 = c^2$$ problemlos als Plaintext (UTF-8). Du musst nichts maskieren, solange du Prepared Statements nutzt. |

### Ein kleiner Fallstrick
In deinem Beispiel hast du Tags und Referenzen als Listen: `tags: [geometrie, basics]`. 
* **Einfache Lösung:** Speichere den gesamten String `[geometrie, basics]` direkt in ein Textfeld.
* **Saubere Lösung:** Erstelle eine Zwischentabelle `tags` in SQLite und verknüpfe sie über die `key`-ID (Normalisierung).

Um Textfragmente (Zeilen) dynamisch zu einem großen Block zusammenzufassen,
ohne vorher zu wissen, wie groß der Text wird, ist eine Kombination aus
`realloc` und `strcat` (oder `memcpy`) nötig.

Hier ist eine robuste Umsetzung der `append_string`-Funktion sowie die
notwendige Initialisierung.

### 1. Die `append_string` Hilfsfunktion

Diese Funktion kümmert sich darum, dass der Speicher für dein `Document`
automatisch mitwächst, während du die Datei einliest.

```c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void append_string(char **destination, const char *source) {
    if (source == NULL) return;

    if (*destination == NULL) {
        // Erster Aufruf: Speicher reservieren und kopieren
        *destination = malloc(strlen(source) + 1);
        if (*destination) {
            strcpy(*destination, source);
        }
    } else {
        // Folgende Aufrufe: Speicher erweitern
        size_t new_size = strlen(*destination) + strlen(source) + 1;
        char *temp = realloc(*destination, new_size);
        if (temp) {
            *destination = temp;
            strcat(*destination, source);
        }
    }
}
```

### 2. Integration in das Gesamtprogramm

Wichtig ist, dass du die Pointer in deiner `Document`-Struktur zu Beginn auf
`NULL` setzt. In C enthalten uninitialisierte Pointer sonst zufällige
Speicheradressen, was bei `realloc` oder der `NULL`-Prüfung zum Absturz führt.

```c
int main() {
    // 1. Dokument initialisieren (WICHTIG: Alles auf NULL)
    Document doc = {NULL, NULL, NULL, NULL, NULL, NULL, NULL};

    // 2. Parser aufrufen
    // In der parse_file Funktion würde jetzt stehen:
    // append_string(&doc.content, line);

    // 3. Beispielhafter Test
    append_string(&doc.content, "In einem rechtwinkligen Dreieck...\n");
    append_string(&doc.content, "$$a^2 + b^2 = c^2$$\n");

    if (doc.content) {
        printf("Gespeicherter Inhalt:\n%s", doc.content);
    }

    // 4. Speicher am Ende wieder freigeben
    free(doc.key);
    free(doc.title);
    free(doc.content);
    free(doc.proof);
    // ... etc für alle Felder

    return 0;
}
```

---

## 4. LaTeX-Exporter Spezifikation
Der Exporter soll aus der SQLite-Datenbank ein kompilierbares LaTeX-Dokument generieren.

| Feature | Anforderung |
| :--- | :--- |
| **Input** | Suchbegriffe (Keywords) via CLI-Argumente, optional `--type <kategorie>` |
| **Query** | `SELECT * FROM entries WHERE (type = ?) AND (key REGEXP ? AND content REGEXP ? ...)` |
| **Output** | Eine `.tex` Datei mit passendem Header (`amsmath`, `amsfonts`, etc.) |
| **Formatierung** | Transformation von Markdown-Elementen (z.B. `#` zu `\section`) und direktes Einbetten von LaTeX-Formeln |

### LaTeX-Template Struktur
Jeder Eintrag aus der Datenbank wird in eine LaTeX-Umgebung gemappt:
```latex
\section*{Titel des Eintrags}
\textbf{Typ:} Kategorie \\
\textbf{Tags:} tag1, tag2

\subsection*{Satz/Inhalt}
[content]

\subsection*{Beweis}
[proof]
```

---

## 5. Erweiterte Exporter-Funktionen

Der Exporter (`src/exporter.c`) wurde um intelligente Funktionen zur Erstellung wissenschaftlicher Dokumente erweitert.

### CLI-Optionen & Steuerung
| Option | Beschreibung |
| :--- | :--- |
| `--refs` | **Dependency-Resolution**: Scannt die `refs`-Spalte der Treffer und bindet alle referenzierten Einträge automatisch mit ein (Tiefe 1). |
| `--type [Kategorie]` | Filtert den Export auf einen bestimmten Typ (z.B. `satz`, `def`). |
| `[Keywords]` | Alle weiteren Argumente werden als reguläre Ausdrücke (Regex) gegen alle Spalten (`key`, `title`, `tags`, `content`, `proof`) geprüft. |

### LaTeX-Layout & Pakete
* **Listen-Management**: Nutzt das Paket `enumitem`. 
  * Globale Konfiguration: `\setlist[enumerate]{leftmargin=2.5cm, itemsep=2pt}`.
  * Unterstützt explizite Labels in den `.md`-Dateien: `\begin{enumerate}[label=(A \arabic*)]`.
* **Formatierung**: Einfache Markdown-Fettmarkierung (`**text**`) wird automatisch in `\textbf{text}` umgewandelt.
* **Theorem-Mapping**: Der `type` aus der Datenbank bestimmt die LaTeX-Umgebung (`axiom`, `satz`, `definition`, `lemma`, `bemerkung`). Unbekannte Typen fallen auf `theorem` zurück.

### Sortierhierarchie (Logische Ordnung)
Um ein konsistentes mathematisches Dokument zu erzeugen, werden alle Einträge (inkl. Abhängigkeiten) nach einer festen Rangfolge sortiert:
1. **Axiome** (`axiom`): Das Fundament.
2. **Definitionen** (`definition`, `def`): Begriffliche Grundlagen.
3. **Sätze & Theoreme** (`satz`, `theorem`, `lemma`): Abgeleitete Resultate.
4. **Bemerkungen & Sonstiges**: Ergänzende Informationen.
Innerhalb jeder Gruppe erfolgt eine alphabetische Sortierung nach dem `title`.

### Einmal-Prinzip (Deduplikation)
Durch eine interne `KeyList` (C-Struktur) wird sichergestellt, dass jeder Eintrag – auch wenn er von mehreren anderen Sätzen referenziert wird – exakt **einmal** im exportierten Dokument erscheint.

