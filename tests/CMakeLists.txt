include(CopyDLLs)
include(FetchGoogleTest)

file(GLOB_RECURSE test_files CONFIGURE_DEPENDS "*.cpp")
add_executable(${PROJECT_NAME}_tests ${test_files})
target_link_libraries(${PROJECT_NAME}_tests PRIVATE ${PROJECT_NAME} GTest::gtest GTest::gtest_main)
target_copy_dlls(${PROJECT_NAME}_tests)
gtest_discover_tests(${PROJECT_NAME}_tests)