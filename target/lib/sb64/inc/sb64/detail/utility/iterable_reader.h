#ifndef SB64_F_ITERABLE_READER_H
#define SB64_F_ITERABLE_READER_H

#include <optional>

namespace sb64::detail::utility
{
    template<typename Value, typename Iterator, typename EndIterator>
    auto iterable_reader(Iterator iter,
                         EndIterator end)
    {
        return [iter, end]() mutable -> std::optional<Value>
        {
            if (iter != end)
            {
                const auto output{iter};
                ++iter;
                return *output;
            }
            else
            {
                return std::nullopt;
            };
        };
    };
};

#endif
