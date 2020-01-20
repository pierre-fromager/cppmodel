
#ifndef CPPMODEL_ITEM_COMPARATOR_HPP
#define CPPMODEL_ITEM_COMPARATOR_HPP

#include <string>
#include <vector>
#include <tuple>
#include "item_temperature.hpp"

namespace cppmodel
{

/**
 * @brief init sort order comparator
 * 
 */
struct ItemComparator
{
    bool _asc;
    ItemComparator(bool asc) : _asc(asc) {}
};

/**
 * @brief compare by index
 * 
 */
struct ItemIndexComparator : public ItemComparator
{
    ItemIndexComparator(bool asc) : ItemComparator(asc){};
    bool operator()(const ItemTemperature &i1, const ItemTemperature &i2)
    {
        return (_asc) ? i1.index < i2.index : i1.index > i2.index;
    }
};

/**
 * @brief compare by port
 * 
 */
struct ItemPortComparator : public ItemComparator
{
    ItemPortComparator(bool asc) : ItemComparator(asc){};
    bool operator()(const ItemTemperature &i1, const ItemTemperature &i2)
    {
        return (_asc) ? i1.port < i2.port : i1.port > i2.port;
    }
};

/**
 * @brief compare by value
 * 
 */
struct ItemValueComparator : public ItemComparator
{
    ItemValueComparator(bool asc) : ItemComparator(asc){};
    bool operator()(const ItemTemperature &i1, const ItemTemperature &i2)
    {
        return (_asc) ? i1.value < i2.value : i1.value > i2.value;
    }
};

/**
 * @brief compare by port and value
 * 
 */
struct ItemPortValueComparator : public ItemComparator
{
    ItemPortValueComparator(bool asc) : ItemComparator(asc){};
    bool operator()(const ItemTemperature &i1, const ItemTemperature &i2)
    {
        return (_asc)
                   ? std::tie(i1.port, i1.value) < std::tie(i2.port, i2.value)
                   : std::tie(i1.port, i1.value) > std::tie(i2.port, i2.value);
    }
};

}; // namespace cppmodel

#endif