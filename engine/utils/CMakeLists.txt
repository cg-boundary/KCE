
# Lib
add_library(utils
    STATIC
        ${CMAKE_CURRENT_SOURCE_DIR}/files.cpp
)

# Includes
target_include_directories(utils
    PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}/
)

# C++ Version
target_compile_features(utils
    PRIVATE
        cxx_std_20
)
