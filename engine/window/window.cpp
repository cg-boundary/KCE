#include <stdexcept>
#include <iostream>
#include <memory>

#include <imgui.h>
#include <backends/imgui_impl_glfw.h>
#include <backends/imgui_impl_opengl3.h>

#include "window.hpp"


namespace KenzoCG {

    // Callbacks
    void resize(GLFWwindow* window, int w, int h) {
        glViewport(0, 0, w, h);
    }

    // Init
    Window::Window(
        int width,
        int height,
        const char* title,
        py::function on_update,
        py::function on_draw_3d,
        py::function on_draw_2d)
    {
        // Props
        this->width = width;
        this->height = height;
        this->title = title;
        this->on_update = on_update;
        this->on_draw_3d = on_draw_3d;
        this->on_draw_2d = on_draw_2d;
        this->prev_time = 0.0f;
        this->delta_time = 0.0f;
        // GLFW
        if (!glfwInit()) {
            throw std::runtime_error("Failed to initialize GLFW");
            return;
        }
        // Profile
        glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
        glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 6);
        glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
        #ifdef __APPLE__
        glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
        #endif
        // Window
        this->window = glfwCreateWindow(this->width, this->height, this->title, nullptr, nullptr);
        if (!this->window) {
            throw std::runtime_error("Failed to create GLFW window");
            return;
        }
        // Context
        glfwMakeContextCurrent(this->window);
        // Resize
        glfwSetFramebufferSizeCallback(this->window, resize);
        // GLAD
        if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
            throw std::runtime_error("Failed to initialize GLAD");
            return;
        }
        // ImGui
        IMGUI_CHECKVERSION();
        ImGui::CreateContext();
        ImGuiIO& io = ImGui::GetIO();
        io.ConfigFlags |= ImGuiConfigFlags_NavEnableKeyboard;
        io.ConfigFlags |= ImGuiConfigFlags_NavEnableGamepad;
        ImGui::StyleColorsDark();
        if (!ImGui_ImplGlfw_InitForOpenGL(this->window, true)) {
            throw std::runtime_error("Failed to initialize ImGui GLFW backend");
            return;
        }
        if (!ImGui_ImplOpenGL3_Init("#version 460")) {
            throw std::runtime_error("Failed to initialize ImGui OpenGL backend");
            return;
        }
    }

    // Destroy
    Window::~Window(void) {
        close();
    }

    // Run
    void Window::run(void) {
        // Time
        this->prev_time = glfwGetTime();
        while (!glfwWindowShouldClose(this->window)){
            // Time
            float current_time = glfwGetTime();
            this->delta_time = static_cast<float>(current_time - this->prev_time);
            this->prev_time = current_time;
            // Update
            update();
            // Start ImGui frame
            ImGui_ImplOpenGL3_NewFrame();
            ImGui_ImplGlfw_NewFrame();
            ImGui::NewFrame();
            // Example UI
            ImGui::Begin("Interface");
            ImGui::Text("Frame time: %.3f ms (%.1f FPS)", this->delta_time * 1000.0f, 1.0f / this->delta_time);
            ImGui::End();
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
        // ImGui
        ImGui_ImplOpenGL3_Shutdown();
        ImGui_ImplGlfw_Shutdown();
        ImGui::DestroyContext();
        // Window
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
        // Callback
        if (this->on_update && !this->on_update.is_none()) {
            py::gil_scoped_acquire gil;
            this->on_update();
        }
    }

    // Draw 3D
    void Window::draw_3d(void) {
        // Callback
        if (this->on_draw_3d && !this->on_draw_3d.is_none()) {
            py::gil_scoped_acquire gil;
            this->on_draw_3d();
        }
    }

    // Draw 2D
    void Window::draw_2d(void) {
        // Callback
        if (this->on_draw_2d && !this->on_draw_2d.is_none()) {
            py::gil_scoped_acquire gil;
            this->on_draw_2d();
        }
    }

} // Namespace - KenzoCG
