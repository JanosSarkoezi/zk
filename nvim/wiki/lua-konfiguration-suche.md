# Lua Konfiguration: Suche und Navigation

Minimalistische Lösungen für die Dateisuche und Textsuche unter Verwendung nativer Lua-Funktionen und externer Tools wie `fd` und `ripgrep`.

## 1. Dateisuche mit `fd` in Quickfix
Anstatt einer Einzelauswahl werden alle von `fd` gefundenen Dateien direkt in die **Quickfix-Liste** geladen. Das erlaubt ein schnelles Durchblättern.

```lua
local function find_files()
  local files = vim.fn.systemlist("fd --type f --strip-cwd-prefix --hidden --exclude .git")
  local qf_list = {}
  for _, file in ipairs(files) do
    table.insert(qf_list, { filename = file, lnum = 1, text = "[Datei]" })
  end
  vim.fn.setqflist(qf_list, "r")
  vim.cmd("copen")
end

vim.keymap.set("n", "<leader>ff", find_files, { desc = "Dateien in Quickfix laden" })
```

## 2. Textsuche mit Grep in Quickfix
Die native `:grep` Funktion wird so konfiguriert, dass sie `ripgrep` nutzt. Die Ergebnisse landen automatisch in der Quickfix-Liste.

```lua
-- Ripgrep als Grepprg setzen
vim.opt.grepprg = "rg --vimgrep --smart-case --follow"
vim.opt.grepformat = "%f:%l:%c:%m"

-- Komfort-Befehl: Suche ausführen und Quickfix sofort öffnen
vim.api.nvim_create_user_command("Grep", function(opts)
  vim.cmd("grep! " .. opts.args)
  vim.cmd("copen")
end, { nargs = 1 })

vim.keymap.set("n", "<leader>fs", ":Grep ", { desc = "Text suchen (Grep/Quickfix)" })
```

## 3. Schneller Projektwechsel
Einfacher Wechsel des Arbeitsverzeichnisses (`cwd`) mittels einer Liste vordefinierter Pfade.

```lua
local function switch_project()
  local projects = { "~/dev/git/myzk", "~/.config/nvim", "~/Documents" }
  vim.ui.select(projects, { prompt = "Projekt wechseln:" }, function(selected)
    if selected then
      vim.api.nvim_set_current_dir(vim.fn.expand(selected))
      print("CWD gewechselt nach: " .. selected)
    end
  end)
end

vim.keymap.set("n", "<leader>fp", switch_project, { desc = "Projekt/Verzeichnis wechseln" })
```

---
Quelle: [[navigation-und-suche]] | Stand: 2026-04-16
