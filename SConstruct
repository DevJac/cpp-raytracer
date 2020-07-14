CCFLAGS = [flag.strip() for flag in open('compile_flags.txt').readlines()]
VariantDir('build', 'src', duplicate=0)
env = Environment(CXX='clang++',
                  CCFLAGS=' '.join(CCFLAGS))
env.Program('build/test.cpp', LIBS=['gtest', 'gtest_main'])
env.Program('build/main.cpp', LIBS=['gtest'])
