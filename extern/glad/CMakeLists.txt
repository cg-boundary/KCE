
# Static Lib
add_library(glad
    STATIC
        src/glad.c
)

# C++ Version
target_compile_features(glad
    PRIVATE
    cxx_std_20
)

# Includes
target_include_directories(glad
    PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}/include
)
