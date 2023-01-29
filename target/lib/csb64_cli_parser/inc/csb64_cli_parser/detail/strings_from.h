#ifndef CSB64_CLI_PARSER_F_ARGS_FROM_H
#define CSB64_CLI_PARSER_F_ARGS_FROM_H

#include <functional>
#include <string>
#include <vector>

namespace csb64_cli_parser::detail
{
    std::vector<std::string> strings_from(const std::vector<std::string>::const_iterator& begin,
                                          const std::vector<std::string>::const_iterator& end,
                                          const std::function<bool(const std::string&)>& stopper);
};

#endif
