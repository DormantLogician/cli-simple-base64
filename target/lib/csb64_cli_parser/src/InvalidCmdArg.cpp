#include <exception>

#include "csb64_cli_parser/InvalidCmdArg.h"

namespace csb64_cli_parser
{
    const char* InvalidCmdArg::what() const noexcept
    {
        return "csb64: Invalid arguments or number of arguments supplied to program.\n";
    };
};
