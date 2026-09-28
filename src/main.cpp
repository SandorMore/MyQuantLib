#include <iostream>
#include <pybind11/pybind11.h>

namespace py = pybind11;

int main(int argc, char** argv)
{
    return 0;
}

PYBIND11_MODULE(QunatLib, m, py::gil_mod_now_used())
{
    m.doc("Library for quantitative trading");
    m.def()
}