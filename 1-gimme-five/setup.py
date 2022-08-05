#
# Python module generation script.
#
# This script uses `setuptools` to compile our C extension module.
# The `setuptools` package provides updated versions of the `distutils`
# methods.
#
#from distutils.core import setup, Extension
from setuptools import setup, Extension

#
# Define an `Extension` object, describing our C code.
#  https://docs.python.org/3/distutils/apiref.html#distutils.core.Extension
#
gimme5 = Extension('gimme', sources=['five.c'])

#
# Run the `setup` script.
#
setup(
    name='gimme',
    version='1',
    description='A very simple example module',
    ext_modules=[gimme5],
)
