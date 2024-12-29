set(BINARY_NAME csb64_cli_parser)
set(MODULE_NAME all_${BINARY_NAME}_specs)

makeTest(${MODULE_NAME} main.cpp)

target_sources(${MODULE_NAME} PRIVATE
    specs_any_classifiers_match.cpp
    specs_begins_with_dash.cpp
    find_all/specs_find_all.cpp
    find_all/src/distance_from.cpp
    find_all/src/indexes_of.cpp
    find_all/src/values_of.cpp
    find_all/inc/specs_find_all/distance_from.h
    find_all/inc/specs_find_all/indexes_of.h
    find_all/inc/specs_find_all/values_of.h
    specs_find_toggle_flag.cpp
    specs_id_classifier.cpp
    specs_find_unary_flag.cpp
    specs_head_arg_count.cpp
    specs_InvalidCmdArg.cpp
    specs_satisfies.cpp
    specs_strings_from.cpp
)

target_include_directories(${MODULE_NAME} PRIVATE
    find_all/inc
)

target_link_libraries(${MODULE_NAME} PRIVATE ${BINARY_NAME} Boost::unit_test_framework)
