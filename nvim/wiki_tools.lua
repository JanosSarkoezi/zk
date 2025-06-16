-- NeoVim Wiki & Suche Tools (Minimalist Edition)
-- Erstellt am: 2026-04-16

local M = {}

-- 1. Dateisuche mit fd in Quickfix
function M.find_files()
  local files = vim.fn.systemlist("fd --type f --strip-cwd-prefix --hidden --exclude .git")
  local qf_list = {}
  for _, file in ipairs(files) do
    table.insert(qf_list, { filename = file, lnum = 1, text = "[Datei]" })
  end
  vim.fn.setqflist(qf_list, "r")
  vim.cmd("copen")
  print("Gefunden: " .. #files .. " Dateien")
end

-- 2. Textsuche mit Grep in Quickfix
function M.grep_search(args)
  vim.opt.grepprg = "rg --vimgrep --smart-case --follow"
  vim.opt.grepformat = "%f:%l:%c:%m"
  
  local query = args
  if not query or query == "" then
    query = vim.fn.input("Suche nach: ")
  end
  if query == "" then return end
  
  vim.cmd("grep! " .. query)
  vim.cmd("copen")
end

-- -- 3. Schneller Projektwechsel
-- function M.switch_project()
--   local projects = { "~/dev/git/myzk", "~/.config/nvim", "~/Documents" }
--   vim.ui.select(projects, { prompt = "Projekt wechseln:" }, function(selected)
--     if selected then
--       vim.api.nvim_set_current_dir(vim.fn.expand(selected))
--       print("CWD gewechselt nach: " .. selected)
--     end
--   end)
-- end

function M.switch_project()
  local projects = { "~/dev/git/myzk", "~/.config/nvim", "~/Documents" }
  
  -- 1. Buffer erstellen (scratch buffer)
  local buf = vim.api.nvim_create_buf(false, true)
  vim.api.nvim_buf_set_lines(buf, 0, -1, false, projects)

  -- 2. Fenster-Optionen (zentriert)
  local win_opts = {
    relative = "editor",
    width = 50,
    height = #projects,
    row = (vim.o.lines - #projects) / 2,
    col = (vim.o.columns - 50) / 2,
    style = "minimal",
    border = "rounded",
    title = " Projekt wechseln ",
    title_pos = "center"
  }

  -- 3. Fenster öffnen
  local win = vim.api.nvim_open_win(buf, true, win_opts)
  
  -- 4. Lokale Keymaps für dieses Fenster
  local function close() vim.api.nvim_win_close(win, true) end

  -- Bestätigen mit Enter
  vim.keymap.set("n", "<CR>", function()
    local selected = vim.api.nvim_get_current_line()
    close()
    vim.api.nvim_set_current_dir(vim.fn.expand(selected))
    print("CWD -> " .. selected)
  end, { buffer = buf, silent = true })

  -- Abbrechen mit q oder Esc
  vim.keymap.set("n", "q", close, { buffer = buf, silent = true })
  vim.keymap.set("n", "<Esc>", close, { buffer = buf, silent = true })
  
  -- Cursor auf die erste Zeile setzen
  vim.api.nvim_win_set_cursor(win, {1, 0})
end

-- 4. Wiki-Link folgen [[link]]
function M.follow_wiki_link()
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

-- Keymaps setzen
-- Setze die Leader-Taste auf Space
-- Wichtig: Dies muss definiert werden, bevor Plugins geladen werden, 
-- damit die Mappings korrekt übernommen werden.
vim.g.mapleader = " "
vim.g.maplocalleader = " "
vim.keymap.set("n", "<leader>ff", M.find_files, { desc = "Dateien suchen mit fd" })
vim.keymap.set("n", "<leader>fs", function() M.grep_search() end, { desc = "Text suchen (Grep/Quickfix)" })
vim.keymap.set("n", "<leader>fp", M.switch_project, { desc = "Projekt/Verzeichnis wechseln" })
vim.keymap.set("n", "gn", M.follow_wiki_link, { desc = "Wiki-Link folgen" })

-- Grep-Befehl registrieren
vim.api.nvim_create_user_command("Grep", function(opts)
  M.grep_search(opts.args)
end, { nargs = 1 })

-- Hilfsfunktion, um Fehler zu unterdrücken, wenn die Liste leer ist
local function qf_jump(cmd)
  return function()
    local ok = pcall(vim.cmd, cmd)
    if not ok then
      -- Optional: Ein dezenter Hinweis statt einer roten Fehlermeldung
      vim.api.nvim_echo({{"Quickfix: Ende der Liste", "WarningMsg"}}, false, {})
    end
  end
end

-- Pfeiltasten als Quickfix-Navigation (zwingt dich zu hjkl für Bewegung)
vim.keymap.set('n', '<Up>',    qf_jump('cprev'), { desc = "QF Previous" })
vim.keymap.set('n', '<Down>',  qf_jump('cnext'), { desc = "QF Next" })
vim.keymap.set('n', '<Left>',  ':cclose<CR>',    { silent = true, desc = "QF Close" })
vim.keymap.set('n', '<Right>', ':copen<CR>',     { silent = true, desc = "QF Open" })

-- F1 deaktivieren (da man sie oft aus Versehen drückt)
vim.keymap.set({ 'n', 'i' }, '<F1>', '<Nop>', { silent = true })

return M
