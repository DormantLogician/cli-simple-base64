set(BINARY_NAME csb64_logic)
set(MODULE_NAME all_${BINARY_NAME}_specs)

makeTest(${MODULE_NAME} main.cpp)

target_sources(${MODULE_NAME} PRIVATE
    specs_decode_flag.cpp
    specs_disable_newline_flag.cpp
    specs_err_code.cpp
    specs_format_flag.cpp
    specs_help_flag.cpp
    specs_help_info_message.cpp
    run_csb64/specs_run_csb64.cpp
    run_csb64/src/test_run_csb64.cpp
    run_csb64/inc/specs_run_csb64/test_run_csb64.h
)

target_include_directories(${MODULE_NAME} PRIVATE
    run_csb64/inc
)

get_property(SB64_DLL TARGET sb64::sb64 PROPERTY IMPORTED_LOCATION_RELEASE)
file(COPY ${SB64_DLL} DESTINATION ${CMAKE_CURRENT_BINARY_DIR})

target_link_libraries(${MODULE_NAME} PRIVATE ${BINARY_NAME} Boost::unit_test_framework)
