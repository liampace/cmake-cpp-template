cmake_minimum_required(VERSION 3.31)
project("mylibrary" LANGUAGES C CXX)
set(PROJECT_VERSION_MAJOR 1)
set(PROJECT_VERSION_MINOR 0)
set(PROJECT_VERSION_PATCH 0)
set(PROJECT_VERSION "${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}.${PROJECT_VERSION_PATCH}")
set(PROJECT_DESCRIPTION "A simple CMake library.")
set_property(GLOBAL PROPERTY USE_FOLDERS ON)

add_library(${PROJECT_NAME} STATIC)
# Add source files
file(GLOB_RECURSE source_files CONFIGURE_DEPENDS
        # Find platform independent code
        "src/${PROJECT_NAME}/*.c"
        "src/${PROJECT_NAME}/*.cpp"
        # Find platform dependent code
        "src/${CMAKE_SYSTEM_NAME}/*.c"
        "src/${CMAKE_SYSTEM_NAME}/*.cpp")
target_sources(${PROJECT_NAME} PRIVATE ${source_files})

# Add header files
file(GLOB_RECURSE header_files CONFIGURE_DEPENDS
        "include/${PROJECT_NAME}/*.h"
        "include/${PROJECT_NAME}/*.hpp")
target_sources(${PROJECT_NAME} PUBLIC
        FILE_SET ${PROJECT_NAME}_headers
        TYPE HEADERS
        FILES ${header_files})
target_include_directories(${PROJECT_NAME} PUBLIC "include")
target_compile_features(${PROJECT_NAME} PRIVATE cxx_std_17)