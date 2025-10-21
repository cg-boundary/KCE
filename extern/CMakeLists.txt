
# GLAD - Static Lib
add_subdirectory(glad)

# GLFW - Static Lib
set(USE_MSVC_RUNTIME_LIBRARY_DLL OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_EXAMPLES OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_TESTS OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_DOCS OFF CACHE BOOL "" FORCE)
set(GLFW_INSTALL OFF CACHE BOOL "" FORCE)
add_subdirectory(glfw)

# PyBind11 - Header Only
add_subdirectory(pybind11)
