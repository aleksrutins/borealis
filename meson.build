project('borealis', 'cpp',
  version : '0.1',
  default_options : ['warning_level=3', 'cpp_std=c++20'])

borealis_srcs = ['main.cc']
borealis_deps = [
  dependency('gtkmm-4.0'),
  dependency('libadwaita-1')
]
subdir('src')

executable('borealis',
           borealis_srcs,
           include_directories: include_directories('src'),
           dependencies: borealis_deps,
           install : true)
