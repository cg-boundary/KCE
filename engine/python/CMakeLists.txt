
# Module
pybind11_add_module(KCE
    ${CMAKE_CURRENT_SOURCE_DIR}/main.cpp
)

# Links
target_link_libraries(KCE
    PRIVATE
        # Internal
        window
)

# C++ Version
target_compile_features(KCE
    PRIVATE
        cxx_std_20
)
