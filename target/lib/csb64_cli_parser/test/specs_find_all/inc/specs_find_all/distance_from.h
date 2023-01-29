#ifndef SPECS_FIND_ALL_F_DISTANCE_FROM_BEGIN_H
#define SPECS_FIND_ALL_F_DISTANCE_FROM_BEGIN_H

#include <string>
#include <vector>

namespace specs_find_all
{
    long long distance_from(const std::vector<std::string>::const_iterator& begin,
                            const std::vector<std::string>::const_iterator& end);
};

#endif
