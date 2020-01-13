
#include <iostream>
#include <chrono>
#include "profile.hpp"

/**
 * @brief Construct a new Profile:: Profile object
 * 
 */
Profile::Profile()
{
}

/**
 * @brief mark in
 * 
 * @param markerMsg 
 */
void Profile::mark(std::string markerMsg)
{
    msg = markerMsg;
    in = microtime();
}

/**
 * @brief mark out caulculate elapse and display msg
 * 
 */
void Profile::elapse()
{
    out = microtime();
    std::cout << "+  Profile " << msg << " : " << out - in << "s" << std::endl;
}

/**
 * @brief time profiler
 * 
 * @return double 
 */
double Profile::microtime()
{
    return (double(
                std::chrono::duration_cast<std::chrono::microseconds>(
                    std::chrono::system_clock::now().time_since_epoch())
                    .count()) /
            double(1000000));
}