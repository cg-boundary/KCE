# CMake Version
cmake_minimum_required(VERSION 3.30)

# Output
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}")
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}")
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}")

# Project
project(KENZO_ENGINE LANGUAGES CXX)

# C++ Version
set(CXX_STANDARD 20)
set(CXX_STANDARD_REQUIRED ON)

# External
add_subdirectory(extern)

# Engine
add_subdirectory(engine)

# Resources
foreach(OUTPUTCONFIG ${CMAKE_CONFIGURATION_TYPES})
    file(COPY ${CMAKE_CURRENT_SOURCE_DIR}/resources DESTINATION ${CMAKE_BINARY_DIR}/${OUTPUTCONFIG})
endforeach()
