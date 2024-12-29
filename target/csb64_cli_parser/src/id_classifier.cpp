#include <string>
#include <functional>

#include "csb64_cli_parser/id_classifier.h"

namespace csb64_cli_parser
{
    std::function<bool(const std::string& id)> id_classifier(const std::string& id)
    {
        return [id](const std::string& input) -> bool
        {
            return input == id;
        };
    }
};
