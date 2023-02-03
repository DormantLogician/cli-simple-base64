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

target_link_libraries(${BINARY_NAME} PRIVATE sb64 csb64_cli_parser)

setupFlags(${BINARY_NAME})
target_include_directories(${BINARY_NAME} PUBLIC inc)
