#include <boost/test/unit_test.hpp>

#include "specs_find_all/values_of.h"
#include "specs_find_all/indexes_of.h"
#include "csb64_cli_parser/id_classifier.h"
#include "csb64_cli_parser/detail/find_all.h"

BOOST_AUTO_TEST_SUITE(find_all);

using VecIterator = std::vector<std::string>::const_iterator;

BOOST_AUTO_TEST_CASE(Output_iterators_have_values_equal_to_found_strings)
{
    const std::vector<std::string> input{"b", "a", "a", "b", "c", "b"};

    const std::vector<std::string> output{
        specs_find_all::values_of(
            csb64_cli_parser::detail::find_all(
                input.cbegin(),
                input.cend(),
                csb64_cli_parser::id_classifier("b")
            )
        )
    };

    const std::vector<std::string> expected{
        "b", "b", "b"
    };

    BOOST_CHECK_EQUAL_COLLECTIONS(
        output.cbegin(),
        output.cend(),
        expected.cbegin(),
        expected.cend()
    );
};

BOOST_AUTO_TEST_CASE(Output_iterators_point_to_correct_locations)
{
    const std::vector<std::string> input{"b", "a", "a", "b", "c", "b"};

    const std::vector<long long> output{
        specs_find_all::indexes_of(
            input.cbegin(),
            csb64_cli_parser::detail::find_all(
                input.cbegin(),
                input.cend(),
                csb64_cli_parser::id_classifier("b")
            )
        )
    };

    const std::vector<long long> expected{
        0, 3, 5
    };

    BOOST_CHECK_EQUAL_COLLECTIONS(
        output.cbegin(),
        output.cend(),
        expected.cbegin(),
        expected.cend()
    );
};

BOOST_AUTO_TEST_CASE(Output_iterators_point_to_correct_locations_when_reading_part_of_input)
{
    const std::vector<std::string> input{"b", "a", "a", "b", "c", "b"};

    const std::vector<long long> output{
        specs_find_all::indexes_of(
            input.cbegin(),
            csb64_cli_parser::detail::find_all(
                input.cbegin() + 1,
                input.cend() - 1,
                csb64_cli_parser::id_classifier("b")
            )
        )
    };

    const std::vector<long long> expected{
        3
    };

    BOOST_CHECK_EQUAL_COLLECTIONS(
        output.cbegin(),
        output.cend(),
        expected.cbegin(),
        expected.cend()
    );
};

BOOST_AUTO_TEST_CASE(Outputs_empty_list_when_no_matches_are_found)
{
    const std::vector<std::string> input{"b", "a", "a", "b", "c", "b"};

    const std::vector<VecIterator> output{
        csb64_cli_parser::detail::find_all(
            input.cbegin(),
            input.cend(),
            csb64_cli_parser::id_classifier("e")
        )
    };

    BOOST_TEST(output.empty());
};

BOOST_AUTO_TEST_CASE(Finds_instances_of_string_when_single_item_in_list)
{
    const std::vector<std::string> input{"b"};

    const std::vector<std::string> output{
        specs_find_all::values_of(
            csb64_cli_parser::detail::find_all(
                input.cbegin(),
                input.cend(),
                csb64_cli_parser::id_classifier("b")
            )
        )
    };

    const std::vector<std::string> expected{
        "b"
    };

    BOOST_CHECK_EQUAL_COLLECTIONS(
        output.cbegin(),
        output.cend(),
        expected.cbegin(),
        expected.cend()
    );
};

BOOST_AUTO_TEST_CASE(Output_iterators_point_to_correct_locations_when_single_item_in_list)
{
    const std::vector<std::string> input{"b"};

    const std::vector<long long> output{
        specs_find_all::indexes_of(
            input.cbegin(),
            csb64_cli_parser::detail::find_all(
                input.cbegin(),
                input.cend(),
                csb64_cli_parser::id_classifier("b")
            )
        )
    };

    const std::vector<long long> expected{
        0
    };

    BOOST_CHECK_EQUAL_COLLECTIONS(
        output.cbegin(),
        output.cend(),
        expected.cbegin(),
        expected.cend()
    );
};

BOOST_AUTO_TEST_CASE(Outputs_empty_list_on_empty_input_list)
{
    const std::vector<std::string> input{};

    const std::vector<VecIterator> output{
        csb64_cli_parser::detail::find_all(
            input.cbegin(),
            input.cend(),
            csb64_cli_parser::id_classifier("b")
        )
    };

    BOOST_TEST(output.empty());
};

BOOST_AUTO_TEST_SUITE_END();
