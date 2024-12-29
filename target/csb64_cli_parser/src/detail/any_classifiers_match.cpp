#include <string>
#include <vector>
#include <functional>

#include "csb64_cli_parser/detail/any_classifiers_match.h"

namespace csb64_cli_parser::detail
{
    bool any_classifiers_match(const std::string& input,
                               const std::vector<std::function<bool(const std::string& id)>>& classifiers)
    {
        for (auto iter{classifiers.cbegin()}; iter < classifiers.cend(); ++iter)
        {
            const std::function<bool(const std::string&)> fn{*iter};
            if (fn(input))
            {
                return true;
            };
        };

        return false;
    };
};
