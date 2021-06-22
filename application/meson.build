application_src = [
    'src/main.cpp'
]

application_inc = include_directories(['include'])

application_deps = [
    fmt_dep,
    spdlog_dep
]

application = executable('application',
    sources: application_src,
    dependencies: application_deps,
    include_directories: application_inc,
    install: true)
