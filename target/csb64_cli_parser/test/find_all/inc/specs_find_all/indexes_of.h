#ifndef SPECS_FIND_ALL_F_INDEXES_OF_H
#define SPECS_FIND_ALL_F_INDEXES_OF_H

#include <string>
#include <vector>

namespace specs_find_all
{
    std::vector<long long> indexes_of(const std::vector<std::string>::const_iterator& begin,
                                      const std::vector<std::vector<std::string>::const_iterator>& positions);
};

#endif
