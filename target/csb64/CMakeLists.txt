set(BINARY_NAME csb64)

add_executable(${BINARY_NAME}
    main.cpp
)

markdownToManpage(${BINARY_NAME}.1 doc/man/${BINARY_NAME}.1.md)

install(TARGETS ${BINARY_NAME} RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR})
install(FILES ${CMAKE_BINARY_DIR}/${BINARY_NAME}.1.gz DESTINATION man/man1)

if (${CMAKE_HOST_SYSTEM_NAME} MATCHES "Windows")
    get_property(SB64_DLL TARGET sb64::sb64 PROPERTY IMPORTED_LOCATION_RELEASE)
    install(FILES ${SB64_DLL} DESTINATION ${CMAKE_INSTALL_BINDIR})
endif()

target_link_libraries(${BINARY_NAME} PRIVATE csb64_logic)

target_include_directories(${BINARY_NAME} PRIVATE inc)
