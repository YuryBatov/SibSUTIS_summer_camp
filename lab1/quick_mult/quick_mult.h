#pragma once

#include <complex>
#include <memory>
#include <vector>
#include <cstdint>

class quick_mult_t
{
public:
    explicit quick_mult_t() = default;
    ~quick_mult_t() = default;
    quick_mult_t(const quick_mult_t&)            = delete;
    quick_mult_t& operator=(const quick_mult_t&) = delete;

    std::string multiply(const std::string &num1, const std::string &num2);
};
