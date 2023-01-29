#include <string>

namespace csb64_logic::constant
{
    std::string help_info_message()
    {
        return std::string{"Usage: csb64 [OPTION]...\n"} +
                           "Encode or decode Base64 - uses standard input and output.\n" +
                           "\n" +
                           "Available options (default mode is encode):\n" +
                           "  -d         Set mode to decode - incompatible with help mode.\n" +
                           "  -h         Displays this help dialog - incompatible with all other options.\n" +
                           "  -w COLS    Sets number of characters to write before adding linebreaks\n" +
                           "             to output (default is 72). Set COLS to zero to disable linebreaks.\n" +
                           "             For encode mode only.\n" +
                           "  -n         Disable trailing newline in output - for encode mode only.\n";
    };
};
