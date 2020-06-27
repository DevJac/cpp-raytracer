CCFLAGS = [
    '-pedantic',
    '-Werror',
    '-Wall',
    '-Wextra',
    '-Wconversion',
    '-Wdouble-promotion',
    '-Wformat=2',
    '-Wformat-overflow',
    '-Wformat-truncation',
    '-Wshadow',
    '-Wundef',
    '-fno-common',
    '-fstack-protector-all',
    '-g3',
    '-Og']

VariantDir('build', 'src', duplicate=0)
env = Environment(CCFLAGS=' '.join(CCFLAGS))
env.Program('build/main.cpp')
