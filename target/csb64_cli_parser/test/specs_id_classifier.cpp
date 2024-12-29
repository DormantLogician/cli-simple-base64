#include <boost/test/unit_test.hpp>

#include "csb64_cli_parser/id_classifier.h"

BOOST_AUTO_TEST_SUITE(id_classifier);

BOOST_AUTO_TEST_CASE(Output_function_returns_true_on_match)
{
    const auto classifier{
        csb64_cli_parser::id_classifier("-f")
    };

    BOOST_TEST(classifier("-f"));
};

BOOST_AUTO_TEST_CASE(Output_function_returns_false_on_not_match)
{
    const auto classifier{
        csb64_cli_parser::id_classifier("-f")
    };

    BOOST_TEST(!classifier("f"));
};

BOOST_AUTO_TEST_CASE(Output_function_finds_empty_string)
{
    const auto classifier{
        csb64_cli_parser::id_classifier("")
    };

    BOOST_TEST(classifier(""));
};

BOOST_AUTO_TEST_SUITE_END();
