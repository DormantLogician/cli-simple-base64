#ifndef CSB64_CLI_PARSER_CL_INVALIDCMDARG_H
#define CSB64_CLI_PARSER_CL_INVALIDCMDARG_H

#include <exception>

namespace csb64_cli_parser
{
    /*
     * Primary error class for command line arguments used by command line
     * parser.
     */
    class InvalidCmdArg final : public std::exception
    {
        public:
            virtual const char* what() const noexcept override;
    };
};

#endif
