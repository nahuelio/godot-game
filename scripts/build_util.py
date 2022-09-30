#!python
import os
from functools import reduce
from SCons.Variables import PathVariable


# Modules Path Converter
def module_converter(value, env):
	bs = env['libraries_path']
	files = value.split(',')
	return list(map(lambda f: os.path.abspath(os.path.join(bs, f)) + '.cpp' if bs else f + '.cpp', files))


# Validate modules
def validate_modules(key, files, env):
	return reduce(lambda r, f: PathVariable.PathExists(key, f, env), files.split(' '), False)
