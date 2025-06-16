# LLM-Wiki: Parser-Source-Management

Ein strukturiertes Wissenssystem zur Vorbereitung und Verwaltung von Inhalten, die automatisiert durch einen **C-Parser** in eine **SQLite-Datenbank** überführt werden.

## Zweck

Dieses Wiki generiert und verwaltet Markdown-Dateien in einem strikten Format. Diese Dateien dienen als Eingabe für einen Parser in C. Gemini stellt sicher, dass die Syntax (YAML-Header und Trenner) jederzeit valide bleibt, damit der Parser die Daten korrekt in SQL-Tabellen mappen kann.

## Ordnerstruktur

```
raw/          -- Unverarbeitete Notizen und Quellen
wiki/         -- Parser-konforme Markdown-Dateien
wiki/index.md -- Register aller Keys und Verlinkungen
wiki/specs.md -- Technische Definition der C-Strukturen und SQL-Schemas
```

## Dokumenten-Spezifikation (Strikt)

Jede Datei in `wiki/` muss zwingend folgendem Aufbau entsprechen, um vom C-Parser erkannt zu werden:

```markdown
---
key: [eindeutiger_schluessel]
title: [Titel des Eintrags]
type: [Kategorie, z.B. satz, def, info]
tags: [tag1, tag2]
refs: [key1, key2]
---
[Inhalt: Der Satz oder die Beschreibung]

--proof--
[Beweis-Teil oder detaillierte technische Ausführung]
```

## Ingest-Workflow

Wenn neue Informationen in den `raw/`-Ordner gelegt werden:

1. **Analyse**: Extrahiere die Kernaussage (den "Satz") und den Beweis/Beleg.
2. **Key-Vergabe**: Erzeuge einen eindeutigen `key` (kleingeschrieben, Unterstriche), der in SQLite als Primärschlüssel dient.
3. **Erstellung**: Erzeuge die Datei in `wiki/`. Achte darauf, dass der YAML-Block keine Syntaxfehler enthält.
4. **Verlinkung**: Trage den neuen `key` in die `wiki/index.md` ein und prüfe, ob `refs` zu anderen Dateien existieren.
5. **Log**: Protokolliere die Erstellung in `wiki/log.md`.

## C-Parser & SQLite Mapping

Das Wiki pflegt in `wiki/specs.md` die technische Vorlage für das C-Programm:

| MD-Feld | C-Struktur Typ | SQLite Spalte |
| :--- | :--- | :--- |
| `key` | `char[64]` | `id (PRIMARY KEY)` |
| `title` | `char[255]` | `title` |
| `type` | `enum / char[32]` | `category` |
| `Content` | `char* (heap)` | `body_text` |
| `--proof--` | `char* (heap)` | `proof_text` |

## Validierung (Linting)

Beim Audit des Wikis prüft Gemini:
* **Parser-Kompatibilität**: Sind die Trenner `---` und `--proof--` korrekt gesetzt?
* **SQL-Integrität**: Sind alle `key`-Werte im gesamten Wiki einzigartig?
* **Broken Refs**: Zeigen alle Einträge unter `refs` auf existierende Dateien?
* **Typ-Check**: Entsprechen die `type`-Felder den definierten Kategorien in der `specs.md`?

## Regeln

- **Keine Format-Experimente**: Verändere niemals die Struktur des Headers, da dies den C-Parser zerstören würde.
- **Dateinamen**: Müssen exakt dem `key` entsprechen (z.B. `satz_pythagoras.md`).
- **Atomarität**: Pro Datei nur ein Satz/Konzept.
- **Speicher-Hinweis**: Lange Texte im Beweis-Teil müssen so formatiert sein, dass der C-Parser sie als zusammenhängenden Block (Buffer) einlesen kann.
