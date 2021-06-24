server_src = [
    'src/main.cpp',
    'src/logger.cpp',
    'src/connection.cpp',
    'src/connection_manager.cpp',
    'src/server.cpp'
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
