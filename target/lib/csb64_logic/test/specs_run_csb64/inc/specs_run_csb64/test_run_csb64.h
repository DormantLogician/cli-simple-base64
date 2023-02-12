#ifndef SPECS_RUN_CSB64_F_TEST_RUN_CSB64_H
#define SPECS_RUN_CSB64_F_TEST_RUN_CSB64_H

#include <string>
#include <vector>
#include <optional>

namespace specs_run_csb64
{
    std::optional<std::vector<unsigned char>> test_run_csb64(const std::vector<std::string>& user_args,
                                                             const std::vector<unsigned char>& stream_data);
};

#endif
