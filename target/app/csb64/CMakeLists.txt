set(BINARY_NAME csb64)

add_executable(${BINARY_NAME}
    main.cpp
)

install(TARGETS ${BINARY_NAME} RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR})
install(FILES doc/man/csb64.1.gz DESTINATION ${CMAKE_INSTALL_MANDIR}/man1)

target_link_libraries(${BINARY_NAME} PRIVATE csb64_logic)

setupFlags(${BINARY_NAME})
target_include_directories(${BINARY_NAME} PRIVATE inc)
