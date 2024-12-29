function(addTestDir TEST_DIR)
    if (BUILD_TESTING)
        add_subdirectory(${TEST_DIR})
    endif()
endfunction()

# Set up a new test with a name and associated source file.
function(makeTest TEST_NAME TEST_SOURCE)
    if (BUILD_TESTING)
        add_executable(${TEST_NAME} ${TEST_SOURCE})

        add_test(
            NAME ${TEST_NAME}
            COMMAND $<TARGET_FILE:${TEST_NAME}>
        )
    endif()
endfunction()

function(findDependency TARG_NAME)
    find_package(${TARG_NAME} REQUIRED)
    include_directories(${${TARG_NAME}_INCLUDE_DIRS})
endfunction()

function(markdownToManpage MANPAGE_NAME MARKDOWN_FILE_PATH)
    execute_process(COMMAND ${PANDOC_EXE} ${MARKDOWN_FILE_PATH} -f man -o ${CMAKE_BINARY_DIR}/${MANPAGE_NAME} COMMAND_ERROR_IS_FATAL ANY WORKING_DIRECTORY ${CMAKE_CURRENT_LIST_DIR})

    if (CMAKE_HOST_SYSTEM_NAME STREQUAL "Windows")
        execute_process(COMMAND ${7ZIP_EXE} a ${CMAKE_BINARY_DIR}/${MANPAGE_NAME}.gz ${CMAKE_BINARY_DIR}/${MANPAGE_NAME} -tgzip -mx9 COMMAND_ERROR_IS_FATAL ANY)
    else()
        execute_process(COMMAND ${GZIP_EXE} -k -9 ${CMAKE_BINARY_DIR}/${MANPAGE_NAME} > ${CMAKE_BINARY_DIR}/${MANPAGE_NAME}.gz COMMAND_ERROR_IS_FATAL ANY)
    endif()
endfunction()
