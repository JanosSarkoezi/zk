# NeoVim Konfigurations-Struktur

Anleitung zum Speichern und Laden von Lua-Funktionen in NeoVim.

## 1. Speicherort
Auf Linux-Systemen befindet sich die Konfiguration unter:
`~/.config/nvim/`

## 2. Empfohlene Ordnerstruktur
Für eine saubere Trennung von Logik und Einstellungen empfiehlt sich folgende Struktur:

```text
~/.config/nvim/
├── init.lua           -- Der Einstiegspunkt (wie init.vim)
└── lua/               -- Hier liegen deine eigenen Lua-Module
    ├── options.lua    -- Allgemeine Einstellungen (Set-Befehle)
    ├── keymaps.lua    -- Deine Tastenkürzel
    └── wiki_tools.lua -- Die Wiki-Funktionen (Suche, Navigation)
```

## 3. Einbinden der Module
In deiner `init.lua` kannst du die Dateien aus dem `lua/`-Ordner wie folgt laden:

```lua
-- In ~/.config/nvim/init.lua
require("options")
require("keymaps")
require("wiki_tools")
```

**Wichtig:** Beim `require`-Befehl wird der Ordner `lua/` automatisch vorausgesetzt und die Endung `.lua` weggelassen.

---
Quelle: [[wiki-navigation]] | Stand: 2026-04-16
