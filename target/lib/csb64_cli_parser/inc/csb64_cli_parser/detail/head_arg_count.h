#ifndef CSB64_CLI_PARSER_F_HEAD_ARG_COUNT_H
#define CSB64_CLI_PARSER_F_HEAD_ARG_COUNT_H

#include <string>
#include <vector>
#include <functional>

namespace csb64_cli_parser::detail
{
    /*
     * Returns how many arguments are at the beginning of command line input
     * before the first command is found.
     * 
     * @param user_args Input to command line (mirrors 'argv' array).
     * @param cmd_classifier Identifies a command so function can stop.
     */
    long long head_arg_count(const std::vector<std::string>& user_args,
                             const std::function<bool(const std::string& id)>& cmd_classifier);
};

#endif
