## CLI Simple Base 64 Encoder/Decoder (CSB64) Beta

### Important notice

This is considered beta software - this means that it is NOT ready for production use until this notice is removed.

### Using this project

Please see LICENSE.txt file before using any part of this project in your own project(s).

### Description

CLI Simple Base 64 (or csb64) is a command line interface that uses a basic, cross-platform implementation of a base 64 encoder and decoder.

### Build instructions

Compiling this project has been tested with the GCC C++ compiler (g++) on Linux only - compilation with other C++ compilers and/or on other operating systems might require modifying the steps below - please refer to the manpage and/or official documentation for CMake before doing this for best results. Please follow steps below if you wish build this project in the standard way (on Linux using Ninja).

1. Install CMake, Conan, and Ninja, (used to build project).
2. Open a command line in root project directory.
3. To build, test, and package project, run (without apostrophies) 'cmake -P util/task/package.cmake' (this will create an installable '.deb' file under the build directory).