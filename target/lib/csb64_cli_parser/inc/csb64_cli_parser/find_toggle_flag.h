#ifndef CSB64_CLI_PARSER_F_FIND_TOGGLE_FLAG_H
#define CSB64_CLI_PARSER_F_FIND_TOGGLE_FLAG_H

#include <string>
#include <vector>
#include <functional>

namespace csb64_cli_parser
{
    /*
     * Finds a command line flag that has no arguments within command line
     * arguments supplied by user. Returns true if the flag exists - false
     * otherwise.
     * 
     * @param user_args Input to command line (mirrors 'argv' array).
     * @param classifier Represents the flag we are searching for - it usually
     * classifies something that begins with a dash '-' followed by a letter.
     * @exception InvalidCmdArg - Throws if multiple instances of the toggle flag
     * exist in command line arguments, or the toggle flag has more than zero
     * arguments.
     */
    bool find_toggle_flag(const std::vector<std::string>& user_args,
                          const std::function<bool(const std::string& id)>& classifier);
};

#endif
