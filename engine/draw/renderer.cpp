#include <string>

#include "files.hpp"
#include "renderer.hpp"


namespace KenzoCG {

    Renderer::Renderer(): shader(nullptr) {
    }

    Renderer::~Renderer() {
        delete shader;
        shader = nullptr;
    }

    bool Renderer::setup() {
        shader = new Shader();
        std::string vertSource = KenzoCG::get_file_content("vert.glsl");
        std::string fragSource = KenzoCG::get_file_content("frag.glsl");
        if (shader->setup(vertSource, fragSource)){
            return true;
        }
        return false;
    }

} // Namespace - KenzoCG