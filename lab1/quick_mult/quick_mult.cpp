#include "quick_mult.h"
#include "../fft/fft.h"

#include <memory>
#include <string>
#include <cmath>
#include <numbers>
#include <algorithm>
#include <functional>

namespace
{
using cd = std::complex<double>;

[[maybe_unused]] std::vector<cd> str2vec(const std::string &num, std::uint32_t res_digit_num)
{
    std::vector<cd> out_vect(res_digit_num);
    for (int i = num.size() - 1, j = 0; i >= 0; --i, j++)
    {
        out_vect[j] = num[i] - '0';
    }
    return out_vect;
}

[[maybe_unused]] std::string vec2str(const std::vector<int> &in_vect)
{
    std::string out_num;
    for (int i = in_vect.size() - 1; i >= 0; --i)
    {
        out_num.push_back(in_vect[i] + '0');
    }
    out_num.erase(0, out_num.find_first_not_of('0'));
    return out_num;
}
}

std::string quick_mult_t::multiply([[maybe_unused]] const std::string &num1, [[maybe_unused]] const std::string &num2)
{
    std::uint32_t res_digit_num = 1;
    
    // Calculate digit numbers for mulitiplication result

    // Convert from string to vector 
    //  auto num1_vect = str2vec(num1, res_digit_num);
    //  auto num2_vect = str2vec(num2, res_digit_num);

    // Write main body

    // Convert from vector to string
    // auto res_num = vec2str(mult);

    return std::string('0', res_digit_num);
}
