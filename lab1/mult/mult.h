#pragma once

#include <complex>
#include <memory>
#include <vector>

class mult_t
{
public:
    explicit mult_t() = default;
    ~mult_t() = default;
    mult_t(const mult_t&)            = delete;
    mult_t& operator=(const mult_t&) = delete;

    std::string multiply(const std::string &num1, const std::string &num2);
};
