#include <boost/test/unit_test.hpp>

#include <string>
#include <vector>

#include "csb64_cli_parser/satisfies.h"
#include "csb64_cli_parser/id_classifier.h"

BOOST_AUTO_TEST_SUITE(satisfies);

BOOST_AUTO_TEST_CASE(Outputs_false_when_unknown_flag_exists)
{
    const std::vector<std::string> input{
        "-f", "Hello", "-e", "-t"
    };

    const bool output{
        csb64_cli_parser::satisfies(
            input,
            {csb64_cli_parser::id_classifier("-e"),
             csb64_cli_parser::id_classifier("-f")}
        )
    };

    BOOST_TEST(!output);
};

BOOST_AUTO_TEST_CASE(Outputs_false_when_list_begins_with_two_non_flags)
{
    const std::vector<std::string> input{
        "Goodbye", "Hello", "-f", "Hello", "-e", "-t"
    };

    const bool output{
        csb64_cli_parser::satisfies(
            input,
            {csb64_cli_parser::id_classifier("-e"),
             csb64_cli_parser::id_classifier("-f"),
             csb64_cli_parser::id_classifier("-t")}
        )
    };

    BOOST_TEST(!output);
};

BOOST_AUTO_TEST_CASE(Outputs_false_when_no_classifiers_are_supplied)
{
    const std::vector<std::string> input{
        "-f", "Hello", "-e", "-t"
    };

    const bool output{
        csb64_cli_parser::satisfies(
            input,
            {}
        )
    };

    BOOST_TEST(!output);
};

BOOST_AUTO_TEST_CASE(Outputs_true_when_user_args_empty)
{
    const std::vector<std::string> input{};

    const bool output{
        csb64_cli_parser::satisfies(
            input,
            {csb64_cli_parser::id_classifier("-e"),
             csb64_cli_parser::id_classifier("-f"),
             csb64_cli_parser::id_classifier("-t")}
        )
    };

    BOOST_TEST(output);
};

BOOST_AUTO_TEST_CASE(Outputs_true_when_all_flags_are_known_and_begins_with_less_than_two_non_flags)
{
    const std::vector<std::string> input{
        "-f", "Hello", "-e", "-t"
    };

    const bool output{
        csb64_cli_parser::satisfies(
            input,
            {csb64_cli_parser::id_classifier("-e"),
             csb64_cli_parser::id_classifier("-f"),
             csb64_cli_parser::id_classifier("-t")}
        )
    };

    BOOST_TEST(output);
};

BOOST_AUTO_TEST_SUITE_END();
