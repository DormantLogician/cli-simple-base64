# CLI Simple Base 64 Encoder/Decoder (CSB64) Beta

## Important notice
This is considered beta software - this means that it is NOT ready for production use until this notice is removed.

## Using this project
Please see LICENSE.txt file before using any part of this project in your own project(s).

## Description
CLI Simple Base 64 (or csb64) is a command line interface that uses a basic, cross-platform implementation of the base 64 specification - it includes both an encoder and decoder for base 64.

## Build instructions
Compiling this project has been tested with the Clang C++ compiler (clang++) on Linux only - compilation with other C++ compilers and/or on other operating systems might require modifying the steps below - please refer to the manpage and/or official documentation for CMake before doing this for best results. Please follow steps below if you wish build this project in the standard way (on Linux using Make).

1. Install CMake - this is used to build the project.
2. Open a command line.
3. Navigate to project's 'built' directory.
4. Type the following command (without the apostrophies) into the command line you opened in order to configure project: 'cmake -D CMAKE_CXX_COMPILER=clang++ -D CMAKE_BUILD_TYPE=Release -D BUILD_TESTING=OFF -G "Unix Makefiles" ..' (don't forget the two dots '..' at end).
5. In same command line opened earlier, type the following command (without the apostrophies) 'make' to build binaries.
