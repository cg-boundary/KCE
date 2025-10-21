#pragma once
#include <string>

#include <glm/glm.hpp>
#include <glad/glad.h>


namespace Kenzo::Draw {

    class Shader {
    public:
        unsigned int ID;
        Shader();
        bool setup(const std::string &vertSource, const std::string &fragSource);
        void use() const;
        void setBool(const std::string &name, bool value) const;
        void setInt(const std::string &name, int value) const;
        void setFloat(const std::string &name, float value) const;
        void setVec3(const std::string &name, const glm::vec3& value) const;
        void setMat4(const std::string &name, const glm::mat4& mat) const;

    private:
        static bool checkCompileErrors(GLuint shader, std::string type);
    };

} // Namespace - KenzoCG
