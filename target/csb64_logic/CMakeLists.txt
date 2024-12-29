set(BINARY_NAME csb64_logic)

add_library(${BINARY_NAME}
    src/constant/decode_flag.cpp
    src/constant/disable_newline_flag.cpp
    src/constant/err_code.cpp
    src/constant/format_flag.cpp
    src/constant/help_flag.cpp
    src/constant/help_info_message.cpp
    src/run_csb64.cpp
    inc/${BINARY_NAME}/constant/decode_flag.h
    inc/${BINARY_NAME}/constant/disable_newline_flag.h
    inc/${BINARY_NAME}/constant/err_code.h
    inc/${BINARY_NAME}/constant/format_flag.h
    inc/${BINARY_NAME}/constant/help_flag.h
    inc/${BINARY_NAME}/constant/help_info_message.h
    inc/${BINARY_NAME}/run_csb64.h
)

generate_export_header(${BINARY_NAME}
    EXPORT_FILE_NAME ${BINARY_NAME}_def_exports.h
    EXPORT_MACRO_NAME ${BINARY_NAME}_EXPORT
)

configure_file(${PROJECT_SOURCE_DIR}/util/build/cmake/template/lib_export.h.in ${BINARY_NAME}_export.h)

set_target_properties(${BINARY_NAME} PROPERTIES PUBLIC_HEADER
     "inc/${BINARY_NAME}/constant/decode_flag.hinc/${BINARY_NAME}/constant/disable_newline_flag.h; \
     inc/${BINARY_NAME}/constant/err_code.h; \
     inc/${BINARY_NAME}/constant/format_flag.h; \
     inc/${BINARY_NAME}/constant/help_flag.h; \
     inc/${BINARY_NAME}/constant/help_info_message.h; \
     inc/${BINARY_NAME}/run_csb64.h; \
     ${CMAKE_CURRENT_BINARY_DIR}/${BINARY_NAME}_def_exports.h; \
     ${CMAKE_CURRENT_BINARY_DIR}/${BINARY_NAME}_export.h"
)

target_include_directories(${BINARY_NAME} PUBLIC
    $<BUILD_INTERFACE:${CMAKE_CURRENT_LIST_DIR}/inc>
    $<BUILD_INTERFACE:${CMAKE_CURRENT_BINARY_DIR}>
    $<INSTALL_INTERFACE:${CMAKE_INSTALL_INCLUDEDIR}>
)

target_link_libraries(${BINARY_NAME} PRIVATE sb64::sb64 csb64_cli_parser)

addTestDir(test)
