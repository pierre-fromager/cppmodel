
#ifndef CPPMODEL_ITEM_COMPARATOR_HPP
#define CPPMODEL_ITEM_COMPARATOR_HPP

#include <string>
#include <vector>
#include <tuple>
#include "item_temperature.hpp"

namespace cppmodel
{

struct ItemComparator
{
    bool _asc;
    ItemComparator(bool asc) : _asc(asc) {}
};

struct ItemIndexComparator : public ItemComparator
{
    ItemIndexComparator(bool asc) : ItemComparator(asc){};
    bool operator()(const ItemTemperature &i1, const ItemTemperature &i2)
    {
        return (_asc) ? i1.index < i2.index : i1.index > i2.index;
    }
};

struct ItemPortComparator : public ItemComparator
{
    ItemPortComparator(bool asc) : ItemComparator(asc){};
    bool operator()(const ItemTemperature &i1, const ItemTemperature &i2)
    {
        return (_asc) ? i1.port < i2.port : i1.port > i2.port;
    }
};

struct ItemValueComparator : public ItemComparator
{
    ItemValueComparator(bool asc) : ItemComparator(asc){};
    bool operator()(const ItemTemperature &i1, const ItemTemperature &i2)
    {
        return (_asc) ? i1.value < i2.value : i1.value > i2.value;
    }
};

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