#include <string>
#include <functional>

#include "csb64_cli_parser/detail/head_arg_count.h"

namespace csb64_cli_parser::detail
{
    long long head_arg_count(const std::vector<std::string>& user_args,
                             const std::function<bool(const std::string& id)>& cmd_classifier)
    {
        long long count{0};
        for (auto iter{user_args.cbegin()}; iter < user_args.cend(); ++iter)
        {
            if (cmd_classifier(*iter))
            {
                break;
            };

            ++count;
        };

        return count;
    };
};
