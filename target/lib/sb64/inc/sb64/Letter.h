#ifndef SB64_CL_LETTER_H
#define SB64_CL_LETTER_H

#include <vector>

namespace sb64
{
    class Letter final
    {
        private:
            std::vector<bool> stored;

            static std::vector<bool> truncate_bits(const std::vector<bool>& input);
            static std::vector<Letter> by_bits(const std::vector<Letter>& bit_groups,
                                               const long long group_max_size);

        public:
            static const unsigned char max_size;

            static std::vector<unsigned char> as_uchars(const std::vector<Letter>& input);
            static std::vector<bool> concat_bits(const std::vector<Letter>& input);
            static std::vector<Letter> by_eight_bits(const std::vector<Letter>& bit_groups);
            static std::vector<Letter> by_six_bits(const std::vector<Letter>& bit_groups);

            Letter(const unsigned char init_stored);
            explicit Letter(const std::vector<bool>& init_stored);

            const std::vector<bool>& bits() const;
            unsigned char to_uchar() const;
    };
};

#endif
