
#include "profile.hpp"

using namespace cppmodel;

//
// @brief Construct a new Profile:: Profile object
//
//
Profile::Profile():in(0),mem_in({0,0}),mem_out({0,0})
{
}

//
// @brief Construct a new Profile:: Profile object
//
//
Profile::~Profile()
{
}

//
// @brief mark in
//
//@param markerMsg
//
void Profile::mark(std::string markerMsg)
{
    msg = markerMsg;
    in = microtime();
    mem(mem_in);
}

//
// @brief mark out caulculate elapse and display msg
//
//
void Profile::elapse()
{
    const std::string separator = "+-----------------------------";
    const std::string timeUnit = " s";
    const std::string memUnit = " kb";
    mem(mem_out);
    std::cout << terminal::ansi::fg_cyan
              << separator << std::endl
              << terminal::ansi::fg_cyan
              << "| Profile  " << terminal::ansi::bold << msg
              << terminal::ansi::reset
              << std::endl
              << terminal::ansi::fg_cyan;
    std::cout << "| Elapse   : " << microtime() - in << timeUnit
              << std::endl;
    std::cout << "| Mem vm  "
              << " : " << mem_out.vm - mem_in.vm << memUnit
              << std::endl;
    std::cout << "| Mem res "
              << " : " << mem_out.rss - mem_in.rss << memUnit
              << std::endl
              << separator << std::endl << std::endl
              << terminal::ansi::reset;
}

/**
 * @brief snapshot both resident and vm mem usage
 * 
 * @param mark 
 */
void Profile::mem(Mem &mark)
{
    mark.rss = 0.0;
    mark.vm = 0.0;

    unsigned long vsize;
    long rss;
    {
        std::string ignore;
        std::ifstream ifs("/proc/self/stat", std::ios_base::in);
        ifs >> ignore >> ignore >> ignore >> ignore >> ignore >> ignore >> ignore >> ignore >> ignore >> ignore >> ignore >> ignore >> ignore >> ignore >> ignore >> ignore >> ignore >> ignore >> ignore >> ignore >> ignore >> ignore >> vsize >> rss;
    }

    long page_size_kb = sysconf(_SC_PAGE_SIZE) / 1024;
    mark.vm = vsize / 1024.0;
    mark.rss = rss * page_size_kb;
}

//
// @brief time profiler
//
// @return double
//
double Profile::microtime()
{
    return (double(
                std::chrono::duration_cast<std::chrono::microseconds>(
                    std::chrono::system_clock::now().time_since_epoch())
                    .count()) /
            double(1000000));
}