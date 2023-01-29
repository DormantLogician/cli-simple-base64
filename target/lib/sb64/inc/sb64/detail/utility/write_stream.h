#ifndef SB64_F_MAKE_WORD_READER_H
#define SB64_F_MAKE_WORD_READER_H

#include <vector>
#include <functional>
#include <optional>
#include <stdexcept>

namespace sb64::detail::utility
{
    template<typename Input, typename Output>
    void write_stream(const long long word_size,
                      const std::function<std::optional<Input>()>& reader,
                      const std::function<bool(const std::vector<Output>& output_word)>& on_input)
    {
        std::vector<Output> items{};
        if (word_size <= 0)
        {
            throw std::invalid_argument{"Word size must be greater than zero."};
        };

        std::optional<Input> current{reader()};
        while (current.has_value())
        {
            items.push_back(*current);
            if (items.size() >= word_size)
            {
                const bool should_continue{on_input(items)};
                if (!should_continue)
                {
                    return void();
                };

                items.clear();
            };

            current = reader();
        };

        if (!items.empty())
        {
            on_input(items);
        };
    };
};

#endif
