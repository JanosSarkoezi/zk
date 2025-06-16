project('llm-wiki-parser', 'c',
  version : '0.1',
  default_options : ['warning_level=3'])

sqlite3_dep = dependency('sqlite3')

sources = [
  'src/main.c',
  'src/import.c',
  'src/database.c'
]

executable('importer',
           sources,
           dependencies : sqlite3_dep,
           install : true)

executable('exporter',
           'src/exporter.c',
           dependencies : sqlite3_dep,
           install : true)
