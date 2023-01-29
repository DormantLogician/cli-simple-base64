#include <boost/test/unit_test.hpp>

#include "csb64_cli_parser/detail/any_classifiers_match.h"
#include "csb64_cli_parser/id_classifier.h"

BOOST_AUTO_TEST_SUITE(any_classifiers_match);

BOOST_AUTO_TEST_CASE(Outputs_true_if_one_of_specified_classifiers_match)
{
    BOOST_TEST(
        csb64_cli_parser::detail::any_classifiers_match(
            "-d",
            {csb64_cli_parser::id_classifier("-e"),
             csb64_cli_parser::id_classifier("-t"),
             csb64_cli_parser::id_classifier("-d"),}
        )
    );
};

BOOST_AUTO_TEST_CASE(Outputs_false_if_none_of_specified_classifiers_match)
{
    BOOST_TEST(
        !csb64_cli_parser::detail::any_classifiers_match(
            "-f",
            {csb64_cli_parser::id_classifier("-e"),
             csb64_cli_parser::id_classifier("-t"),
             csb64_cli_parser::id_classifier("-d"),}
        )
    );
};

BOOST_AUTO_TEST_CASE(Outputs_false_when_no_classifiers_are_supplied)
{
    BOOST_TEST(
        !csb64_cli_parser::detail::any_classifiers_match(
            "-f",
            {}
        )
    );
};

BOOST_AUTO_TEST_SUITE_END();
