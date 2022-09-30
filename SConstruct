#!python
from SCons.Script import *
from scripts.build_util import validate_modules, module_converter

# Setup Default Environment
env = DefaultEnvironment()
env.Tool('clang')

# Supported Platforms
platforms = 'windows,osx'.split(',')

# PathVariables validators
PathExists = PathVariable.PathExists
PathAccept = PathVariable.PathAccept

# Build Variables
variables = Variables([], ARGUMENTS)
variables.Add(
	EnumVariable('target', 'Target Compilation', 'debug', ['debug', 'release'], {'d': 'debug', 'r': 'release'}))
variables.Add(ListVariable('platforms', 'Target Platforms', 'windows', platforms))
variables.Add(EnumVariable('bits', 'Target Bits', '64', ['32', '64']))
variables.Add(PathVariable('godot_bindings_path', 'Godot binding base path', '../godot-cpp', PathExists))
variables.Add(PathVariable('libraries_path', 'GDNative libraries base path', './modules', PathExists))
variables.Add(PathVariable('libraries_export_path', 'GDNative libraries export path', 'assets/libs', PathAccept))
variables.Add('libraries', 'List of libraries - names must match cpp filename in modules folder', '',
	validate_modules, module_converter)
variables.Update(env)

# Internal variables
target = env['target']
platforms = env['platforms']
bits = env['bits']
godot_bindings_path = env['godot_bindings_path']
libraries = env['libraries']
libraries_export_path = env['libraries_export_path']