#pragma once

#include <string>
#include <filesystem>
#include <fstream>
#include <sstream>
#include <stdexcept>


namespace KenzoCG {

    std::filesystem::path getBinaryDirectory(void);
    std::filesystem::path getResourcesDirectory(void);
    std::filesystem::path getShadersDirectory(void);
    std::string getFileContent(const std::string& filePath);
    std::string getShaderContent(const std::string& fileName);

} // Namespace - KenzoCG