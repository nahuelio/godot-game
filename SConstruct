#!python
import os, subprocess

opts = Variables([], ARGUMENTS)
env = DefaultEnvironment()

# Our Options
opts.Add(EnumVariable('target', 'Compilation Target', 'debug', ['d', 'debug', 'r', 'release']))
opts.Add(EnumVariable('platform', "Compilation Platform", '', ['', 'windows', 'osx']))
opts.Add(EnumVariable('p', "Compilation target, alias for 'platform'", '', ['', 'windows', 'osx']))
opts.Add(BoolVariable('use_llvm', "Use the LLVM / Clang compiler", 'no'))
opts.Add(PathVariable('target_path', 'The path where the lib is installed.', 'assets/libs/'))
opts.Add(PathVariable('target_name', 'The library name.', 'libs', PathVariable.PathAccept))

# Dependencies
godot_headers_path = "../godot-cpp/godot-headers/"
cpp_bindings_path = "../godot-cpp/"
cpp_library = "libgodot-cpp"

# TODO: Continue working here to improve local development experience
# 1) Compile GDNative modules
# 2) Launch godot in debugging mode
# 3) Unit tests

# Support 64
bits = 64

opts.Update(env)

if env['use_llvm']:
	env['CC'] = 'clang'
	env['CXX'] = 'clang++'

if env['p'] != '':
	env['platform'] = env['p']

if env['platform'] == '':
	print("No valid target platform selected.")
	quit()

# Check our platform specifics

# OSX
if env['platform'] == "osx":
	env['target_path'] += 'osx/'
	cpp_library += '.osx'
	if env['target'] in ('debug', 'd'):
		env.Append(CCFLAGS = ['-g','-O2', '-arch', 'x86_64', '-std=c++17'])
		env.Append(LINKFLAGS = ['-arch', 'x86_64'])
	else:
		env.Append(CCFLAGS = ['-g','-O3', '-arch', 'x86_64', '-std=c++17'])
		env.Append(LINKFLAGS = ['-arch', 'x86_64'])
# linux
elif env['platform'] in ('x11', 'linux'):
	env['target_path'] += 'x11/'
	cpp_library += '.linux'
	if env['target'] in ('debug', 'd'):
		env.Append(CCFLAGS = ['-fPIC', '-g3','-Og', '-std=c++17'])
	else:
		env.Append(CCFLAGS = ['-fPIC', '-g','-O3', '-std=c++17'])
# Windows
elif env['platform'] == "windows":
	env['target_path'] += 'win64/'
	cpp_library += '.windows'
	# This makes sure to keep the session environment variables on windows,
	# that way you can run scons in a vs 2017 prompt and it will find all the required tools
	env.Append(ENV = os.environ)
	env.Append(CCFLAGS = ['-DWIN32', '-D_WIN32', '-D_WINDOWS', '-W3', '-GR', '-D_CRT_SECURE_NO_WARNINGS'])
	if env['target'] in ('debug', 'd'):
		env.Append(CCFLAGS = ['-EHsc', '-D_DEBUG', '-MDd'])
	else:
		env.Append(CCFLAGS = ['-O2', '-EHsc', '-DNDEBUG', '-MD'])

if env['target'] in ('debug', 'd'):
	cpp_library += '.debug'
else:
	cpp_library += '.release'

cpp_library += '.' + str(bits)

# File Output
# godot.<platform>.[opt].[release|release_debug|debug].<architecture>[extension]

# make sure our binding library is properly includes
env.Append(CPPPATH=['.', godot_headers_path, cpp_bindings_path + 'include/', cpp_bindings_path + 'include/core/', cpp_bindings_path + 'include/gen/'])
env.Append(LIBPATH=[cpp_bindings_path + 'bin/'])
env.Append(LIBS=[cpp_library])

# tweak this if you want to use different folders, or more folders, to store your source code in.
env.Append(CPPPATH=['src/'])
sources = Glob('src/*.cpp')

library = env.SharedLibrary(target=env['target_path'] + env['target_name'] , source=sources)

Default(library)

# Generates help for the -h scons option.
Help(opts.GenerateHelpText(env))