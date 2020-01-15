
#ifndef CPPMODEL_ITEM_HPP
#define CPPMODEL_ITEM_HPP

#include <string>
#include <vector>

namespace cppmodel
{

    //
    // @brief item structure
    //
    //
    typedef struct
    {
        int index;
        int port;
        std::string timestamp;
        std::string type;
        float value;
    } ItemTemperature;

}
#endif