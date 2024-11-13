set(BINARY_NAME csb64_cli_parser)
set(MODULE_NAME all_${BINARY_NAME}_specs)

makeTest(${MODULE_NAME} ${MODULE_NAME}.cpp)
setupFlags(${MODULE_NAME})

add_subdirectory(specs_any_classifiers_match)
add_subdirectory(specs_begins_with_dash)
add_subdirectory(specs_find_all)
add_subdirectory(specs_find_toggle_flag)
add_subdirectory(specs_id_classifier)
add_subdirectory(specs_find_unary_flag)
add_subdirectory(specs_head_arg_count)
add_subdirectory(specs_InvalidCmdArg)
add_subdirectory(specs_satisfies)
add_subdirectory(specs_strings_from)

target_link_libraries(${MODULE_NAME} PRIVATE ${BINARY_NAME}
    ${BINARY_NAME}_specs_any_classifiers_match
    ${BINARY_NAME}_specs_begins_with_dash
    ${BINARY_NAME}_specs_find_all
    ${BINARY_NAME}_specs_find_toggle_flag
    ${BINARY_NAME}_specs_id_classifier
    ${BINARY_NAME}_specs_find_unary_flag
    ${BINARY_NAME}_specs_head_arg_count
    ${BINARY_NAME}_specs_InvalidCmdArg
    ${BINARY_NAME}_specs_satisfies
    ${BINARY_NAME}_specs_strings_from
)


