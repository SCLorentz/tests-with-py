#include <Python.h>

extern void write_asm(int fd, const void *buf, size_t count);

static PyObject* write_msg(PyObject* self, PyObject* args)
{
    const char *string;
    if (!PyArg_ParseTuple(args, "s", &string))
    {
        return NULL;
    }

    write_asm(1, string, strlen(string));

    Py_RETURN_NONE;
}

static PyMethodDef MyModulesMethods[] =
{
    {"write_msg", write_msg, METH_VARARGS, "printa uma mensagem"},
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
    return PyModule_Create(&my_asm);
}