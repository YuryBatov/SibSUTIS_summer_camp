#include "quick_mult/quick_mult.h"
#include "calc_mult_time/calc_mult_time.h"
#include "mult/mult.h"

#include <string>
#include <iostream>
#include <random>

std::string gen_random_number(int N)
{
    std::random_device random_device;
    std::mt19937 generator(random_device());
    std::uniform_int_distribution<> distribution(0, 9);

    std::string number;
    for (int i = 0; i < N; i++)
    {
        number.push_back('0' + distribution(generator));
    }
    
    return number;
}

bool compare_results(const std::string &num1, const std::string &num2)
{
    quick_mult_t q_mult;
    mult_t mult;
    
    std::string res_1 = q_mult.multiply(num1, num2);
    std::string res_2 = mult.multiply(num1, num2);

    return (res_1 == res_2);
}

int main()
{
    int N = 3000; 
    
    std::string num1 = gen_random_number(N);
    std::string num2 = gen_random_number(N);
    
    std::cout << "Results are the same: " << std::boolalpha << compare_results(num1, num2) << '\n';

    quick_mult_t q_mult;
    mult_t mult;
    
    int64_t q_mult_time = calc_mult_time<quick_mult_t>(num1, num2, q_mult);
    int64_t mult_time = calc_mult_time<mult_t>(num1, num2, mult);

    std::cout << "Time for quick multiplication:" << q_mult_time << '\n';
    std::cout << "Time for multiplication:" << mult_time << '\n';

    return 0;
}