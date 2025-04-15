#include <Python.h>

extern void write_asm(int fd, const void *buf, size_t count);

static PyObject* print(PyObject* self, PyObject* args)
{
    const char *string;
    if (!PyArg_ParseTuple(args, "s", &string)) { return NULL; }

    write_asm(1, string, strlen(string));

    Py_RETURN_NONE;
}

static PyObject* println(PyObject* self, PyObject* args)
{
    char *string;
    if (!PyArg_ParseTuple(args, "s", &string)) { return NULL; }

    write_asm(1, strcat(string, "\n"), strlen(string) + 1);

    Py_RETURN_NONE;
}

static PyMethodDef MyModulesMethods[] =
{
    {"print", print, METH_VARARGS, "prints a message"},
    {"println", println, METH_VARARGS, "prints a message and then skips to a new line"},
    {NULL, NULL, 0, NULL}
};

static struct PyModuleDef my_asm =
{
    PyModuleDef_HEAD_INIT,
    "my_asm",
    NULL,
    -1,
    MyModulesMethods
};

PyMODINIT_FUNC PyInit_my_asm(void)
{
    PyObject *m = PyModule_Create(&my_asm);

    PyObject *builtins = PyImport_ImportModule("builtins");
    if (!builtins) { Py_DECREF(m); return NULL; }

    PyObject* print_func = PyObject_GetAttrString(builtins, "print");
    if (!print_func) { Py_DECREF(m); Py_DECREF(builtins); return NULL; }
    
    PyObject_SetAttrString(builtins, "print", PyObject_GetAttrString(m, "print"));
    Py_DECREF(print_func);
    Py_DECREF(builtins);

    return PyModule_Create(&my_asm);
}