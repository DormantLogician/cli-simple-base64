cmake_minimum_required(VERSION 3.20)

project(cli-sb64
    LANGUAGES CXX
    DESCRIPTION "Command line interface for sb64 base 64 encoder/decoder."
    VERSION 1
)

set(SETUP_DIR util/build/cmake/setup) # Directory used by this CMake configuartion for includes.

include(${SETUP_DIR}/setup.cmake) # Perform general configuration related to project before continuing.
include(${SETUP_DIR}/common.cmake) # Define functions and variables that are used later.
include(${SETUP_DIR}/deps.cmake)
include(${SETUP_DIR}/linting.cmake) # Deps not included in linting because they are retrieved above.
include(${SETUP_DIR}/packing.cmake) # Configure CPack so we can package our binaries and sources.

# Add project's targets to build.
set(TARGET_DIR_NAME target)

add_subdirectory(${TARGET_DIR_NAME}/lib/sb64)
addTestDir(${TARGET_DIR_NAME}/lib/sb64/test)

add_subdirectory(${TARGET_DIR_NAME}/lib/csb64_cli_parser)
addTestDir(${TARGET_DIR_NAME}/lib/csb64_cli_parser/test)

add_subdirectory(${TARGET_DIR_NAME}/lib/csb64_logic)
addTestDir(${TARGET_DIR_NAME}/lib/csb64_logic/test)

add_subdirectory(${TARGET_DIR_NAME}/app/csb64)

install(FILES LICENSE.txt DESTINATION ${CMAKE_INSTALL_DOCDIR})

# Enable binary and source packaging targets (for certain generators).
include(CPack)
