set(BINARY_NAME csb64_cli_parser)

add_library(${BINARY_NAME}
    src/detail/any_classifiers_match.cpp
    src/detail/begins_with_dash.cpp
    src/detail/find_all.cpp
    src/detail/head_arg_count.cpp
    src/find_toggle_flag.cpp
    src/find_unary_flag.cpp
    src/id_classifier.cpp
    src/InvalidCmdArg.cpp
    src/satisfies.cpp
    src/detail/strings_from.cpp
    inc/${BINARY_NAME}/detail/any_classifiers_match.h
    inc/${BINARY_NAME}/detail/begins_with_dash.h
    inc/${BINARY_NAME}/detail/find_all.h
    inc/${BINARY_NAME}/detail/head_arg_count.h
    inc/${BINARY_NAME}/find_toggle_flag.h
    inc/${BINARY_NAME}/find_unary_flag.h
    inc/${BINARY_NAME}/id_classifier.h
    inc/${BINARY_NAME}/InvalidCmdArg.h
    inc/${BINARY_NAME}/satisfies.h
    inc/${BINARY_NAME}/detail/strings_from.h
)

generate_export_header(${BINARY_NAME}
    EXPORT_FILE_NAME ${BINARY_NAME}_def_exports.h
    EXPORT_MACRO_NAME ${BINARY_NAME}_EXPORT
)

configure_file(${PROJECT_SOURCE_DIR}/util/build/cmake/template/lib_export.h.in ${BINARY_NAME}_export.h)

set_target_properties(${BINARY_NAME} PROPERTIES PUBLIC_HEADER
     "inc/${BINARY_NAME}/detail/any_classifiers_match.h; \
     inc/${BINARY_NAME}/detail/begins_with_dash.h; \
     inc/${BINARY_NAME}/detail/find_all.h; \
     inc/${BINARY_NAME}/detail/head_arg_count.h; \
     inc/${BINARY_NAME}/find_toggle_flag.h; \
     inc/${BINARY_NAME}/find_unary_flag.h; \
     inc/${BINARY_NAME}/id_classifier.h; \
     inc/${BINARY_NAME}/InvalidCmdArg.h; \
     inc/${BINARY_NAME}/satisfies.h; \
     inc/${BINARY_NAME}/detail/strings_from.h; \
     ${CMAKE_CURRENT_BINARY_DIR}/${BINARY_NAME}_def_exports.h; \
     ${CMAKE_CURRENT_BINARY_DIR}/${BINARY_NAME}_export.h"
)

target_include_directories(${BINARY_NAME} PUBLIC
    $<BUILD_INTERFACE:${CMAKE_CURRENT_LIST_DIR}/inc>
    $<BUILD_INTERFACE:${CMAKE_CURRENT_BINARY_DIR}>
    $<INSTALL_INTERFACE:${CMAKE_INSTALL_INCLUDEDIR}>
)

addTestDir(test)
