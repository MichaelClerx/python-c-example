/*
 * This is a C file that can be compiled into a Python extension module.
 *
 * These files always start with the lines:
 *   #define PY_SSIZE_T_CLEAN
 *   #include <Python.h>
 *
 * The line "#include <Python.h>" loads a file called Python.h, which contains
 * all the definitions for things like "PyObject", which we'll use a lot below.
 *
 * The "#define PY_SSIZE_T_CLEAN" line is a bit of a detail: just make sure you
 * write this before the "include <Python.h>" line
 *
 * Note that these lines, which start with #, are not strictly C code: they are
 * instructions for the "C preprocessor": this is run automatically before the
 * C code is compiled. In this step, all macros get replaced by proper C code.
 *   https://en.wikipedia.org/wiki/C_preprocessor
 */
#define PY_SSIZE_T_CLEAN
#include <Python.h>


/*
 * This function can be called from Python.
 *
 * Its input arguments are two pointers to python objects, which we don't use
 * here. (PyObject is the C name for objects of Python's "object" class).
 *
 * The returned value is another pointer to a Python object.
 *
 * In this case, we ignore any input and always return 5.
 *
 */
static PyObject *
five(PyObject *self, PyObject *args)
{
    /*
     * A "PyLong" is the C name for Python's "int".
     *   https://docs.python.org/3/c-api/long.html
     * The function PyLong_FromLong(x) creates a PyLong from a C "long":
     *   https://www.gnu.org/software/gnu-c-manual/gnu-c-manual.html#Primitive-Types
     */
    return PyLong_FromLong(5);
}

/*
 * Create a "method table" describing the functions our module should have.
 *
 * Each function is described using a "PyMethodDef".
 *   https://docs.python.org/3/c-api/structures.html#c.PyMethodDef
 * The end of the list is indicated with a "sentinel": A field containing a
 * null pointer.
 */
static PyMethodDef GimmeFiveMethods[] = {
    {"five",  five, METH_VARARGS, "Returns the number 5."},
    {NULL}
};

/*
 * Create a "module definition structure", telling Python about this module.
 *
 * This is a PyModuleDef type
 *  https://docs.python.org/3/c-api/module.html#c.PyModuleDef
 */
static struct PyModuleDef gimme_five_module = {
    PyModuleDef_HEAD_INIT,
    "gimme",       /* The module name (in Python) */
    "A module with a method that returns 5", /* Module docstring. */
    -1,                 /* See the docs for this one! */
    GimmeFiveMethods    /* This module's methods. */
};

/*
 * Create a "module initialisation function".
 * This will be called by the Python interpreter when it imports this module.
 *
 * This _must_ be called PyInit_name, where "name" is the module name.
 */
PyMODINIT_FUNC
PyInit_gimme(void)
{
    return PyModule_Create(&gimme_five_module);
}

