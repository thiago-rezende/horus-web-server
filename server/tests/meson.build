tests_src = {
    'path': [
        'src/utils/path.cpp',
        '../src/utils/path.cpp'
    ]
}

tests_inc = include_directories('include')

foreach name, sources : tests_src
    test(name, executable(name,
        sources: sources,
        include_directories: [tests_inc, server_inc],
        install: false))
endforeach
