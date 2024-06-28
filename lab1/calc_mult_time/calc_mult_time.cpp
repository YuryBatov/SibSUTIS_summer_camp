#include "calc_mult_time.h"
#include "../quick_mult/quick_mult.h"
#include "../mult/mult.h"

#include <chrono>
#include <vector>
#include <complex>
#include <cstdint>

template<class T>
int64_t calc_mult_time(std::string num1, std::string num2, T &mult)
{
    auto start = std::chrono::high_resolution_clock::now();
    
    mult.multiply(num1, num2);

    auto stop = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::microseconds>(stop - start);

    return duration.count();
}

template int64_t calc_mult_time<mult_t>(std::string num1, std::string num2, mult_t &mult);
template int64_t calc_mult_time<quick_mult_t>(std::string num1, std::string num2, quick_mult_t &mult);