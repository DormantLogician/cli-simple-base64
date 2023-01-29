#include <boost/test/unit_test.hpp>

#include "sb64/detail/Letter.h"

BOOST_AUTO_TEST_SUITE(Letter_by_eight_bits);

BOOST_AUTO_TEST_CASE(Empty_list_output_on_empty_list_input)
{
    const std::vector<sb64::detail::Letter> output{sb64::detail::Letter::by_eight_bits(std::vector<sb64::detail::Letter>{})};

    BOOST_TEST(output.empty());
};

BOOST_AUTO_TEST_CASE(Outputs_correct_character_with_list_that_has_single_element)
{
    const std::vector<sb64::detail::Letter> input{0b10000110};

    const std::vector<unsigned char> expected{
        0b10000110
    };

    const std::vector<sb64::detail::Letter> output{
        sb64::detail::Letter::by_eight_bits(input)
    };

    const std::vector<unsigned char> uchars{
        sb64::detail::Letter::as_uchars(output)
    };

    BOOST_CHECK_EQUAL_COLLECTIONS(
        uchars.cbegin(),
        uchars.cend(),
        expected.cbegin(),
        expected.cend()
    );
};

BOOST_AUTO_TEST_CASE(Outputs_correct_character_with_list_that_has_letter_less_than_eight_bits)
{
    const std::vector<sb64::detail::Letter> input{
        sb64::detail::Letter{std::vector<bool>{true, false, true}}
    };

    const std::vector<unsigned char> expected{
        0b00000101
    };

    const std::vector<sb64::detail::Letter> output{
        sb64::detail::Letter::by_eight_bits(input)
    };

    const std::vector<unsigned char> uchars{
        sb64::detail::Letter::as_uchars(output)
    };

    BOOST_CHECK_EQUAL_COLLECTIONS(
        uchars.cbegin(),
        uchars.cend(),
        expected.cbegin(),
        expected.cend()
    );
};

BOOST_AUTO_TEST_CASE(Outputs_correct_character_with_list_that_has_multiple_letters_less_than_eight_bits)
{
    const std::vector<sb64::detail::Letter> input{
        sb64::detail::Letter{std::vector<bool>{true, false, true}},
        sb64::detail::Letter{std::vector<bool>{true, false, true, true}},
        sb64::detail::Letter{std::vector<bool>{false, false, true, true}}
    };

    const std::vector<unsigned char> expected{
        0b10110110,
        0b00000011
    };

    const std::vector<sb64::detail::Letter> output{
        sb64::detail::Letter::by_eight_bits(input)
    };

    const std::vector<unsigned char> uchars{
        sb64::detail::Letter::as_uchars(output)
    };

    BOOST_CHECK_EQUAL_COLLECTIONS(
        uchars.cbegin(),
        uchars.cend(),
        expected.cbegin(),
        expected.cend()
    );
};

BOOST_AUTO_TEST_CASE(Outputs_correct_characters_with_list_that_has_multiple_elements)
{
    const std::vector<sb64::detail::Letter> input{
        0b10000110,
        0b00000101,
        0b01110111
    };

    const std::vector<unsigned char> expected{
        0b10000110,
        0b00000101,
        0b01110111
    };

    const std::vector<sb64::detail::Letter> output{
        sb64::detail::Letter::by_eight_bits(input)
    };

    const std::vector<unsigned char> uchars{
        sb64::detail::Letter::as_uchars(output)
    };

    BOOST_CHECK_EQUAL_COLLECTIONS(
        uchars.cbegin(),
        uchars.cend(),
        expected.cbegin(),
        expected.cend()
    );
};

BOOST_AUTO_TEST_CASE(Outputs_correct_characters_with_list_that_has_empty_letters)
{
    const std::vector<sb64::detail::Letter> input{
        sb64::detail::Letter{std::vector<bool>{}},
        0b10000110,
        0b00000101,
        sb64::detail::Letter{std::vector<bool>{}},
        0b01110111
    };

    const std::vector<unsigned char> expected{
        0b10000110,
        0b00000101,
        0b01110111,
    };

    const std::vector<sb64::detail::Letter> output{
        sb64::detail::Letter::by_eight_bits(input)
    };

    const std::vector<unsigned char> uchars{
        sb64::detail::Letter::as_uchars(output)
    };

    BOOST_CHECK_EQUAL_COLLECTIONS(
        uchars.cbegin(),
        uchars.cend(),
        expected.cbegin(),
        expected.cend()
    );
};

BOOST_AUTO_TEST_SUITE_END();
