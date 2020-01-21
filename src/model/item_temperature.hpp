
#ifndef CPPMODEL_ITEM_TEMPERATURE_HPP
#define CPPMODEL_ITEM_TEMPERATURE_HPP

#include <string>
#include <vector>
#include <iostream>

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
    int value;
    friend std::ostream &operator<<(std::ostream &os, const ItemTemperature &item)
    {
        const std::string sep = ";";
        os << item.index
           << sep << item.port
           << sep << item.timestamp
           << sep << item.type
           << sep << item.value;
        return os;
    };
};

}; // namespace cppmodel

#endif