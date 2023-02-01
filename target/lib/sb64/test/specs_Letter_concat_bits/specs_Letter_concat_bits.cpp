#include <boost/test/unit_test.hpp>

#include "sb64/Letter.h"

BOOST_AUTO_TEST_SUITE(Letter_concat_bits);

BOOST_AUTO_TEST_CASE(Outputs_no_bits_for_empty_list)
{
    const std::vector<bool> output{sb64::Letter::concat_bits(std::vector<sb64::Letter>{})};

    BOOST_TEST(output.empty());
};

BOOST_AUTO_TEST_CASE(Outputs_no_bits_for_single_empty_letter)
{
    const std::vector<sb64::Letter> input{
        sb64::Letter{std::vector<bool>{}}
    };

    const std::vector<bool> output{sb64::Letter::concat_bits(input)};

    BOOST_TEST(output.empty());
};

BOOST_AUTO_TEST_CASE(Same_bits_for_single_eight_bit_letter)
{
    const std::vector<sb64::Letter> input{
        0b11101110
    };

    const std::vector<bool> output{sb64::Letter::concat_bits(input)};

    const std::vector<bool> expected{
        true, true, true, false, true, true, true, false
    };

    BOOST_CHECK_EQUAL_COLLECTIONS(
        output.cbegin(),
        output.cend(),
        expected.cbegin(),
        expected.cend()
    );
};

BOOST_AUTO_TEST_CASE(Same_bits_for_single_letter_less_than_eight_bit_letter)
{
    const std::vector<sb64::Letter> input{
        sb64::Letter{std::vector<bool>{true, false, true}}
    };

    const std::vector<bool> output{sb64::Letter::concat_bits(input)};

    const std::vector<bool> expected{
        true, false, true
    };

    BOOST_CHECK_EQUAL_COLLECTIONS(
        output.cbegin(),
        output.cend(),
        expected.cbegin(),
        expected.cend()
    );
};

BOOST_AUTO_TEST_CASE(Concatenates_bits_of_multiple_letters)
{
    const std::vector<sb64::Letter> input{
        0b11101110,
        0b00001011
    };

    const std::vector<bool> output{sb64::Letter::concat_bits(input)};

    const std::vector<bool> expected{
        true, true, true, false, true, true, true, false, false, false, false, false, true, false, true, true
    };

    BOOST_CHECK_EQUAL_COLLECTIONS(
        output.cbegin(),
        output.cend(),
        expected.cbegin(),
        expected.cend()
    );
};

BOOST_AUTO_TEST_CASE(Ignores_bits_of_empty_letters)
{
    const std::vector<sb64::Letter> input{
        0b00001011,
        sb64::Letter{std::vector<bool>{}},
        0b00000101
    };

    const std::vector<bool> output{sb64::Letter::concat_bits(input)};

    const std::vector<bool> expected{
        false, false, false, false, true, false, true, true, false, false, false, false, false, true, false, true
    };

    BOOST_CHECK_EQUAL_COLLECTIONS(
        output.cbegin(),
        output.cend(),
        expected.cbegin(),
        expected.cend()
    );
};

BOOST_AUTO_TEST_CASE(Concatenates_bits_of_letters_with_less_than_eight_bits)
{
    const std::vector<sb64::Letter> input{
        sb64::Letter{std::vector<bool>{true, false, true}},
        sb64::Letter{std::vector<bool>{true}},
        sb64::Letter{std::vector<bool>{false, true}}
    };

    const std::vector<bool> output{sb64::Letter::concat_bits(input)};

    const std::vector<bool> expected{
        true, false, true, true, false, true
    };

    BOOST_CHECK_EQUAL_COLLECTIONS(
        output.cbegin(),
        output.cend(),
        expected.cbegin(),
        expected.cend()
    );
};

BOOST_AUTO_TEST_SUITE_END();
