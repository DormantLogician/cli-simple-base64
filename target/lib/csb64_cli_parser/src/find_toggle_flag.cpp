#include <string>
#include <vector>
#include <functional>

#include "csb64_cli_parser/detail/find_all.h"
#include "csb64_cli_parser/detail/strings_from.h"
#include "csb64_cli_parser/detail/begins_with_dash.h"
#include "csb64_cli_parser/InvalidCmdArg.h"
#include "csb64_cli_parser/find_toggle_flag.h"

namespace csb64_cli_parser
{
    bool find_toggle_flag(const std::vector<std::string>& user_args,
                          const std::function<bool(const std::string& id)>& classifier)
    {
        const std::vector<std::vector<std::string>::const_iterator> matches{
            detail::find_all(
                user_args.cbegin(),
                user_args.cend(),
                classifier
            )
        };

        if (matches.size() > 1)
        {
            throw csb64_cli_parser::InvalidCmdArg{};
        }
        else if (matches.size() == 1)
        {
            const std::vector<std::string> args{
                detail::strings_from(
                    (matches[0] + 1),
                    user_args.cend(),
                    detail::begins_with_dash
                )
            };

            if (args.empty())
            {
                return true;
            }
            else
            {
                throw csb64_cli_parser::InvalidCmdArg{};
            };
        }
        else
        {
            return false;
        };
    };
};
