#include <stdexcept>
#include <iostream>

#include "window.hpp"


namespace KenzoCG {
    // Callbacks
    void resize(GLFWwindow* window, int w, int h) {
        glViewport(0, 0, w, h);
    }

    // Init
    Window::Window(int width, int height, const char* title) {
        // Props
        this->width = width;
        this->height = height;
        this->title = title;
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
        this->window = glfwCreateWindow(this->width, this->height, this->title, nullptr, nullptr);
        if (!this->window) {
            throw std::runtime_error("Failed to create GLFW window");
        }
        // Context
        glfwMakeContextCurrent(this->window);
        // Resize
        glfwSetFramebufferSizeCallback(this->window, resize);
        // GLAD
        if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
            throw std::runtime_error("Failed to initialize GLAD");
        }
    }

    // Destroy
    Window::~Window(void) {
        close();
    }

    // Run
    void Window::run(void) {
        while (!glfwWindowShouldClose(this->window)){
            // Update
            update();
            // Clear
            glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
            glClear(GL_COLOR_BUFFER_BIT);
            // 3D
            draw_3d();
            // 2D
            draw_2d();
            // Swap
            glfwSwapBuffers(this->window);
            // Events
            glfwPollEvents();
        }
    }

    // Shutdown
    void Window::close(void) {
        if (this->window) {
            glfwSetWindowShouldClose(this->window, true);
            glfwDestroyWindow(this->window);
        }
        glfwTerminate();
    }

    // Update
    void Window::update(void) {
        // Escape
        if (glfwGetKey(this->window, GLFW_KEY_ESCAPE) == GLFW_PRESS) {
            close();
        }
    }

    // Draw 3D
    void Window::draw_3d(void) {
    }

    // Draw 2D
    void Window::draw_2d(void) {
    }
}
