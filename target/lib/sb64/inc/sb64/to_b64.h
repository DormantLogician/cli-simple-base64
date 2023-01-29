#ifndef SB64_TO_B64_H
#define SB64_TO_B64_H

#include <vector>
#include <optional>
#include <functional>

namespace sb64
{
      void to_b64(const std::function<std::optional<unsigned char>()>& reader,
                  const std::function<bool(const std::vector<unsigned char>& output_word)>& writer);
};

#endif
