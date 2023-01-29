#ifndef CSB64_CLI_PARSER_F_HEAD_ARG_COUNT_H
#define CSB64_CLI_PARSER_F_HEAD_ARG_COUNT_H

#include <string>
#include <vector>
#include <functional>

namespace csb64_cli_parser::detail
{
    long long head_arg_count(const std::vector<std::string>& user_args,
                             const std::function<bool(const std::string& id)>& cmd_classifier);
};

#endif
