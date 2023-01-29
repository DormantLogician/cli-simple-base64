#ifndef CSB64_CLI_PARSER_F_FIND_TOGGLE_FLAG_H
#define CSB64_CLI_PARSER_F_FIND_TOGGLE_FLAG_H

#include <string>
#include <vector>
#include <optional>
#include <functional>

namespace csb64_cli_parser
{
    bool find_toggle_flag(const std::vector<std::string>& user_args,
                          const std::function<bool(const std::string& id)>& classifier);
};

#endif
