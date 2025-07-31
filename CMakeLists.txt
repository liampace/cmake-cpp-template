cmake_minimum_required(VERSION 3.31)

project("mylibrary" LANGUAGES C CXX)
set(PROJECT_VERSION_MAJOR 1)
set(PROJECT_VERSION_MINOR 0)
set(PROJECT_VERSION_PATCH 0)
set(PROJECT_VERSION "${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}.${PROJECT_VERSION_PATCH}")
set(PROJECT_DESCRIPTION "A simple CMake library.")
set_property(GLOBAL PROPERTY USE_FOLDERS ON)

string(COMPARE EQUAL "${CMAKE_CURRENT_SOURCE_DIR}" "${CMAKE_SOURCE_DIR}" MYLIBRARY_STANDALONE)

option(BUILD_SHARED_LIBS "Build shared libraries" ON)
option(MYLIBRARY_BUILD_EXAMPLES "Build the ${PROJECT_NAME} example programs" ${MYLIBRARY_STANDALONE})
option(MYLIBRARY_BUILD_TESTS "Build the ${PROJECT_NAME} test programs" ${MYLIBRARY_STANDALONE})
option(MYLIBRARY_BUILD_DOCS "Build the ${PROJECT_NAME} HTML documentation." ON)
option(MYLIBRARY_INSTALL "Generate the ${PROJECT_NAME} installation target" ON)
list(APPEND CMAKE_MODULE_PATH "${CMAKE_CURRENT_SOURCE_DIR}/cmake/modules")

if (${BUILD_SHARED_LIBS})
    add_library(${PROJECT_NAME} SHARED)
else ()
    add_library(${PROJECT_NAME} STATIC)
    target_compile_definitions(${PROJECT_NAME} PUBLIC "MYLIBRARY_STATIC_DEFINE")
endif ()

add_subdirectory("include")
add_subdirectory("src")
target_compile_features(${PROJECT_NAME} PUBLIC cxx_std_17)
target_compile_options(${PROJECT_NAME} PUBLIC ${MYLIBRARY_CXX_FLAGS})
set_target_properties(${PROJECT_NAME} PROPERTIES CXX_STANDARD_REQUIRED ON)
if (${CMAKE_BUILD_TYPE} STREQUAL "Debug")
    target_compile_options(${PROJECT_NAME} PRIVATE ${MYLIBRARY_CXX_WARNING_FLAGS})
    set_target_properties(${PROJECT_NAME} PROPERTIES
            COMPILE_WARNING_AS_ERROR ON
            LINK_WARNING_AS_ERROR ON
            CXX_EXTENSIONS OFF)
endif ()

if (MYLIBRARY_BUILD_EXAMPLES)
    add_subdirectory("examples")
endif ()

if (MYLIBRARY_BUILD_TESTS)
    include(CTest)
    enable_testing()
    add_subdirectory("tests")
endif ()

if (MYLIBRARY_BUILD_DOCS)
    add_subdirectory("docs")
endif ()

if (MYLIBRARY_INSTALL)
    add_subdirectory("cmake")
endif ()