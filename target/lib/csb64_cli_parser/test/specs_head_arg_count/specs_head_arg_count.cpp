#include <boost/test/unit_test.hpp>

#include "csb64_cli_parser/detail/head_arg_count.h"
#include "csb64_cli_parser/detail/begins_with_dash.h"

BOOST_AUTO_TEST_SUITE(head_arg_count);

BOOST_AUTO_TEST_CASE(Outputs_zero_for_empty_list)
{
    const std::vector<std::string> input{};

    const long long output{
        csb64_cli_parser::detail::head_arg_count(
            input,
            csb64_cli_parser::detail::begins_with_dash
        )
    };

    BOOST_CHECK_EQUAL(output, 0);
};

BOOST_AUTO_TEST_CASE(Outputs_one_for_list_with_size_of_one)
{
    const std::vector<std::string> input{"a"};

    const long long output{
        csb64_cli_parser::detail::head_arg_count(
            input,
            csb64_cli_parser::detail::begins_with_dash
        )
    };

    BOOST_CHECK_EQUAL(output, 1);
};

BOOST_AUTO_TEST_CASE(Outputs_two_for_list_with_size_of_two)
{
    const std::vector<std::string> input{"a", "b"};

    const long long output{
        csb64_cli_parser::detail::head_arg_count(
            input,
            csb64_cli_parser::detail::begins_with_dash
        )
    };

    BOOST_CHECK_EQUAL(output, 2);
};

BOOST_AUTO_TEST_CASE(Outputs_one_after_stopping_at_first_cmd)
{
    const std::vector<std::string> input{"./programname", "-f", "Hello"};

    const long long output{
        csb64_cli_parser::detail::head_arg_count(
            input,
            csb64_cli_parser::detail::begins_with_dash
        )
    };

    BOOST_CHECK_EQUAL(output, 1);
};

BOOST_AUTO_TEST_SUITE_END();
