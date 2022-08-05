# First example 🙌

This example contains two files:

- `five.c`: a Python extension module, written in C
- `setup.py`: a Python script that uses `setuptools` to compile the module.

To compile, run:
```
python setup.py develop --user
```
On some systems you may need to write `python3` instead of `python`.

The command `develop` tells the script to build your extension, but not to move the built files into your main python library.
The `--user` switch tells the script that you want to install for this user only (so that you don't require admin permissions).

To test it out, load `python` and:
```
>>> import gimme
>>> dir(gimme)
['__doc__', '__file__', '__loader__', '__name__', '__package__', '__spec__', 'five']
>>> gimme.five()
5
```

