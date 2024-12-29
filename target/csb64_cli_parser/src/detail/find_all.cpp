#include <functional>
#include <string>
#include <vector>

#include "csb64_cli_parser/detail/find_all.h"

namespace csb64_cli_parser::detail
{
    std::vector<std::vector<std::string>::const_iterator> find_all(const std::vector<std::string>::const_iterator& begin,
                                                                   const std::vector<std::string>::const_iterator& end,
                                                                   const std::function<bool(const std::string& id)>& classifier)
    {
        std::vector<std::vector<std::string>::const_iterator> output{};

        for (auto iter{begin}; iter < end; ++iter)
        {
            if (classifier(*iter))
            {
                output.push_back(iter);
            };
        };

        return output;
    };
};
