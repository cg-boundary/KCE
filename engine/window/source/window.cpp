#include <stdexcept>
#include <iostream>
#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include "window.hpp"


namespace KenzoCG {
    // Callbacks
    void resize(GLFWwindow* window, int w, int h) {
        glViewport(0, 0, w, h);
    }

    // Init
    Window::Window(int w, int h, const char* title) {
        // GLFW
        if (!glfwInit()) {
            throw std::runtime_error("Failed to initialize GLFW");
        }
        // Profile
        glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
        glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
        glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
        #ifdef __APPLE__
        glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
        #endif
        // Window
        _window = glfwCreateWindow(w, h, title, nullptr, nullptr);
        if (!_window) {
            throw std::runtime_error("Failed to create GLFW window");
        }
        // Context
        glfwMakeContextCurrent(_window);
        // Resize
        glfwSetFramebufferSizeCallback(_window, resize);
        // GLAD
        if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
            throw std::runtime_error("Failed to initialize GLAD");
        }
    }

    // Destroy
    Window::~Window(void) {
        close();
    }

    // Opened 
    bool Window::running(void) {
        return glfwWindowShouldClose(_window);
    }

    // Update
    void Window::update(void) {
        // Events - Check
        if (_window) {
            // Key - Escape
            if (glfwGetKey(_window, GLFW_KEY_ESCAPE) == GLFW_PRESS) {
                close();
                return;
            }
        }
        // Events - Load
        glfwPollEvents();
    }

    // Buffer - Clear
    void Window::clear(void) {
        glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);
    }
    
    // Buffer - Swap
    void Window::swap(void) {
        glfwSwapBuffers(_window);
    }

    // Shutdown
    bool Window::close(void) {
        if (_window) {
            glfwSetWindowShouldClose(_window, true);
            glfwDestroyWindow(_window);
        }
        glfwTerminate();
    }

    // Draw 2D
    void Window::draw_2d(void) {
    }

    // Draw 3D
    void Window::draw_3d(void) {
    }
}
