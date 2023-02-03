#ifndef CSB64_CLI_PARSER_F_ANY_CLASSIFIERS_MATCH_H
#define CSB64_CLI_PARSER_F_ANY_CLASSIFIERS_MATCH_H

#include <string>
#include <vector>
#include <functional>

namespace csb64_cli_parser::detail
{
    /*
     * True if any of the specified classifers return true when executed on the
     * input string.
     * @param input String to check.
     * @param classifiers List of classifiers to check string against.
     */
    bool any_classifiers_match(const std::string& input,
                               const std::vector<std::function<bool(const std::string& id)>>& classifiers);
};

#endif
