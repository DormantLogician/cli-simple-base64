#include <functional>
#include <string>
#include <vector>

namespace csb64_cli_parser::detail
{
    std::vector<std::string> strings_from(const std::vector<std::string>::const_iterator& begin,
                                          const std::vector<std::string>::const_iterator& end,
                                          const std::function<bool(const std::string&)>& stopper)
    {
        std::vector<std::string> output{};
        for (auto iter{begin}; iter < end; ++iter)
        {
            if (stopper(*iter))
            {
                break;
            };

            output.push_back(*iter);
        };

        return output;
    };
};
