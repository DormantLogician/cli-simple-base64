#include <boost/test/unit_test.hpp>

#include "csb64_logic/constant/decode_flag.h"

BOOST_AUTO_TEST_SUITE(decode_flag);

BOOST_AUTO_TEST_CASE(Outputs_correct_flag)
{
    BOOST_CHECK_EQUAL(csb64_logic::constant::decode_flag(), "-d");
};

BOOST_AUTO_TEST_SUITE_END();
