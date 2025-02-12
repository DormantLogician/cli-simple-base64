include(GNUInstallDirs) # Define common file installation paths.

set(CPACK_PACKAGE_CHECKSUM SHA256)
set(CPACK_STRIP_FILES YES) # Strip debug symbols from binary files.
set(CPACK_RESOURCE_FILE_LICENSE ${CMAKE_CURRENT_SOURCE_DIR}/LICENSE.txt)
set(CPACK_PACKAGE_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}/dist)
set(CPACK_THREADS 2)

set(CPACK_PACKAGE_CONTACT "Stephen Aaron Hannon <hannonstephen19@gmail.com>")

set(CPACK_INSTALL_DEFAULT_DIRECTORY_PERMISSIONS # Make sure directory permissions are set properly.
    OWNER_READ OWNER_WRITE OWNER_EXECUTE
    GROUP_READ GROUP_EXECUTE
    WORLD_READ WORLD_EXECUTE
)

set(CPACK_SOURCE_GENERATOR ZIP)
set(CPACK_SOURCE_IGNORE_FILES /built;/.git;/.vscode;/CMakeUserPresets.json)

set(CPACK_DEBIAN_PACKAGE_SECTION utils)
set(CPACK_DEBIAN_PACKAGE_SHLIBDEPS YES) # Make better dependency list in deb file.

set(CPACK_NSIS_EXTRA_INSTALL_COMMANDS
    "Push '$INSTDIR/bin'
    Call AddToPath"
)

set(CPACK_NSIS_EXTRA_UNINSTALL_COMMANDS
   "Push '$INSTDIR/bin'
   Call un.RemoveFromPath"
)
