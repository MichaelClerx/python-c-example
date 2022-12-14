# Python C extension example

This repository contains some very basic examples of C extension modules for Python.

Much more complete information is given here: ["Extending and Embedding the Python Interpreter"](https://docs.python.org/3/extending/index.html).

A C extension module is a little bit of C code that gets compiled and then acts like a module which you can `import` from your Python code.
To write one, follow these steps:

1. Create a C file (or a C++ file if you want to use C++).
2. Add a function that accepts and returns [pointers](https://www.gnu.org/software/gnu-c-manual/gnu-c-manual.html#Pointers) to [PyObject](https://docs.python.org/3/c-api/object.html) types (see also [here](https://docs.python.org/3/c-api/structures.html#c.PyObject)).
3. Add some [very specific bits of code](https://docs.python.org/3/extending/extending.html#the-module-s-method-table-and-initialization-function) that tell Python about your function.
4. Compile your C file [using setup.py](https://docs.python.org/3/extending/building.html#building) and the Python modules `distutils` and `setuptools`.
5. Import your module from Python, just like you would with an ordinary Python module.

## Trying it out

To see if your system is set up correctly, try [running the first example](./1-gimme-five/README.md).

## Virtual environments

Some people love using virtual environments.
If you are one, feel free!
If you are working for or being taught by one, you might like [these instructions](https://docs.python.org/3/tutorial/venv.html).

## Setting up

### On linux

Install the python development package: this will be called something like `python-dev` or `python-devel` in your package manager.

### On Windows

Install Python (the official version or anaconda).
Install [the appropriate C compiler](https://wiki.python.org/moin/WindowsCompilers), try to use a "standalone" version if you want to save space.
Make sure you have a recent version of the `setuptools` python package installed, i.e. via `pip install --upgrade setuptools`

### On macOS

Install xcode and Python.
If that doesn't work find someone who knows how to do Python on Mac. I don't!

## Stuff about C

C is older than the internet: there is no "official online C documentation" or anything like that.
There are a lot of excellent books, and some less excellent tutorials.

Don't confuse C with C++: C is much simpler than C++, which is an entirely separate language.
It's sometimes called [ANSI C](https://en.wikipedia.org/wiki/ANSI_C).

There are [several versions of the C standard](https://stackoverflow.com/questions/16403311/what-version-of-c-does-python-take).
For maximum compatibility, write in C89.
For a while this was the only option if you wanted your code to work on Windows.
Now, it seems to be OK to use newer versions like C99.
Luckily, because C is so old there isn't actually much difference between these standards.

A good free resource is [The GNU C Reference Manual](https://www.gnu.org/software/gnu-c-manual/gnu-c-manual.html), which documents "the C programming language _as implemented by the GNU Compiler Collection (GCC)_".

