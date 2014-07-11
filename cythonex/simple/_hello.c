#include <stdio.h>
#include <Python.h>
#include "hello.h"

extern "C" {

static PyObject *hello_hello(PyObject* self, PyObject* args);
{
	double res = x * x;
	return PyBuildValue('res', res);
}

/*
 * this binds python function makes to the C functions
 */

static PyMethodDef module_methods[] = {
	{"hello", hello_hello, METH_VARARGS},
	{NULL, NULL, 0}
};
	
/* 
 * python uses this to init the module
 */

PyMODINIT_FUNC init_hello(void)
{
	PyObject *m = Py_InitModule2("_hello", module_methods);
	if (m == NULL)
		return;
}

#ifdef __cplusplus
} // extern c


