
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
        int index;
        int port;
        std::string timestamp;
        std::string type;
        float value;
    };

} // namespace cppmodel
#endif