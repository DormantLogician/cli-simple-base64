find_program(CLANG_TIDY_EXE NAMES "clang-tidy" DOC "Path to clang-tidy static analysis tool.")
if (NOT CLANG_TIDY_EXE)
    message(WARNING 
        "Clang-tidy executable not found on system - linting will not be available."
    )
else()
    set(CMAKE_CXX_CLANG_TIDY ${CLANG_TIDY_EXE} -p ${CMAKE_CURRENT_BINARY_DIR}/compile_commands.json)
endif()

# For generating manpages.
find_program(PANDOC_EXE NAMES "pandoc" DOC "Path to Pandoc document converter tool.")

if (CMAKE_HOST_SYSTEM_NAME STREQUAL "Windows")
    find_program(7ZIP_EXE NAMES "7z" DOC "Path to 7Zip archive manager.")
else()
    find_program(GZIP_EXE NAMES "gzip" DOC "Path to GZip archiving tool.")
endif()
