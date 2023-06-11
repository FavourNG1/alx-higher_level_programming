#!/usr/bin/python3
#include <Python.h>

void print_python_list_info(PyObject* p) {
    Py_ssize_t size = PyList_Size(p);
    PyObject* repr = PyObject_Repr(p);
    const char* repr_str = PyUnicode_AsUTF8(repr);
    Py_DECREF(repr);

    printf("[*] Size of the Python List = %ld\n", size);
    printf("[*] Allocated = %ld\n", ((PyListObject*)p)->allocated);
    printf("[*] Element 0: %s\n", repr_str);

    Py_ssize_t i;
    for (i = 0; i < size; i++) {
        PyObject* item = PyList_GetItem(p, i);
        const char* item_type = Py_TYPE(item)->tp_name;
        printf("Element %ld: %s\n", i + 1, item_type);
    }
}
