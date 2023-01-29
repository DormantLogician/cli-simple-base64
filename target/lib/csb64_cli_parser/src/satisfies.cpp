#include <string>
#include <vector>
#include <functional>

#include "csb64_cli_parser/detail/head_arg_count.h"
#include "csb64_cli_parser/detail/find_all.h"
#include "csb64_cli_parser/detail/begins_with_dash.h"
#include "csb64_cli_parser/detail/any_classifiers_match.h"
#include "csb64_cli_parser/satisfies.h"

namespace csb64_cli_parser
{
    bool satisfies(const std::vector<std::string>& user_args,
                   const std::vector<std::function<bool(const std::string& id)>>& classifiers)
    {
        const std::function<bool(const std::string&)> cmd_classifier{
            detail::begins_with_dash
        };

        const std::vector<std::vector<std::string>::const_iterator> cmds{
            detail::find_all(
                user_args.cbegin(),
                user_args.cend(),
                cmd_classifier
            )
        };

        for (auto current{cmds.cbegin()}; current < cmds.cend(); ++current)
        {
            if (!detail::any_classifiers_match(**current, classifiers))
            {
                return false;
            };
        };

        return (detail::head_arg_count(user_args, cmd_classifier) < 2);
    };
};
