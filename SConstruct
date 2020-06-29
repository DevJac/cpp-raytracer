CCFLAGS = [flag.strip() for flag in open('compile_flags.txt').readlines()]
VariantDir('build', 'src', duplicate=0)
env = Environment(CXX='clang++',
                  CCFLAGS=' '.join(CCFLAGS))
env.Program('build/main.cpp')
