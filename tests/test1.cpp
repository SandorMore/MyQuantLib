#include <pybind11/pybind11.h>

namespace py = pybind11;

inline int add(int a, int b)
{
    return a + b;
}

PYBIND11_MODULE(test, m, py::mod_gil_not_used())
{
    m.doc() = "pybind11 test case 1";
    m.def("add", &add, "Add two numbers");
}
