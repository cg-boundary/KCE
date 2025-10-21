#include <pybind11/pybind11.h>
namespace py = pybind11;

#include "window.hpp"


PYBIND11_MODULE(KCE, m) {
    m.doc() = "KenzoCG Engine";

    py::class_<KenzoCG::Window, py::smart_holder>(m, "Window")
        .def(py::init<int, int, const char*>())
        .def("run", &KenzoCG::Window::run)
        .def("close", &KenzoCG::Window::close)
        .def("update", &KenzoCG::Window::update)
        .def("draw_3d", &KenzoCG::Window::draw_3d)
        .def("draw_2d", &KenzoCG::Window::draw_2d);
}