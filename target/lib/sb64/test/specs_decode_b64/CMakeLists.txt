set(SUITE_NAME ${BINARY_NAME}_specs_decode_b64)

add_library(${SUITE_NAME} OBJECT
    specs_decode_b64.cpp
)

target_sources(${SUITE_NAME} PRIVATE
    src/decode_to_uchars.cpp
)

target_link_libraries(${SUITE_NAME} PRIVATE ${BINARY_NAME} Boost::unit_test_framework)
target_include_directories(${SUITE_NAME} PRIVATE inc)

setupFlags(${SUITE_NAME})
