#include <string>
#include <vector>

namespace specs_find_all
{
    long long distance_from(const std::vector<std::string>::const_iterator& begin,
                            const std::vector<std::string>::const_iterator& end)
    {
        long long distance{0};
        for (auto iter{begin}; iter < end; ++iter)
        {
            ++distance;
        };

        return distance;
    };
};
