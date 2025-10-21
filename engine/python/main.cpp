#include <pybind11/pybind11.h>
namespace py = pybind11;

#include "window.hpp"

PYBIND11_MODULE(KCE, m) {
    m.doc() = "KenzoCG Engine";

    py::class_<KenzoCG::Window, py::smart_holder>(m, "Window")
        .def(py::init<int, int, const char*>())
        .def("running", &KenzoCG::Window::running)
        .def("update", &KenzoCG::Window::update);
}
