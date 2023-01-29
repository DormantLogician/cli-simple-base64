#ifndef SB64_F_TO_ORIGINAL_CHAR_H
#define SB64_F_TO_ORIGINAL_CHAR_H

#include <optional>

namespace sb64::detail
{
    std::optional<unsigned char> to_original_char(const unsigned long long character);
};

#endif
