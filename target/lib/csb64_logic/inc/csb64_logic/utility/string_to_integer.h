#ifndef CSB64_LOGIC_F_STRING_TO_INTEGER_H
#define CSB64_LOGIC_F_STRING_TO_INTEGER_H

#include <string>
#include <optional>

namespace csb64_logic::utility
{
    std::optional<long long> string_to_integer(const std::string& str);
};

#endif
