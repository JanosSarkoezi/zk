# Wiki Navigation (ohne Plugins)

Anleitung zur Navigation zwischen Wiki-Seiten mittels `[[link]]` ohne externe Plugins wie Vimwiki.

## 1. Lua-Lösung für `[[link]]`
Füge diesen Code in deine NeoVim-Konfiguration ein. Er sucht nach dem Text zwischen `[[` und `]]` und öffnet die entsprechende `.md`-Datei im `wiki/`-Ordner.

```lua
local function follow_wiki_link()
  local line = vim.api.nvim_get_current_line()
  local col = vim.api.nvim_win_get_cursor(0)[2] + 1

  -- Suche nach dem Muster [[...]] um den Cursor herum
  local start_pos = line:find("%[%[", 1)
  while start_pos and start_pos <= col do
    local end_pos = line:find("%]%]", start_pos)
    if end_pos and end_pos >= col then
      local link = line:sub(start_pos + 2, end_pos - 1)
      
      -- Pfad-Logik: Prüfen ob im Hauptverzeichnis oder wiki-Ordner
      local path = "wiki/" .. link .. ".md"
      if vim.fn.filereadable(path) == 0 then
        path = link .. ".md"
      end

      if vim.fn.filereadable(path) == 1 then
        vim.cmd("edit " .. path)
      else
        print("Datei nicht gefunden: " .. path)
      end
      return
    end
    start_pos = line:find("%[%[", end_pos + 1)
  end
  print("Kein Wiki-Link unter dem Cursor.")
end

-- Keymap setzen (gn = Go to Note)
vim.keymap.set("n", "gn", follow_wiki_link, { desc = "Wiki-Link folgen" })
```

## 2. Alternative: Natives `gf` anpassen
Man kann auch das native `gf` ("Go to File") nutzen, indem man den Suchpfad und die Dateiendungen erweitert. Das ist jedoch bei `[[link]]` weniger präzise als die Lua-Lösung.

```lua
vim.opt.path:append("wiki")
vim.opt.suffixesadd:append(".md")
-- Hinweis: Damit gf die Klammern ignoriert, müsste isfname angepasst werden, 
-- was andere Funktionen stören könnte. Die Lua-Lösung oben wird daher empfohlen.
```

---
Quelle: [[lua-konfiguration-suche]] | Stand: 2026-04-16
