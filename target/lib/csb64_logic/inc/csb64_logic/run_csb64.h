#ifndef CSB64_LOGIC_F_RUN_CSB64_H
#define CSB64_LOGIC_F_RUN_CSB64_H

#include <functional>
#include <vector>

namespace csb64_logic
{
    /*
     * Runner for the application (any input/output functionality is injected
     * in).
     *
     * @param user_args Input to command line (mirrors 'argv' array).
     * @param read_character Outputs a stream of characters from some arbitrary
     * location one by one.
     * @param write_character Writes a character to some arbitrary location.
     * @param at_end_of_stream Returns true if we are at end of some stream -
     * false otherwise.
     * @param print_error Is called to print error messages to some arbirary
     * location.
     * @param print_error Is called to print help info for program to some
     * arbirary location.
     */
    int run_csb64(const std::vector<std::string>& user_args,
                  const std::function<int()>& read_character,
                  const std::function<void(const unsigned char character)> write_character,
                  const std::function<bool()> at_end_of_stream,
                  const std::function<void(const std::string&)>& print_error,
                  const std::function<void()>& print_help_info);
};

#endif
