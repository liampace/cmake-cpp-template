include(FindDoxygen)
file(GLOB_RECURSE MYLIBRARY_DOCS CONFIGURE_DEPENDS "*.md")
string(REPLACE ";" "\\\n" MYLIBRARY_DOCS ${MYLIBRARY_DOCS})
set(DOXYGEN_IN "${CMAKE_CURRENT_SOURCE_DIR}/Doxyfile.in")
set(DOXYGEN_OUT "${CMAKE_CURRENT_BINARY_DIR}/Doxyfile")
configure_file(${DOXYGEN_IN} ${DOXYGEN_OUT} @ONLY)
add_custom_target(${PROJECT_NAME}_docs ALL
        COMMAND ${DOXYGEN_EXECUTABLE} ${DOXYGEN_OUT}
        WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}
        COMMENT "Build the ${PROJECT_NAME} HTML documentation."
        VERBATIM)