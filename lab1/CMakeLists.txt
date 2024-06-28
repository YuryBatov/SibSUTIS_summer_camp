cmake_minimum_required(VERSION 3.4...3.18)
project(quick_mult LANGUAGES CXX)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_FLAGS_RELEASE "-Wall -Wextra -Werror -Wpedantic -O3")
set(CMAKE_CXX_FLAGS_RELWITHDEBINFO "-Wall -Wextra -Werror -Wpedantic -g -O3")
set(CMAKE_CXX_FLAGS_DEBUG "-Wall -Wextra -Werror -Wpedantic -g -O0")

set(SRC_LIST quick_mult/quick_mult.cpp
             quick_mult/quick_mult.h
             mult/mult.cpp
             mult/mult.h
             calc_mult_time/calc_mult_time.cpp
             calc_mult_time/calc_mult_time.h
             fft/fft.cpp
             fft/fft.h
             test_mult.cpp)

add_executable(test_mult ${SRC_LIST})
