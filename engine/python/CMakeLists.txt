
# Bind
pybind11_add_module(KCE
    ${CMAKE_CURRENT_SOURCE_DIR}/main.cpp
)

# Links
target_link_libraries(KCE
    PUBLIC
        window
)
