#ifndef CSB64_CLI_PARSER_F_ARGS_FROM_H
#define CSB64_CLI_PARSER_F_ARGS_FROM_H

#include <functional>
#include <string>
#include <vector>

namespace csb64_cli_parser::detail
{
    /*
     * Gets all strings from specified start point to specified end point,
     * stopping when stopper returns true for a string, or we reach end of list.
     * 
     * @param begin Where to start in the list.
     * @param end Where collection of strings ends.
     * @param stopper Function that classifies string, returning true in order
     * to stop early, or false to continue.
     */
    std::vector<std::string> strings_from(const std::vector<std::string>::const_iterator& begin,
                                          const std::vector<std::string>::const_iterator& end,
                                          const std::function<bool(const std::string&)>& stopper);
};

#endif
