#pragma once
#include <iostream>
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <pybind11/pybind11.h>
namespace py = pybind11;

#include "renderer.hpp"


namespace KenzoCG {

    class Window {
    public:
        Window(int width, int height, const char* title,
               py::function on_update,
               py::function on_draw_3d,
               py::function on_draw_2d);
        ~Window();

        void run();
        void close();
        void update();
        void draw_3d();
        void draw_2d();

        GLFWwindow* window = nullptr;
        std::unique_ptr<KenzoCG::Renderer> renderer;
        int width;
        int height;
        const char* title;
        py::function on_update;
        py::function on_draw_3d;
        py::function on_draw_2d;
        float prev_time;
        float delta_time;
    };

} // Namespace - KenzoCG
