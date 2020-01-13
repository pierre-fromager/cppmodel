
#ifndef CPPMODEL_PROFILE_HPP
#define CPPMODEL_PROFILE_HPP

#include <string>

namespace cppmodel
{
    class Profile
    {

    public:
        Profile();
        void mark(std::string msg);
        void elapse();

    private:
        double microtime();
        double in;
        std::string msg;
    };
}

#endif