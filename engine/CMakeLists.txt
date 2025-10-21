# Window Static
add_subdirectory(window)

# Python Module
add_subdirectory(python)

# Ensure KCE Dependencies
add_dependencies(KCE window)