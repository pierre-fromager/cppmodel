
#ifndef CPPMODEL_ITEM_TEMPERATURE_HPP
#define CPPMODEL_ITEM_TEMPERATURE_HPP

#include <string>
#include <vector>

namespace cppmodel
{

    //
    // @brief item structure
    //
    //
    struct ItemTemperature
    {
        unsigned int index;
        unsigned int port;
        std::string timestamp;
        std::string type;
        unsigned int value;
    };

} // namespace cppmodel
#endif