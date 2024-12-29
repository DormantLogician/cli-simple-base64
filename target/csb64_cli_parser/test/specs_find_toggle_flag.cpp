#include <boost/test/unit_test.hpp>

#include "csb64_cli_parser/InvalidCmdArg.h"
#include "csb64_cli_parser/id_classifier.h"
#include "csb64_cli_parser/find_toggle_flag.h"

BOOST_AUTO_TEST_SUITE(find_toggle_flag);

BOOST_AUTO_TEST_CASE(Outputs_true_when_single_flag_exists_in_list)
{
    bool output{
        csb64_cli_parser::find_toggle_flag(
            {"-f", "-e", "-t"},
            csb64_cli_parser::id_classifier("-f")
        )
    };

    BOOST_TEST(output);
};

BOOST_AUTO_TEST_CASE(Throws_when_more_flags_exist_than_one)
{
    BOOST_CHECK_THROW(csb64_cli_parser::find_toggle_flag(
            {"-f", "-f", "-t"},
            csb64_cli_parser::id_classifier("-f")
    ), csb64_cli_parser::InvalidCmdArg);
};

BOOST_AUTO_TEST_CASE(Throws_when_flag_has_a_single_argument)
{
    BOOST_CHECK_THROW(csb64_cli_parser::find_toggle_flag(
            {"-f", "Hello", "-e", "-t"},
            csb64_cli_parser::id_classifier("-f")
    ), csb64_cli_parser::InvalidCmdArg);
};

BOOST_AUTO_TEST_CASE(Outputs_false_when_user_args_empty)
{
    const bool output{
        csb64_cli_parser::find_toggle_flag(
            {},
            csb64_cli_parser::id_classifier("-f")
        )
    };

    BOOST_TEST(!output);
};

BOOST_AUTO_TEST_CASE(Outputs_false_when_flag_not_in_list)
{
    const bool output{
        csb64_cli_parser::find_toggle_flag(
            {"-e", "-t", "-a"},
            csb64_cli_parser::id_classifier("-f")
        )
    };

    BOOST_TEST(!output);
};

BOOST_AUTO_TEST_SUITE_END();
