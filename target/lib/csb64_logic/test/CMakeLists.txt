set(BINARY_NAME csb64_logic)
set(MODULE_NAME all_${BINARY_NAME}_specs)

makeTest(${MODULE_NAME} ${MODULE_NAME}.cpp)
setupFlags(${MODULE_NAME})

add_subdirectory(specs_decode_flag)
add_subdirectory(specs_disable_newline_flag)
add_subdirectory(specs_err_code)
add_subdirectory(specs_format_flag)
add_subdirectory(specs_help_flag)
add_subdirectory(specs_help_info_message)
add_subdirectory(specs_run_csb64)

target_link_libraries(${MODULE_NAME} PRIVATE ${BINARY_NAME}
    ${BINARY_NAME}_specs_decode_flag
    ${BINARY_NAME}_specs_disable_newline_flag
    ${BINARY_NAME}_specs_err_code
    ${BINARY_NAME}_specs_format_flag
    ${BINARY_NAME}_specs_help_flag
    ${BINARY_NAME}_specs_help_info_message
    ${BINARY_NAME}_specs_run_csb64
)


