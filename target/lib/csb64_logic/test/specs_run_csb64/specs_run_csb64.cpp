#include <boost/test/unit_test.hpp>

#include "specs_run_csb64/test_run_csb64.h"

BOOST_AUTO_TEST_SUITE(run_csb64);

BOOST_AUTO_TEST_CASE(Empty_output_on_invalid_decoder_input)
{
    const std::optional<std::vector<unsigned char>> output{
        specs_run_csb64::test_run_csb64(
            {"-d"},
            {'!'}
        )
    };

    BOOST_TEST(!output.has_value());
};

BOOST_AUTO_TEST_CASE(Decoder_ignores_newline_characters)
{
    const std::optional<std::vector<unsigned char>> output{
        specs_run_csb64::test_run_csb64(
            {"-d"},
            {'\n', 'Q', '\n', 'Q', '=', '=', '\n'}
        )
    };

    const std::vector<unsigned char> expected{'A'};

    BOOST_REQUIRE(output.has_value());

    BOOST_CHECK_EQUAL_COLLECTIONS(
        output->cbegin(),
        output->cend(),
        expected.cbegin(),
        expected.cend()
    );
};

BOOST_AUTO_TEST_CASE(Decoder_ignores_carriage_return_characters)
{
    const std::optional<std::vector<unsigned char>> output{
        specs_run_csb64::test_run_csb64(
            {"-d"},
            {'\x0D', 'Q', '\x0D', 'Q', '=', '=', '\x0D'}
        )
    };

    const std::vector<unsigned char> expected{'A'};

    BOOST_REQUIRE(output.has_value());

    BOOST_CHECK_EQUAL_COLLECTIONS(
        output->cbegin(),
        output->cend(),
        expected.cbegin(),
        expected.cend()
    );
};

BOOST_AUTO_TEST_CASE(Outputs_base64_encoded_data_with_newline_when_requested)
{
    const std::optional<std::vector<unsigned char>> output{
        specs_run_csb64::test_run_csb64(
            {},
            {'H', 'e', 'l', 'l', 'o'}
        )
    };

    const std::vector<unsigned char> expected{'S', 'G', 'V', 's', 'b', 'G', '8', '=', '\n'};

    BOOST_REQUIRE(output.has_value());

    BOOST_CHECK_EQUAL_COLLECTIONS(
        output->cbegin(),
        output->cend(),
        expected.cbegin(),
        expected.cend()
    );
};

BOOST_AUTO_TEST_CASE(Outputs_decoded_base64_data_when_requested)
{
    const std::optional<std::vector<unsigned char>> output{
        specs_run_csb64::test_run_csb64(
            {"-d"},
            {'S', 'G', 'V', 's', 'b', 'G', '8', '='}
        )
    };

    const std::vector<unsigned char> expected{'H', 'e', 'l', 'l', 'o'};

    BOOST_REQUIRE(output.has_value());

    BOOST_CHECK_EQUAL_COLLECTIONS(
        output->cbegin(),
        output->cend(),
        expected.cbegin(),
        expected.cend()
    );
};

BOOST_AUTO_TEST_CASE(Encodes_null_characters_properly)
{
    const std::optional<std::vector<unsigned char>> output{
        specs_run_csb64::test_run_csb64(
            {},
            {'\0', '\0', '\0'}
        )
    };

    const std::vector<unsigned char> expected{'A', 'A', 'A', 'A', '\n'};

    BOOST_REQUIRE(output.has_value());

    BOOST_CHECK_EQUAL_COLLECTIONS(
        output->cbegin(),
        output->cend(),
        expected.cbegin(),
        expected.cend()
    );
};

BOOST_AUTO_TEST_CASE(Encodes_binary_all_ones_properly)
{
    const std::optional<std::vector<unsigned char>> output{
        specs_run_csb64::test_run_csb64(
            {},
            {0b11111111, 0b11111111, 0b11111111}
        )
    };

    const std::vector<unsigned char> expected{'/', '/', '/', '/', '\n'};

    BOOST_REQUIRE(output.has_value());

    BOOST_CHECK_EQUAL_COLLECTIONS(
        output->cbegin(),
        output->cend(),
        expected.cbegin(),
        expected.cend()
    );
};

BOOST_AUTO_TEST_CASE(Encodes_empty_input)
{
    const std::optional<std::vector<unsigned char>> output{
        specs_run_csb64::test_run_csb64(
            {},
            {}
        )
    };

    const std::vector<unsigned char> expected{'\n'};

    BOOST_REQUIRE(output.has_value());

    BOOST_CHECK_EQUAL_COLLECTIONS(
        output->cbegin(),
        output->cend(),
        expected.cbegin(),
        expected.cend()
    );
};

BOOST_AUTO_TEST_CASE(Error_on_non_flag_start)
{
    const std::optional<std::vector<unsigned char>> output{
        specs_run_csb64::test_run_csb64(
            {"./programname", "Hello", "-d"},
            {}
        )
    };

    BOOST_TEST(!output.has_value());
};

BOOST_AUTO_TEST_CASE(Error_on_unrecognized_flags)
{
    const std::optional<std::vector<unsigned char>> output{
        specs_run_csb64::test_run_csb64(
            {"-d", "-z"},
            {}
        )
    };

    BOOST_TEST(!output.has_value());
};

BOOST_AUTO_TEST_CASE(Error_on_decode_flag_argument)
{
    const std::optional<std::vector<unsigned char>> output{
        specs_run_csb64::test_run_csb64(
            {"-d", "Hello", "-z"},
            {}
        )
    };

    BOOST_TEST(!output.has_value());
};

BOOST_AUTO_TEST_CASE(Error_on_newline_flag_argument)
{
    const std::optional<std::vector<unsigned char>> output{
        specs_run_csb64::test_run_csb64(
            {"-n", "Hello", "-z"},
            {}
        )
    };

    BOOST_TEST(!output.has_value());
};

BOOST_AUTO_TEST_CASE(Error_on_newline_flag_and_decode_flag)
{
    const std::optional<std::vector<unsigned char>> output{
        specs_run_csb64::test_run_csb64(
            {"-n", "-d"},
            {}
        )
    };

    BOOST_TEST(!output.has_value());
};

BOOST_AUTO_TEST_SUITE_END();
