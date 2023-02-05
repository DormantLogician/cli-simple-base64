% CSB64(1) v1
% Stephen Aaron Hannon
% February 2023

# NAME
csb64 - cross platform command line interface to base 64 encoder and decoder

# SYNOPSIS
csb64 [OPTION]...

# DESCRIPTION
Encode or decode base 64 - uses standard input and/or output.

# OPTIONS
Available options (default mode is encode):

    -d         Set mode to decode - incompatible with help mode.

    -h         Displays this help dialog - incompatible with all other options.

    -w COLS    Sets number of characters to write before adding linebreaks
               to output (default is 72). Set COLS to zero to disable linebreaks.
               For encode mode only.

    -n         Disable trailing newline in output - for encode mode only.

# COPYRIGHT
Copyright 2023 Stephen Aaron Hannon. License MIT