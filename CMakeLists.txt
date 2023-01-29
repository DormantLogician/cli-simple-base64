cmake_minimum_required(VERSION 3.17)

set(PROJECT_IS_ROOT CMAKE_SOURCE_DIR STREQUAL CMAKE_CURRENT_SOURCE_DIR)

# Set default to 'Release' to avoid pushing out debug builds accidentally.
if (NOT CMAKE_BUILD_TYPE)
    set(CMAKE_BUILD_TYPE Release)
endif()

# Forbid in-source builds in order to keep root project directory from being polluted with binary files.
if (${PROJECT_IS_ROOT} AND
    NOT (CMAKE_BINARY_DIR STREQUAL CMAKE_CURRENT_BINARY_DIR))
    message(FATAL_ERROR "In-source builds are prohibited, please run CMake relative to 'built' directory.")
endif()

project(SimpleBase64 LANGUAGES CXX)

set(SETUP_DIR util/build/cmake/setup) # Directory used by this CMake configuartion for includes.

include(${SETUP_DIR}/setup.cmake) # Perform general configuration related to project before continuing.
include(${SETUP_DIR}/common.cmake) # Define functions and variables that are used later.
include(${SETUP_DIR}/deps.cmake)
include(${SETUP_DIR}/linting.cmake) # Deps not included in linting because they are retrieved above.

# Add project's targets to build.
set(TARGET_DIR_NAME target)

add_subdirectory(${TARGET_DIR_NAME}/lib/sb64)
addTestDir(${TARGET_DIR_NAME}/lib/sb64/test)

add_subdirectory(${TARGET_DIR_NAME}/lib/csb64_cli_parser)
addTestDir(${TARGET_DIR_NAME}/lib/csb64_cli_parser/test)

add_subdirectory(${TARGET_DIR_NAME}/lib/csb64_logic)
addTestDir(${TARGET_DIR_NAME}/lib/csb64_logic/test)

add_subdirectory(${TARGET_DIR_NAME}/app/csb64)
