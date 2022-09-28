#!python
from SCons.Script import *

# Setup Default Environment
env = DefaultEnvironment()
env.Tool('clang')
# Supported Platforms
platforms = 'windows,osx'.split(',')

# Build Options
options = Variables([], ARGUMENTS)
options.Add(EnumVariable('target', 'Target Compilation', 'debug', ['debug', 'release'], {'d': 'debug', 'r': 'release'}))
options.Add(ListVariable('platforms', 'Target Platforms', 'windows', platforms))
options.Add(EnumVariable('bits', 'Target Bits', '64', ['32', '64']))
options.Add('libraries', 'List of libraries - names must match cpp filename in modules folder', '')
options.Add(PathVariable('libraries_export_path', 'GDNative Libraries path', 'assets/libs', PathVariable.PathAccept))
options.Update(env)

# Continue Working here...
print(env['target'], env['platforms'], env['bits'], env['libraries'], env['libraries_export_path'])
