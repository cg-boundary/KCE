#pragma once
#include <iostream>
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <pybind11/pybind11.h>
namespace py = pybind11;


namespace KenzoCG {
    class Window {
        public:
            Window(int width, int height, const char* title);
            ~Window(void);
            GLFWwindow* window = nullptr;
            int width;
            int height;
            const char* title;
            void run(void);
            void close(void);
            void update(void);
            void draw_3d(void);
            void draw_2d(void);
    };
}
