#include <string>

namespace csb64_cli_parser::detail
{
    bool begins_with_dash(const std::string& input)
    {
        return input.empty() ? false : (input[0] == '-');
    };
};
