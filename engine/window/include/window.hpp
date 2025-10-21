#pragma once
#include <iostream>
#include <glad/glad.h>
#include <GLFW/glfw3.h>


namespace KenzoCG {
    class Window {
        public:
            Window(int width, int height, const char* title);
            ~Window(void);
        private:
            GLFWwindow* _window = nullptr;
            bool running(void);
            void update(void);
            void clear(void);
            void swap(void);
            bool close(void);
            void draw_2d(void);
            void draw_3d(void);
    };
}
