function(copy_compile_commands TARGET_NAME)

    if(TARGET ${TARGET_NAME})
        add_custom_command(TARGET ${TARGET_NAME} POST_BUILD
            COMMAND ${CMAKE_COMMAND} -E copy_if_different compile_commands.json ${CMAKE_CURRENT_SOURCE_DIR}
            WORKING_DIRECTORY ${CMAKE_BINARY_DIR}
            COMMENT "Copying compile_commands.json..."
        )
    else()
        message(WARNING "Given TARGET_NAME: '${TARGET_NAME}' does not exist.")
    endif()

endfunction()

