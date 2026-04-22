project('llm-wiki-parser', 'c',
  version : '0.1',
  default_options : ['warning_level=3'])

sqlite3_dep = dependency('sqlite3')

common_sources = [
  'src/common/database.c',
  'src/common/sb_helper.c'
]

importer_sources = [
  'src/importer/main.c',
  'src/importer/import.c'
] + common_sources

exporter_sources = [
  'src/exporter/main.c',
  'src/exporter/latex.c'
] + common_sources

executable('importer',
           importer_sources,
           dependencies : sqlite3_dep,
           install : true)

executable('exporter',
           exporter_sources,
           dependencies : sqlite3_dep,
           install : true)
