borealis_sources = [
  'main.c',
  'borealis-application.c',
  'borealis-window.c',
]

borealis_deps = [
  dependency('gtk4'),
  dependency('libadwaita-1', version: '>= 1.2'),
]

blueprints = custom_target('blueprints',
  input: files(
    'gtk/help-overlay.blp',
    'borealis-window.blp',
  ),
  output: '.',
  command: [find_program('blueprint-compiler'), 'batch-compile', '@OUTPUT@', '@CURRENT_SOURCE_DIR@', '@INPUT@'],
)


borealis_sources += gnome.compile_resources('borealis-resources',
  'borealis.gresource.xml',
  dependencies: blueprints,
  c_name: 'borealis'
)

executable('borealis', borealis_sources,
  dependencies: borealis_deps,
       install: true,
)
