find_program(CONAN_EXE NAMES "conan" DOC "Path to Conan package manager command line utility.")
find_program(GIT_EXE NAMES "git" DOC "Path to Git version control command line utility.")

if (NOT CONAN_EXE)
    message(SEND_ERROR
        "Conan executable not found on system - this is required to package project's dependencies and make them available to this project."
    )
endif()

if (NOT GIT_EXE)
    message(SEND_ERROR
        "Git executable not found on system - this is required to get dependencies of project."
    )
endif()

if (NOT CONAN_EXE OR NOT GIT_EXE)
    message(FATAL_ERROR
        "Not all programs required to run script are available on system - please check which programs are missing above."
    )
endif()

message(STATUS Making local Conan dependencies available to project...)

execute_process(COMMAND ${GIT_EXE} clone https://github.com/DormantLogician/simple-base64 built/simple-base64 COMMAND_ERROR_IS_FATAL ANY)
execute_process(COMMAND ${CONAN_EXE} create built/simple-base64 COMMAND_ERROR_IS_FATAL ANY)
