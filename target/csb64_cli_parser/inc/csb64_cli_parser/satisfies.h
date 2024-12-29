#ifndef CSB64_CLI_PARSER_F_SATISFIES_H
#define CSB64_CLI_PARSER_F_SATISFIES_H

#include <string>
#include <vector>
#include <functional>

namespace csb64_cli_parser
{
    /*
     * Checks that all command line arguments supplied by user are recognized by
     * at least one classifier, and number of head arguments is one (name of the
     * program only). Please note that this function does not enforce which
     * flags are compatible with each other.
     * 
     * @param user_args Input to command line (mirrors 'argv' array).
     * @param classifiers Classifiers to check against.
     */
    bool satisfies(const std::vector<std::string>& user_args,
                   const std::vector<std::function<bool(const std::string& id)>>& classifiers);
};

#endif
