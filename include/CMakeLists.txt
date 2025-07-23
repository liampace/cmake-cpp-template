# Add import/export attributes
include(GenerateExportHeader)
generate_export_header(${PROJECT_NAME} EXPORT_FILE_NAME "${CMAKE_CURRENT_SOURCE_DIR}/${PROJECT_NAME}/export.h")

# Add header files
file(GLOB_RECURSE header_files CONFIGURE_DEPENDS
        "${PROJECT_NAME}/*.h"
        "${PROJECT_NAME}/*.hpp")
target_sources(${PROJECT_NAME} PUBLIC
        FILE_SET ${PROJECT_NAME}_headers
        TYPE HEADERS
        FILES ${header_files})
target_include_directories(${PROJECT_NAME} PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}")