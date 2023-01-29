#ifndef CSB64_CLI_PARSER_CL_INVALIDCMDARG_H
#define CSB64_CLI_PARSER_CL_INVALIDCMDARG_H

#include <exception>

namespace csb64_cli_parser
{
    class InvalidCmdArg final : public std::exception
    {
        public:
            virtual const char* what() const noexcept override;
    };
};

#endif
