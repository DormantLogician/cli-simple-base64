#include <boost/test/unit_test.hpp>

#include <string>
#include <optional>

#include "csb64_cli_parser/InvalidCmdArg.h"
#include "csb64_cli_parser/id_classifier.h"
#include "csb64_cli_parser/find_unary_flag.h"

BOOST_AUTO_TEST_SUITE(find_unary_flag);

BOOST_AUTO_TEST_CASE(Throws_when_input_has_multiple_instances_of_same_flag)
{
    BOOST_CHECK_THROW(csb64_cli_parser::find_unary_flag(
            {"-a", "-f", "-f", "arg", "-t"},
            csb64_cli_parser::id_classifier("-f")
    ), csb64_cli_parser::InvalidCmdArg);

    BOOST_CHECK_THROW(csb64_cli_parser::find_unary_flag(
            {"-a", "-f", "arg", "-f", "arg", "-t"},
            csb64_cli_parser::id_classifier("-f")
    ), csb64_cli_parser::InvalidCmdArg);

    BOOST_CHECK_THROW(csb64_cli_parser::find_unary_flag(
            {"-a", "-f", "arg", "-f", "arg", "arg2", "-t"},
            csb64_cli_parser::id_classifier("-f")
    ), csb64_cli_parser::InvalidCmdArg);
};

BOOST_AUTO_TEST_CASE(Throws_when_input_flag_has_multiple_arguments)
{
    BOOST_CHECK_THROW(csb64_cli_parser::find_unary_flag(
            {"-a", "-f", "arg", "arg2", "-t"},
            csb64_cli_parser::id_classifier("-f")
    ), csb64_cli_parser::InvalidCmdArg);

    BOOST_CHECK_THROW(csb64_cli_parser::find_unary_flag(
            {"-f", "arg", "arg", "-t"},
            csb64_cli_parser::id_classifier("-f")
    ), csb64_cli_parser::InvalidCmdArg);

    BOOST_CHECK_THROW(csb64_cli_parser::find_unary_flag(
            {"-a", "-f", "arg", "arg"},
            csb64_cli_parser::id_classifier("-f")
    ), csb64_cli_parser::InvalidCmdArg);
};

BOOST_AUTO_TEST_CASE(Yields_value_of_flag_when_input_has_multiple_other_flags)
{
    std::optional<std::string> output{
        csb64_cli_parser::find_unary_flag(
            {"-a", "arg", "-b", "-f", "target", "-c", "-d", "arg", "arg"},
            csb64_cli_parser::id_classifier("-f")
        )
    };

    BOOST_REQUIRE(output.has_value());

    BOOST_CHECK_EQUAL(*output, "target");
};

BOOST_AUTO_TEST_CASE(Yields_value_of_flag_when_input_has_a_single_flag_only)
{
    std::optional<std::string> output{
        csb64_cli_parser::find_unary_flag(
            {"-f", "target"},
            csb64_cli_parser::id_classifier("-f")
        )
    };

    BOOST_REQUIRE(output.has_value());

    BOOST_CHECK_EQUAL(*output, "target");
};

BOOST_AUTO_TEST_CASE(Yields_empty_value_when_input_flag_not_in_arguments)
{
    const std::optional<std::string> output{
        csb64_cli_parser::find_unary_flag(
            {"-a", "e", "-b", "-f", "e", "-c", "-d", "e", "e"},
            csb64_cli_parser::id_classifier("-e")
        )
    };

    BOOST_TEST(!output.has_value());
};

BOOST_AUTO_TEST_CASE(Yields_empty_value_when_input_is_empty)
{
    const std::optional<std::string> output{
        csb64_cli_parser::find_unary_flag(
            {},
            csb64_cli_parser::id_classifier("-e")
        )
    };

    BOOST_TEST(!output.has_value());
};

BOOST_AUTO_TEST_SUITE_END();
