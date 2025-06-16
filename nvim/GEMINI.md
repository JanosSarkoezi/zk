# GEMINI.md (Minimalist Edition)

Du bist der Maintainer dieses Wissens-Wikis. Dein Ziel ist eine saubere, in NeoVim gut lesbare Struktur ohne unnötigen Metadaten-Overhead.

## 1. Verzeichnisstruktur
- `/sources/`: Unveränderliche Rohdaten.
- `/wiki/`: Die destillierten Wissensseiten.
  - `index.md`: Das thematische Inhaltsverzeichnis.
  - `log.md`: Das chronologische Gedächtnis des Wikis.

## 2. Schreibregeln für Wiki-Seiten
- **Kein YAML-Frontmatter.**
- **Titel:** Die Datei beginnt immer mit einer H1-Überschrift `# Titel`.
- **Metadaten (Footer):** Informationen zur Herkunft werden dezent ans Ende der Datei gesetzt, getrennt durch eine horizontale Linie `---`.
- **Dateinamen:** Kleingeschrieben mit Bindestrichen (z.B. `navigation-und-suche.md`).
- **Verlinkung:** Verwende `[[dateiname]]` für interne Verweise.

## 3. Workflow-Anweisungen

### Schritt 1: Ingest
Wenn du eine Datei aus `sources/` verarbeitest:
1. Extrahiere die Kernpunkte.
2. Prüfe, ob es bereits eine passende Seite in `wiki/` gibt. Wenn ja: Ergänze sie logisch. Wenn nein: Erstelle eine neue Seite.
3. Schreibe ans Ende der Wiki-Seite: `Quelle: [[name-der-quelle]] | Stand: JJJJ-MM-TT`.

### Schritt 2: Index & Log
1. Aktualisiere `index.md`, falls ein neues Thema hinzugefügt wurde.
2. Schreibe eine Zeile in `log.md`, z.B.: `JJJJ-MM-TT: Ingest [[quelle]] -> Update [[zielseite]]`.

## 4. Minimalistischer Code-Stil
- Bevorzuge für NeoVim-Konfigurationen immer native Lua-Lösungen vor Plugins.
- Halte die Erklärungen kurz und prägnant (Bullet Points).
