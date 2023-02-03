#ifndef CSB64_CLI_PARSER_F_BEGINS_WITH_DASH_H
#define CSB64_CLI_PARSER_F_BEGINS_WITH_DASH_H

#include <string>

namespace csb64_cli_parser::detail
{
    /*
     * True if the specified string begins with a dash '-'.
     *
     * @param input String to check.
     */
    bool begins_with_dash(const std::string& input);
};

#endif
