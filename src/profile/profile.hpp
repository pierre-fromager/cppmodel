
#ifndef CPPMODEL_PROFILE_HPP
#define CPPMODEL_PROFILE_HPP

#include <string>

namespace cppmodel
{

    struct Mem {
        double vm;
        double rss;
    };

    class Profile
    {

    public:
        Profile();
        void mark(std::string msg);
        void elapse();
        void mem(Mem &mark);

    private:
        double microtime();
        double in;
        Mem mem_in;
        Mem mem_out;
        std::string msg;
    };
}

#endif