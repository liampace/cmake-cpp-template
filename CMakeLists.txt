cmake_minimum_required(VERSION 3.31)

project("mylibrary" LANGUAGES C CXX)
set(PROJECT_VERSION_MAJOR 1)
set(PROJECT_VERSION_MINOR 0)
set(PROJECT_VERSION_PATCH 0)
set(PROJECT_VERSION "${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}.${PROJECT_VERSION_PATCH}")
set(PROJECT_DESCRIPTION "A simple CMake library.")
set_property(GLOBAL PROPERTY USE_FOLDERS ON)

# Add CMake modules to this project
list(APPEND CMAKE_MODULE_PATH "${CMAKE_CURRENT_SOURCE_DIR}/cmake/modules")

add_library(${PROJECT_NAME} SHARED)
add_subdirectory("include")
add_subdirectory("src")
target_compile_features(${PROJECT_NAME} PRIVATE cxx_std_17)

add_subdirectory("tests")

add_executable(${PROJECT_NAME}_main "main.cpp")
target_link_libraries(${PROJECT_NAME}_main PRIVATE ${PROJECT_NAME})