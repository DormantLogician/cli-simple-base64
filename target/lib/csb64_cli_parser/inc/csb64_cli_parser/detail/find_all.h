#ifndef CSB64_CLI_PARSER_F_FIND_ALL_H
#define CSB64_CLI_PARSER_F_FIND_ALL_H

#include <functional>
#include <string>
#include <vector>

namespace csb64_cli_parser::detail
{
    /*
     * Finds all iterators to strings in a list that match the specified
     * classifier.
     * 
     * @param begin Where to start search in the list.
     * @param end Where search ends.
     * @param classifier Classifier to use to select items from list
     */
    std::vector<std::vector<std::string>::const_iterator> find_all(const std::vector<std::string>::const_iterator& begin,
                                                                   const std::vector<std::string>::const_iterator& end,
                                                                   const std::function<bool(const std::string& id)>& classifier);
};

#endif
