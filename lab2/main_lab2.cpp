#include <algorithm>
#include <array>
#include <cassert>
#include <cmath>
#include <complex>
#include <cstdint>
#include <iostream>
#include <numeric>
#include <random>
#include <set>
#include <span>
#include <sstream>
#include <vector>

namespace
{
template <class T>
void print_vector(const std::vector<T> &input)
{
    std::cout << "vector: ";
    for (auto el : input)
    {
        std::cout << (int)el << ' ';
    }
    std::cout << '\n';
}

std::vector<uint8_t> serialize(size_t val, size_t output_size)
{
    std::vector<uint8_t> out(output_size, 0);
    for (size_t j_bit{}; j_bit < output_size; ++j_bit)
    {
        out[j_bit] = (val >> j_bit) & 1;
    }
    return out;
}

std::vector<int> bpsk_modulate(std::span<const std::uint8_t> input)
{
    std::vector<int> out(input.begin(), input.end());
    std::transform(out.begin(), out.end(), out.begin(),
                   [](auto a) { return 1 - 2 * a; });
    return out;
}
}  // namespace

class BlockCoder
{
    static constexpr size_t CW_LEN{32};
    static constexpr size_t MAX_PAYLOAD_SIZE{11};
    static constexpr std::array<std::array<std::uint8_t, MAX_PAYLOAD_SIZE>,
                                CW_LEN>
        G_GEN{{{1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 1},
               {1, 1, 1, 0, 0, 0, 0, 0, 0, 1, 1},
               {1, 0, 0, 1, 0, 0, 1, 0, 1, 1, 1},
               {1, 0, 1, 1, 0, 0, 0, 0, 1, 0, 1},
               {1, 1, 1, 1, 0, 0, 0, 1, 0, 0, 1},
               {1, 1, 0, 0, 1, 0, 1, 1, 1, 0, 1},
               {1, 0, 1, 0, 1, 0, 1, 0, 1, 1, 1},
               {1, 0, 0, 1, 1, 0, 0, 1, 1, 0, 1},
               {1, 1, 0, 1, 1, 0, 0, 1, 0, 1, 1},
               {1, 0, 1, 1, 1, 0, 1, 0, 0, 1, 1},
               {1, 0, 1, 0, 0, 1, 1, 1, 0, 1, 1},
               {1, 1, 1, 0, 0, 1, 1, 0, 1, 0, 1},
               {1, 0, 0, 1, 0, 1, 0, 1, 1, 1, 1},
               {1, 1, 0, 1, 0, 1, 0, 1, 0, 1, 1},
               {1, 0, 0, 0, 1, 1, 0, 1, 0, 0, 1},
               {1, 1, 0, 0, 1, 1, 1, 1, 0, 1, 1},
               {1, 1, 1, 0, 1, 1, 1, 0, 0, 1, 0},
               {1, 0, 0, 1, 1, 1, 0, 0, 1, 0, 0},
               {1, 1, 0, 1, 1, 1, 1, 1, 0, 0, 0},
               {1, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0},
               {1, 0, 1, 0, 0, 0, 1, 0, 0, 0, 1},
               {1, 1, 0, 1, 0, 0, 0, 0, 0, 1, 1},
               {1, 0, 0, 0, 1, 0, 0, 1, 1, 0, 1},
               {1, 1, 1, 0, 1, 0, 0, 0, 1, 1, 1},
               {1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 0},
               {1, 1, 0, 0, 0, 1, 1, 1, 0, 0, 1},
               {1, 0, 1, 1, 0, 1, 0, 0, 1, 1, 0},
               {1, 1, 1, 1, 0, 1, 0, 1, 1, 1, 0},
               {1, 0, 1, 0, 1, 1, 1, 0, 1, 0, 0},
               {1, 0, 1, 1, 1, 1, 1, 1, 1, 0, 0},
               {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
               {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}}};

    size_t num_bits_to_decode_{};

    // Codewords
    std::vector<std::vector<int>> parity_bits_per_cw_;

   public:
    BlockCoder(size_t num_bits_to_decode = 0)
        : num_bits_to_decode_{num_bits_to_decode}
    {
        assert(num_bits_to_decode_ <= MAX_PAYLOAD_SIZE);
        gen_parity_matrix();
    };

    std::vector<std::uint8_t> code(std::span<const std::uint8_t> input)
    {
        std::vector<std::uint8_t> out(CW_LEN);
        // !!! Write your code here !!!
        return out;
    }

    void gen_parity_matrix()
    {
        // Bits for forming codewords
        std::vector<std::uint8_t> msg_bits(num_bits_to_decode_, 0);
        // Number of codewords
        const size_t num_cw = (size_t)std::exp2(num_bits_to_decode_);
        parity_bits_per_cw_.resize(num_cw, std::vector<int>(CW_LEN));
        // !!! Write your code here !!!
    }

    std::vector<std::uint8_t> decode(std::span<const int> input)
    {
        size_t max_corr_cw_idx = 0;
        int max_corr = 0;
        // size_t num_cw = (size_t)std::exp2(num_bits_to_decode_);

        // !!! Write your code here !!!

        auto dec_bits = serialize(max_corr_cw_idx, num_bits_to_decode_);
        return dec_bits;
    };

    std::vector<int> random_err(std::span<const int> input, size_t num_of_errs)
    {
        std::vector<int> out(input.begin(), input.end());
        std::set<int> indxs;
        while (indxs.size() < num_of_errs)
        {
            indxs.insert(rand() % CW_LEN);
        }
        for (auto it = indxs.begin(); it != indxs.end(); ++it)
        {
            out[*it] = -out[*it];
        }
        return out;
    }

    int find_min_dist()
    {
        int dist = CW_LEN;
        // !!! Write your code here !!!

        return dist;
    }

    ~BlockCoder() = default;
};

int main()
{
    // input_size: [1 ... 11]
    const int input_size = 5;
    const int max_val = (int)std::exp2(input_size);
    // Generate random input vector
    const auto input = serialize(rand() % max_val, input_size);
    print_vector(input);
    auto Coder = BlockCoder(input_size);

    // !!! Write your code here !!!

    return 0;
}