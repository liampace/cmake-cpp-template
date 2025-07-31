# cmake-cpp-template
A C++ project template using CMake

## Requirements
1. Ninja
2. CMake
3. Doxygen

## Getting Started
1. Create a new project using this template by:
    1. Cloning this repository
    2. Clicking the "Use this template" button
2. Replace the default `LICENCE` and `README.md` files.
3. Rename `mylibraryConfig.cmake.in` to `<project-name>Config.cmake.in` 
4. Within the `CMakePresets.json` file
   1. Replace all instances of `MYLIBRARY_*` with `<PROJECT-NAME>_*`
5. Within the various `CMakeLists.txt` files
    1. Change the default project name (`mylibrary`) to the name of your project
    2. Change the default `CPACK_PACKAGE_VENDOR` to your/your organization's name
    3. Replace all instances of `MYLIBRARY_*` to `<PROJECT-NAME>_*`
6. Start coding