#include <boost/test/unit_test.hpp>

#include "csb64_cli_parser/detail/begins_with_dash.h"

BOOST_AUTO_TEST_SUITE(begins_with_dash);

BOOST_AUTO_TEST_CASE(Outputs_true_when_string_begins_with_dash)
{
    BOOST_TEST(csb64_cli_parser::detail::begins_with_dash("-d"));
};

BOOST_AUTO_TEST_CASE(Outputs_true_when_string_only_contains_single_dash)
{
    BOOST_TEST(csb64_cli_parser::detail::begins_with_dash("-"));
};

BOOST_AUTO_TEST_CASE(Outputs_false_when_string_does_not_begin_with_dash)
{
    BOOST_TEST(!csb64_cli_parser::detail::begins_with_dash("d"));
};

BOOST_AUTO_TEST_CASE(Outputs_false_when_string_is_empty)
{
     BOOST_TEST(!csb64_cli_parser::detail::begins_with_dash(""));
};

BOOST_AUTO_TEST_SUITE_END();
