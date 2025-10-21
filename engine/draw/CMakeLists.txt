
# Lib
add_library(draw
    STATIC
        ${CMAKE_CURRENT_SOURCE_DIR}/shader.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/renderer.cpp
)

# Includes
target_include_directories(draw
    PUBLIC
        "${CMAKE_CURRENT_SOURCE_DIR}/"
)

# Links
target_link_libraries(draw
    PUBLIC
        # External
        pybind11::module
        glad
        glm
        # Internal
        utils
)

# C++ Version
target_compile_features(draw
    PRIVATE
        cxx_std_20
)
