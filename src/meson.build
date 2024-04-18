testapplication_sources = [
  'main.c',
  'testapplication-application.c',
  'testapplication-window.c',
]

testapplication_deps = [
  dependency('gtk4'),
  dependency('libadwaita-1', version: '>= 1.4'),
]

testapplication_sources += gnome.compile_resources('testapplication-resources',
  'testapplication.gresource.xml',
  c_name: 'testapplication'
)

executable('testapplication', testapplication_sources,
  dependencies: testapplication_deps,
       install: true,
)
