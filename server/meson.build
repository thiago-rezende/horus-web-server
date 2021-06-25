server_src = [
    'src/main.cpp',
    'src/logger.cpp',
    'src/server.cpp',
    'src/connection.cpp',
    'src/utils/path.cpp',
    'src/connection_manager.cpp',
    'src/http/request_parser.cpp',
    'src/http/request_handler.cpp'
]

server_inc = include_directories(['include'])

server_deps = [
    fmt_dep,
    spdlog_dep,
    asio_dep
]

server_exe = executable('server',
    sources: server_src,
    dependencies: server_deps,
    include_directories: server_inc,
    install: true)

install_subdir('share/horus-www', install_dir : get_option('datadir'))

subdir('tests')
