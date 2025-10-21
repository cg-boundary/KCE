
# Lib
add_library(window
    STATIC
        ${CMAKE_CURRENT_SOURCE_DIR}/source/window.cpp
)

# Includes
target_include_directories(window
    PUBLIC
        "${CMAKE_CURRENT_SOURCE_DIR}/include"
)

# Links
target_link_libraries(window
    PUBLIC
        glad
        glfw
)
