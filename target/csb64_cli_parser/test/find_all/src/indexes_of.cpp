#include <string>
#include <vector>

#include "specs_find_all/distance_from.h"

namespace specs_find_all
{
    std::vector<long long> indexes_of(const std::vector<std::string>::const_iterator& begin,
                                      const std::vector<std::vector<std::string>::const_iterator>& positions)
    {
        std::vector<long long> output{};
        for (auto iter{positions.cbegin()}; iter < positions.cend(); ++iter)
        {
            output.push_back(distance_from(begin, *iter));
        };

        return output;
    };
};
