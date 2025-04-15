#include <Python.h>

extern void write_asm(int fd, const void *buf, size_t count);

static PyObject* write_msg(PyObject* self, PyObject* args)
{
    const char *string;
    if (!PyArg_ParseTuple(args, "s", &string)) { return NULL; }

    write_asm(1, string, strlen(string));

    Py_RETURN_NONE;
}

static PyObject* write_msg_ln(PyObject* self, PyObject* args)
{
    char *string;
    if (!PyArg_ParseTuple(args, "s", &string)) { return NULL; }

    write_asm(1, strcat(string, "\n"), strlen(string) + 1);

    Py_RETURN_NONE;
}

static PyMethodDef MyModulesMethods[] =
{
    {"write_msg", write_msg, METH_VARARGS, "printa uma mensagem"},
    {"println", write_msg_ln, METH_VARARGS, "printa uma mensagem com nova linha"},
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
    
    PyObject* custom_print_func = PyObject_GetAttrString(m, "write_msg");
    if (custom_print_func == NULL)
    {
        Py_DECREF(m);
        Py_DECREF(builtins);
        Py_DECREF(print_func);
        return NULL;
    }

    PyObject_SetAttrString(builtins, "print", custom_print_func);
    Py_DECREF(print_func);
    Py_DECREF(builtins);

    return PyModule_Create(&my_asm);
}