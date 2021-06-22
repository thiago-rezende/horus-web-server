project('asio',
  ['cpp'],
  version: 'head',
  license: 'BSL-1.0',
  default_options: [
      'cpp_std=c++17'
  ])

asio_inc = include_directories([
    'asio/include'
])

asio_dep = declare_dependency(
    include_directories: asio_inc
)
