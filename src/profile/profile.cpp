
#include "profile.hpp"

using namespace cppmodel;

//
// @brief Construct a new Profile:: Profile object
//
//
Profile::Profile()
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
    mem(mem_out);
    std::cout << terminal::ansi::fg_white
              << "+  Profile " << msg << " : " << microtime() - in
              << "s" << terminal::ansi::reset << std::endl;
    std::cout << terminal::ansi::fg_cyan
              << "+  Profile mem vm  "
              << msg << " : " << mem_out.vm - mem_in.vm << "kb"
              << terminal::ansi::reset << std::endl;
    std::cout << terminal::ansi::fg_yellow
              << "+  Profile mem res "
              << msg << " : " << mem_out.rss - mem_in.rss << "kb"
              << terminal::ansi::reset << std::endl;
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