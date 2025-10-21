
# Lib
add_library(draw
    STATIC
        ${CMAKE_CURRENT_SOURCE_DIR}/shader.cpp
)

# Includes
target_include_directories(draw
    PUBLIC
        "${CMAKE_CURRENT_SOURCE_DIR}/"
)

# Links
target_link_libraries(draw
    PUBLIC
        pybind11::module
        glad
)
