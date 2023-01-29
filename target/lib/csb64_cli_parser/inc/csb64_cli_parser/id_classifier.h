#ifndef CSB64_CLI_PARSER_F_ID_CLASSIFIER_H
#define CSB64_CLI_PARSER_F_ID_CLASSIFIER_H

#include <string>
#include <functional>

namespace csb64_cli_parser
{
    std::function<bool(const std::string& id)> id_classifier(const std::string& id);
};

#endif
