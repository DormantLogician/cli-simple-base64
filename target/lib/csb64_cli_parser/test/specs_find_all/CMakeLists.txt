set(SUITE_NAME ${BINARY_NAME}_specs_find_all)

add_library(${SUITE_NAME} OBJECT
    specs_find_all.cpp
)

target_sources(${SUITE_NAME} PRIVATE
    src/distance_from.cpp
    src/indexes_of.cpp
    src/values_of.cpp
)

target_link_libraries(${SUITE_NAME} PRIVATE ${BINARY_NAME} Boost::unit_test_framework)
target_include_directories(${SUITE_NAME} PRIVATE inc)

setupFlags(${SUITE_NAME})
