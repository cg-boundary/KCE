
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
        # External
        glad
        glfw
        imgui
        pybind11::module
        # Internal
        draw
)

# C++ Version
target_compile_features(window
    PRIVATE
        cxx_std_20
)
