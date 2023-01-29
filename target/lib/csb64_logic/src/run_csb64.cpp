#include <vector>
#include <optional>
#include <functional>
#include <stdexcept>

#include "sb64/decode_b64.h"
#include "sb64/to_b64.h"

#include "csb64_logic/run_csb64.h"
#include "csb64_logic/constant/decode_flag.h"
#include "csb64_logic/constant/disable_newline_flag.h"
#include "csb64_logic/constant/err_code.h"
#include "csb64_logic/constant/format_flag.h"
#include "csb64_logic/constant/help_info_message.h"
#include "csb64_logic/constant/help_flag.h"
#include "csb64_logic/utility/string_to_integer.h"

#include "csb64_cli_parser/InvalidCmdArg.h"
#include "csb64_cli_parser/id_classifier.h"
#include "csb64_cli_parser/satisfies.h"
#include "csb64_cli_parser/find_unary_flag.h"
#include "csb64_cli_parser/find_toggle_flag.h"

namespace csb64_logic
{
    int run_csb64(const std::vector<std::string>& user_args,
                  const std::function<int()>& read_character,
                  const std::function<void(const unsigned char character)> write_character,
                  const std::function<bool()> at_end_of_stream,
                  const std::function<void(const std::string&)>& print_error,
                  const std::function<void()>& print_help_info)
    {
        const auto decode_reader{[&read_character, &at_end_of_stream]() -> std::optional<unsigned char>
        {
            int output{read_character()};

            const char newline_char{'\n'};
            const char carriage_return_char{'\x0D'};

            while (!at_end_of_stream() &&
                   ((static_cast<unsigned char>(output) == newline_char) || (static_cast<unsigned char>(output) == carriage_return_char)))
            {
                output = read_character();
            };

            if (at_end_of_stream())
            {
                return std::nullopt;
            };

            return static_cast<unsigned char>(output);
        }};

        const auto normal_writer{[&write_character](const std::vector<unsigned char>& input) -> bool
        {
            for (auto character{input.cbegin()}; character < input.cend(); ++character)
            {
                write_character(*character);
            };

            return true;
        }};

        const auto b64_reader{[&read_character, &at_end_of_stream]() -> std::optional<unsigned char>
        {
            int output{read_character()};

            if (at_end_of_stream())
            {
                return std::nullopt;
            };

            return static_cast<unsigned char>(output);
        }};

        const bool commands_are_recognized{
            csb64_cli_parser::satisfies(
                user_args,
                {csb64_cli_parser::id_classifier(csb64_logic::constant::decode_flag()),
                 csb64_cli_parser::id_classifier(csb64_logic::constant::disable_newline_flag()),
                 csb64_cli_parser::id_classifier(csb64_logic::constant::format_flag()),
                 csb64_cli_parser::id_classifier(csb64_logic::constant::help_flag())}
            )
        };

        try
        {
            const bool decode_flag_set{
                csb64_cli_parser::find_toggle_flag(
                    user_args, 
                    csb64_cli_parser::id_classifier(csb64_logic::constant::decode_flag())
                )
            };

            const bool newline_flag_set{
                csb64_cli_parser::find_toggle_flag(
                    user_args,
                    csb64_cli_parser::id_classifier(csb64_logic::constant::disable_newline_flag())
                )
            };

            const std::optional<std::string> format_flag_set{
                csb64_cli_parser::find_unary_flag(
                    user_args,
                    csb64_cli_parser::id_classifier(csb64_logic::constant::format_flag())
                )
            };

            const bool help_flag_set{
                csb64_cli_parser::find_toggle_flag(
                    user_args,
                    csb64_cli_parser::id_classifier(csb64_logic::constant::help_flag())
                )
            };

            const bool invalid_arguments{
                !commands_are_recognized ||
                (decode_flag_set && (newline_flag_set || help_flag_set || format_flag_set.has_value())) ||
                (help_flag_set && (decode_flag_set || format_flag_set.has_value() || newline_flag_set))
            };

            if (invalid_arguments)
            {
                throw csb64_cli_parser::InvalidCmdArg{};
            };

            if (help_flag_set)
            {
                print_help_info();
                return 0;
            };

            long long line_limit{72};

            if (format_flag_set.has_value())
            {
                const std::optional<long long> as_integer{
                    csb64_logic::utility::string_to_integer(*format_flag_set)
                };

                if (!as_integer.has_value() || (*as_integer < 0))
                {
                    throw csb64_cli_parser::InvalidCmdArg{};
                };

                line_limit = *as_integer;
            };

            long long pos_line{0};

            const auto cpl_writer{[&pos_line, line_limit, &write_character](const std::vector<unsigned char>& input) -> bool
            {
                for (auto character{input.cbegin()}; character < input.cend(); ++character)
                {
                    if (pos_line >= line_limit)
                    {
                        write_character('\n');
                        pos_line = 0;
                    };

                    write_character(*character);
                    ++pos_line;
                };

                return true;
            }};

            if (decode_flag_set)
            {
                try
                {
                    sb64::decode_b64(decode_reader, normal_writer);
                }
                catch(const std::invalid_argument& err)
                {
                    print_error("csb64: At least some data supplied to decoder was not valid base 64 encoded data.\n");
                    return csb64_logic::constant::err_code();
                }
            }
            else
            {
                if (line_limit == 0)
                {
                    sb64::to_b64(b64_reader, normal_writer);
                }
                else
                {
                    sb64::to_b64(b64_reader, cpl_writer);
                };

                if (!newline_flag_set)
                {
                    write_character('\n');
                };
            };
        }
        catch (const csb64_cli_parser::InvalidCmdArg& err)
        {
            print_error(csb64_logic::constant::help_info_message());
            return csb64_logic::constant::err_code();
        };

        return 0;
    };
};
