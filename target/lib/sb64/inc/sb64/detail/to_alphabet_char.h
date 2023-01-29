#ifndef SB64_F_TO_ALPHABET_CHAR_H
#define SB64_F_TO_ALPHABET_CHAR_H

#include <optional>

namespace sb64::detail 
{
    std::optional<unsigned char> to_alphabet_char(const long long index);
};

#endif
