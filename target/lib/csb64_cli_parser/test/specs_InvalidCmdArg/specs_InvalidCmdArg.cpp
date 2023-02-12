#include <boost/test/unit_test.hpp>
#include <string>

#include "csb64_cli_parser/InvalidCmdArg.h"

BOOST_AUTO_TEST_SUITE(InvalidCmdArg);

BOOST_AUTO_TEST_CASE(Error_message_is_correct)
{
    const std::string expected{
        "csb64: Invalid arguments or number of arguments supplied to program.\n"
    };

    BOOST_CHECK_EQUAL(expected, csb64_cli_parser::InvalidCmdArg{}.what());
};

BOOST_AUTO_TEST_SUITE_END();
