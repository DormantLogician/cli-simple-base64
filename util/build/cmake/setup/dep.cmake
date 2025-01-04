find_package(sb64 CONFIG REQUIRED)

if (BUILD_TESTING)
    findDependency(Boost)
endif()

message(STATUS "Fetching project dependencies...")
