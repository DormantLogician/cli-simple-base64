#include <string>
#include <regex>
#include <optional>
#include <stdexcept>

namespace csb64_logic::utility
{
    std::optional<long long> string_to_integer(const std::string& str)
    {
        const std::regex is_integer{"0|(-?[1-9][0-9]*)"};
        if (!std::regex_match(str, is_integer))
        {
            return std::nullopt;
        };

        try
        {
            return std::stoll(str);
        }
        catch (const std::out_of_range& err)
        {
            return std::nullopt;
        };
    };
};
