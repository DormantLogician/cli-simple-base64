#include <boost/test/unit_test.hpp>

#include "csb64_logic/constant/help_info_message.h"

BOOST_AUTO_TEST_SUITE(help_info_message);

BOOST_AUTO_TEST_CASE(Outputs_correct_message)
{
    BOOST_CHECK_EQUAL(csb64_logic::constant::help_info_message(), 
               std::string{"Usage: csb64 [OPTION]...\n"} +
                           "Encode or decode base 64 - uses standard input and output.\n" +
                           "\n" +
                           "Available options (default mode is encode):\n" +
                           "  -d         Set mode to decode - incompatible with help mode.\n" +
                           "  -h         Displays this help dialog - incompatible with all other options.\n" +
                           "  -w COLS    Sets number of characters to write before adding linebreaks\n" +
                           "             to output (default is 72). Set COLS to zero to disable linebreaks.\n" +
                           "             For encode mode only.\n" +
                           "  -n         Disable trailing newline in output - for encode mode only.\n"
    );
};

BOOST_AUTO_TEST_SUITE_END();
