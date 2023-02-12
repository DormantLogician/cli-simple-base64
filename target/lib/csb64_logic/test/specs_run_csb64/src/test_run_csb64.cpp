#include <string>
#include <vector>
#include <optional>
#include <functional>

#include "csb64_logic/constant/err_code.h"
#include "csb64_logic/run_csb64.h"

#include "specs_run_csb64/test_run_csb64.h"

namespace specs_run_csb64
{
    std::optional<std::vector<unsigned char>> test_run_csb64(const std::vector<std::string>& user_args,
                                                             const std::vector<unsigned char>& stream_data)
    {
        std::vector<unsigned char> write_location{};

        bool end_of_stream_reached{false};
        auto position{stream_data.cbegin()};

        const auto reader{[&end_of_stream_reached, &position, &stream_data]() -> int
        {
            if (position < stream_data.cend())
            {
                const unsigned char value{*position};
                ++position;
                return value;
            }
            else
            {
                end_of_stream_reached = true;
                return -1;
            };
        }};

        const auto writer{[&write_location](const unsigned char character) -> void
        {
            write_location.push_back(character);
        }};

        const auto at_end{[&end_of_stream_reached]() -> bool
        {
            return end_of_stream_reached;
        }};

        const auto print_error{[](const std::string& message) -> void
        {
            return void();
        }};

        const auto print_help{[]() -> void
        {
            return void();
        }};

        const int output{
            csb64_logic::run_csb64(
                user_args,
                reader,
                writer,
                at_end,
                print_error,
                print_help
            )
        };

        return ((output == csb64_logic::constant::err_code()) ? 
                std::nullopt : 
                std::optional<std::vector<unsigned char>>{write_location});
    };
};
