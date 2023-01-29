#ifndef CSB64_CLI_PARSER_F_SATISFIES_H
#define CSB64_CLI_PARSER_F_SATISFIES_H

#include <string>
#include <vector>
#include <functional>

namespace csb64_cli_parser
{
    bool satisfies(const std::vector<std::string>& user_args,
                   const std::vector<std::function<bool(const std::string& id)>>& classifiers);
};

#endif
