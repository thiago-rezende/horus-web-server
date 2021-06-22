project('MesonStarterProject',
  ['cpp'],
  version: '2.1.0',
  license: 'MIT',
  default_options: [
      'cpp_std=c++17',
      'default_library=static'
  ])

fmt_proj = subproject('fmt')
fmt_dep = dependency('fmt', required: true, fallback: ['fmt', 'fmt_dep'])

subdir('application')

summary({'bindir': get_option('bindir'),
         'libdir': get_option('libdir'),
         'datadir': get_option('datadir'),
         'includedir': get_option('includedir'),
         'localedir': get_option('localedir'),
         'localstatedir': get_option('localstatedir'),
         'mandir': get_option('mandir'),
         'sysconfdir': get_option('sysconfdir'),
         'prefix': get_option('prefix'),
        }, section: 'Directories')
