function(target_copy_dlls target)
    if (NOT CMAKE_IMPORT_LIBRARY_SUFFIX)
        return()
    endif ()
    add_custom_command(
            TARGET ${target} POST_BUILD
            COMMAND ${CMAKE_COMMAND} -E copy $<TARGET_RUNTIME_DLLS:${target}> $<TARGET_FILE_DIR:${target}>
            COMMAND_EXPAND_LISTS)
endfunction()