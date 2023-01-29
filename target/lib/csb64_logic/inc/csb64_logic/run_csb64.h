#ifndef CSB64_LOGIC_F_RUN_CSB64_H
#define CSB64_LOGIC_F_RUN_CSB64_H

#include <functional>
#include <vector>

namespace csb64_logic
{
    int run_csb64(const std::vector<std::string>& user_args,
                  const std::function<int()>& read_character,
                  const std::function<void(const unsigned char character)> write_character,
                  const std::function<bool()> at_end_of_stream,
                  const std::function<void(const std::string&)>& print_error,
                  const std::function<void()>& print_help_info);
};

#endif
