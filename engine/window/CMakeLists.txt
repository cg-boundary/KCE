
# Lib
add_library(window
    STATIC
        ${CMAKE_CURRENT_SOURCE_DIR}/window.cpp
)

# Includes
target_include_directories(window
    PUBLIC
        "${CMAKE_CURRENT_SOURCE_DIR}/"
)

# Links
target_link_libraries(window
    PUBLIC
        pybind11::module
        glad
        glfw
)
