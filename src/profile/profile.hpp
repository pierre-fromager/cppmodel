
#ifndef CPPMODEL_PROFILE_HPP
#define CPPMODEL_PROFILE_HPP

#include <string>

class Profile
{

public:
    Profile();
    void mark(std::string msg);
    void elapse();

private:
    double microtime();
    double in;
    double out;
    std::string msg;
};

#endif