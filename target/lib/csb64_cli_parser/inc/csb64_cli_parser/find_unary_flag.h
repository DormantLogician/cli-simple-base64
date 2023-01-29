#ifndef CSB64_CLI_PARSER_F_FIND_UNARY_FLAG_H
#define CSB64_CLI_PARSER_F_FIND_UNARY_FLAG_H

#include <string>
#include <vector>
#include <functional>

namespace csb64_cli_parser
{
    std::optional<std::string> find_unary_flag(const std::vector<std::string>& user_args,
                                               const std::function<bool(const std::string& id)>& classifier);
};

#endif
