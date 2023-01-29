#include <boost/test/unit_test.hpp>

#include <string>
#include <vector>

#include "csb64_cli_parser/detail/strings_from.h"
#include "csb64_cli_parser/detail/begins_with_dash.h"

BOOST_AUTO_TEST_SUITE(strings_from);

BOOST_AUTO_TEST_CASE(Outputs_strings_from_begin_until_stopper_true)
{
    const std::vector<std::string> input{"-f", "Hello", "world", "-e", "apple"};

    const std::vector<std::string> output{
        csb64_cli_parser::detail::strings_from(
            input.cbegin() + 1,
            input.cend(),
            csb64_cli_parser::detail::begins_with_dash)
    };

    const std::vector<std::string> expected{"Hello", "world"};

    BOOST_CHECK_EQUAL_COLLECTIONS(
        output.cbegin(),
        output.cend(),
        expected.cbegin(),
        expected.cend()
    );
};

BOOST_AUTO_TEST_CASE(Stops_at_end_of_input_list_without_stopper)
{
    const std::vector<std::string> input{"Hello", "world", "apple"};

    const std::vector<std::string> output{
        csb64_cli_parser::detail::strings_from(
            input.cbegin(),
            input.cend(),
            csb64_cli_parser::detail::begins_with_dash)
    };

    const std::vector<std::string> expected{"Hello", "world", "apple"};

    BOOST_CHECK_EQUAL_COLLECTIONS(
        output.cbegin(),
        output.cend(),
        expected.cbegin(),
        expected.cend()
    );
};

BOOST_AUTO_TEST_CASE(Outputs_empty_list_on_empty_input_list)
{
    const std::vector<std::string> input{};

    const std::vector<std::string> output{
        csb64_cli_parser::detail::strings_from(
            input.cbegin(),
            input.cend(),
            csb64_cli_parser::detail::begins_with_dash)
    };

    const std::vector<std::string> expected{};

    BOOST_CHECK_EQUAL_COLLECTIONS(
        output.cbegin(),
        output.cend(),
        expected.cbegin(),
        expected.cend()
    );
};

BOOST_AUTO_TEST_CASE(Outputs_empty_list_when_no_strings_exist)
{
    const std::vector<std::string> input{"-f", "-e", "Hello", "world", "apple"};

    const std::vector<std::string> output{
        csb64_cli_parser::detail::strings_from(
            input.cbegin() + 1,
            input.cend(),
            csb64_cli_parser::detail::begins_with_dash)
    };

    const std::vector<std::string> expected{};

    BOOST_CHECK_EQUAL_COLLECTIONS(
        output.cbegin(),
        output.cend(),
        expected.cbegin(),
        expected.cend()
    );
};

BOOST_AUTO_TEST_SUITE_END();
