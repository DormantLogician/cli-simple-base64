set(SUITE_NAME ${BINARY_NAME}_specs_run_csb64)

add_library(${SUITE_NAME} OBJECT
    specs_run_csb64.cpp
    inc/specs_run_csb64/test_run_csb64.h
)

target_sources(${SUITE_NAME} PRIVATE
    src/test_run_csb64.cpp
)

target_link_libraries(${SUITE_NAME} PRIVATE ${BINARY_NAME} Boost::unit_test_framework)
target_include_directories(${SUITE_NAME} PRIVATE inc)

setupFlags(${SUITE_NAME})
