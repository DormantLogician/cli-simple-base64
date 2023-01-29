#ifndef SB64_F_IS_VALID_B64_H
#define SB64_F_IS_VALID_B64_H

#include <vector>
#include <functional>
#include <optional>
#include "sb64/detail/Letter.h"

namespace sb64
{
    bool is_valid_b64(const std::function<std::optional<unsigned char>()>& reader);
};

#endif
