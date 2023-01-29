set(BINARY_NAME csb64)

add_executable(${BINARY_NAME}
    main.cpp
)

target_link_libraries(${BINARY_NAME} PRIVATE csb64_logic)

setupFlags(${BINARY_NAME})
target_include_directories(${BINARY_NAME} PRIVATE inc)
