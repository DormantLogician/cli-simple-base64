#include <boost/test/unit_test.hpp>

#include "csb64_logic/constant/err_code.h"

BOOST_AUTO_TEST_SUITE(err_code);

BOOST_AUTO_TEST_CASE(Outputs_correct_flag)
{
    BOOST_CHECK_EQUAL(csb64_logic::constant::err_code(), 1);
};

BOOST_AUTO_TEST_SUITE_END();
