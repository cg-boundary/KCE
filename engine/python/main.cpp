#include <pybind11/pybind11.h>
namespace py = pybind11;

#include "window.hpp"


PYBIND11_MODULE(KCE, m) {
    m.doc() = "KenzoCG Engine";

    py::class_<KenzoCG::Window>(m, "Window")
        .def(py::init<int, int, const char*, py::function, py::function, py::function>(),
             py::arg("width"),
             py::arg("height"),
             py::arg("title"),
             py::arg("on_update") = py::none(),
             py::arg("on_draw_3d") = py::none(),
             py::arg("on_draw_2d") = py::none())
        .def("run", &KenzoCG::Window::run)
        .def("close", &KenzoCG::Window::close);

} // KCE - Python Module
