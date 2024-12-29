#include <string>
#include <vector>

namespace specs_find_all
{
    std::vector<std::string> values_of(const std::vector<std::vector<std::string>::const_iterator>& list)
    {
        std::vector<std::string> output{};
        for (auto iter{list.cbegin()}; iter < list.cend(); ++iter)
        {
            output.push_back(**iter);
        };

        return output;
    };
};
