#pragma once
#include "shader.hpp"


namespace KenzoCG {

    class Renderer {
    public:
        Shader* shader;
        Renderer();
        ~Renderer();
        bool setup();
    };
}
