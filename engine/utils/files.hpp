#pragma once
#include <string>
#include <filesystem>
#include <fstream>
#include <sstream>
#include <stdexcept>


namespace KenzoCG {

    std::filesystem::path get_binary_directory(void);
    std::filesystem::path get_resources_directory(void);
    std::filesystem::path get_shaders_directory(void);
    std::string get_file_content(const std::string& filePath);
    std::string get_shader_content(const std::string& fileName);

} // Namespace - KenzoCG