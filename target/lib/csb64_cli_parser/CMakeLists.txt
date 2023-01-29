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
)

setupFlags(${BINARY_NAME})
target_include_directories(${BINARY_NAME} PUBLIC inc)
