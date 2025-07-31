file(GLOB_RECURSE source_files CONFIGURE_DEPENDS
        # Find platform independent code
        "${PROJECT_NAME}/*.c"
        "${PROJECT_NAME}/*.cpp"
        # Find platform dependent code
        "${CMAKE_SYSTEM_NAME}/*.c"
        "${CMAKE_SYSTEM_NAME}/*.cpp")
target_sources(${PROJECT_NAME} PRIVATE ${source_files})