
#define PY_SSIZE_T_CLEAN

#include <Python.h>
#include <string.h>
#include "../artifacts/build/libgloop.h"


#define RETURN_NONE Py_INCREF(Py_None) ; return Py_None
PyObject* GetPyNone() {
    Py_INCREF(Py_None);
    return Py_None;
}

PyObject* unpackb;


static PyObject* gloop_goLoop(PyObject* self, PyObject* args) { 
    char* result = GoLoop();
    PyObject* py_result = result==NULL ? GetPyNone() : PyUnicode_FromString(result);
    free(result);
    return py_result;
}

static PyMethodDef Methods[] = {
    {"goLoop", gloop_goLoop, METH_VARARGS, "goLoop"},
    {NULL, NULL, 0, NULL}
};

static struct PyModuleDef gloop_module = {
    PyModuleDef_HEAD_INIT,
    "gloop",
    NULL,
    -1,
    Methods
};
PyMODINIT_FUNC PyInit_gloop(void) {
    PyObject* msgpack = PyImport_ImportModule("msgpack");
    if (msgpack == NULL) {
       PyErr_SetString(PyExc_ImportError, "msgpack module not found");
        return NULL;
    }
    unpackb = PyObject_GetAttrString(msgpack, "unpackb");

    return PyModule_Create(&gloop_module);
}
