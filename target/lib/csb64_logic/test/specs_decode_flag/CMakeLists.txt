set(SUITE_NAME ${BINARY_NAME}_specs_decode_flag)

add_library(${SUITE_NAME} OBJECT
    specs_decode_flag.cpp
)

target_link_libraries(${SUITE_NAME} PRIVATE ${BINARY_NAME} Boost::unit_test_framework)

setupFlags(${SUITE_NAME})
