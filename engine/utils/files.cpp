
#include "files.hpp"

#include <string>
#include <filesystem>
#include <fstream>
#include <sstream>
#include <stdexcept>

#ifdef _WIN32
#include <windows.h>
#elif defined(__linux__)
#include <unistd.h>
#elif defined(__APPLE__)
#include <mach-o/dyld.h>
#else
#error "Unsupported operating system"
#endif

namespace KenzoCG {

    std::filesystem::path getBinaryDirectory() {
        std::filesystem::path exePath;

    #ifdef _WIN32
        // Windows: Use GetModuleFileNameW to get the executable path
        wchar_t path[MAX_PATH];
        DWORD size = GetModuleFileNameW(NULL, path, MAX_PATH);
        if (size == 0 || size == MAX_PATH) {
            throw std::runtime_error("Failed to get executable path");
        }
        exePath = std::filesystem::path(path);
    #elif defined(__linux__)
        // Linux: Read the symbolic link /proc/self/exe
        char path[PATH_MAX];
        ssize_t count = readlink("/proc/self/exe", path, PATH_MAX);
        if (count == -1 || count >= PATH_MAX) {
            throw std::runtime_error("Failed to get executable path");
        }
        path[count] = '\0'; // Null-terminate the string
        exePath = std::filesystem::path(path);
    #elif defined(__APPLE__)
        // macOS: Use _NSGetExecutablePath
        char path[PATH_MAX];
        uint32_t size = PATH_MAX;
        if (_NSGetExecutablePath(path, &size) != 0) {
            throw std::runtime_error("Failed to get executable path");
        }
        exePath = std::filesystem::path(path);
    #endif

        // Return the parent directory of the executable path
        return exePath.parent_path();
    }

    std::filesystem::path getResourcesDirectory() {
        std::filesystem::path resourcesDir = getBinaryDirectory() / "resources";
        return resourcesDir.make_preferred();
    }

    std::filesystem::path getShadersDirectory() {
        std::filesystem::path resourcesDir = getBinaryDirectory() / "resources" / "shaders";
        return resourcesDir.make_preferred();
    }

    std::string getFileContent(const std::string& filePath) {
        // Normalize the file path for the current OS
        std::filesystem::path normalizedPath = std::filesystem::path(filePath).make_preferred();
        
        // Check if file exists
        if (!std::filesystem::exists(normalizedPath)) {
            throw std::runtime_error("File does not exist: " + normalizedPath.string());
        }
        
        // Check if path is a regular file
        if (!std::filesystem::is_regular_file(normalizedPath)) {
            throw std::runtime_error("Path is not a regular file: " + normalizedPath.string());
        }
        
        // Open the file
        std::ifstream file(normalizedPath, std::ios::binary);
        if (!file.is_open()) {
            throw std::runtime_error("Failed to open file: " + normalizedPath.string());
        }
        
        // Read file contents into string
        std::stringstream buffer;
        buffer << file.rdbuf();
        
        // Check for read errors
        if (file.fail()) {
            file.close();
            throw std::runtime_error("Error reading file: " + normalizedPath.string());
        }
        
        file.close();
        return buffer.str();
    }

    std::string getShaderContent(const std::string& fileName) {
        std::filesystem::path shaderDirectory = getShadersDirectory();
        std::string filePath = (shaderDirectory / fileName).make_preferred().string();
        return getFileContent(filePath);
    }

} // Namespace - KenzoCG