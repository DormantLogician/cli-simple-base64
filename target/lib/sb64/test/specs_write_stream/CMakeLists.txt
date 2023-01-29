set(SUITE_NAME ${BINARY_NAME}_specs_write_stream)

add_library(${SUITE_NAME} OBJECT
    specs_write_stream.cpp
)

target_sources(${SUITE_NAME} PRIVATE
    src/TestFixture.cpp
)

target_link_libraries(${SUITE_NAME} PRIVATE ${BINARY_NAME} Boost::unit_test_framework)
target_include_directories(${SUITE_NAME} PRIVATE inc)

setupFlags(${SUITE_NAME})
