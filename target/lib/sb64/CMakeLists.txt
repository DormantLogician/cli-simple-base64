set(BINARY_NAME sb64)

add_library(${BINARY_NAME}

    src/detail/to_alphabet_char.cpp
    src/detail/to_original_char.cpp
    src/decode_b64.cpp
    src/is_valid_b64.cpp
    src/Letter.cpp
    src/to_b64.cpp
)

setupFlags(${BINARY_NAME})
target_include_directories(${BINARY_NAME} PUBLIC inc)

