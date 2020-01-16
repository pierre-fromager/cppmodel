
#ifndef CPPMODEL_LISTE_HPP
#define CPPMODEL_LISTE_HPP

#include <string>
#include <vector>
#include <algorithm>
//#include <sstream>
#include <iostream>
#include <tuple>

namespace cppmodel
{

//
// @brief Liste Class
//
//
template <typename Item, typename VectorItem = std::vector<Item>>
class Liste
{

public:
    enum Directions
    {
        ASC,
        DESC
    };
    enum Views
    {
        MAIN,
        FILTERED
    };
    Liste();
    ~Liste();
    VectorItem items();
    Item itemAt(int ix);
    void resetAll();
    bool removeAt(int ix);
    void pop();
    void appendItem(Item item);
    bool setItemAt(int ix, Item item);
    int getSize();
    int getMinValue();
    int getMinPort();
    int getMinIndex();
    int getMaxValue();
    int getMaxPort();
    int getMaxIndex();
    void displayAt(int ix);
    void displayAll();
    Liste &setView(Views mode);
    Liste &setOrder(Directions direction);
    Liste &sortBy(const std::string name);
    Liste &sortByIndex();
    Liste &sortByPort();
    Liste &sortByValue();
    Liste &sortByPortAndValue();
    Liste &filterByPort(int portFilter);
    Liste &filterByValue(int valueFilter);

private:
    Directions order;
    Views view;
    VectorItem itemList;
    VectorItem filteredList;
};

//
// @brief Construct a new Liste of temperature items
//
//
template <typename Item, typename VectorItem>
Liste<Item, VectorItem>::Liste()
{
    order = ASC;
    resetAll();
}

//
// @brief Destroy the Temperature Liste
//
//
template <typename Item, typename VectorItem>
Liste<Item, VectorItem>::~Liste()
{
    resetAll();
}

//
// @brief reset lists
//
//
template <typename Item, typename VectorItem>
void Liste<Item, VectorItem>::resetAll()
{
    itemList.clear();
    itemList.resize(0);
    filteredList.clear();
    filteredList.resize(0);
}

//
// @brief minimum value
//
// @return int
//
template <typename Item, typename VectorItem>
int Liste<Item, VectorItem>::getMinValue()
{
    const auto min = std::min_element(
        itemList.begin(),
        itemList.end(),
        [](const Item &i1, const Item &i2) {
            return i1.value < i2.value;
        });
    return min->value;
}

//
// @brief minimum port
//
// @return int
//
template <typename Item, typename VectorItem>
int Liste<Item, VectorItem>::getMinPort()
{
    const auto min = std::min_element(
        itemList.begin(),
        itemList.end(),
        [](const Item &i1, const Item &i2) {
            return i1.port < i2.port;
        });
    return min->port;
}

//
// @brief minimum index
//
// @return int
//
template <typename Item, typename VectorItem>
int Liste<Item, VectorItem>::getMinIndex()
{
    const auto min = std::min_element(
        itemList.begin(),
        itemList.end(),
        [](const Item &i1, const Item &i2) {
            return i1.index < i2.index;
        });
    return min->index;
}

//
// @brief maximum value
//
// @return int
//
template <typename Item, typename VectorItem>
int Liste<Item, VectorItem>::getMaxValue()
{
    const auto max = std::max_element(
        itemList.begin(),
        itemList.end(),
        [](const Item &i1, const Item &i2) {
            return i1.value < i2.value;
        });
    return max->value;
}

//
// @brief maximum port
//
// @return int
//
template <typename Item, typename VectorItem>
int Liste<Item, VectorItem>::getMaxPort()
{
    const auto max = std::max_element(
        itemList.begin(),
        itemList.end(),
        [](const Item &i1, const Item &i2) {
            return i1.port < i2.port;
        });
    return max->port;
}

//
// @brief maximum index
//
// @return int
//
template <typename Item, typename VectorItem>
int Liste<Item, VectorItem>::getMaxIndex()
{
    const auto max = std::max_element(
        itemList.begin(),
        itemList.end(),
        [](const Item &i1, const Item &i2) {
            return i1.index < i2.index;
        });
    return max->index;
}

//
// @brief return the temperature list items
//
// @return VectorItem
//
template <typename Item, typename VectorItem>
VectorItem Liste<Item, VectorItem>::items()
{
    return (view == MAIN) ? itemList : filteredList;
}

//
// @brief get temperature item at position
//
// @param ix
// @return Item
//
template <typename Item, typename VectorItem>
Item Liste<Item, VectorItem>::itemAt(int ix)
{
    const int size = itemList.size();
    if (size > ix)
        ix = size;
    return itemList.at(ix);
}

//
// @brief remove a temperature item at position
//
// @param ix
// @return true
// @return false
//
template <typename Item, typename VectorItem>
bool Liste<Item, VectorItem>::removeAt(const int ix)
{
    if (itemList.size() < ix)
        return false;
    itemList.erase(itemList.begin() + ix);
    return true;
}

//
// @brief remove last element
//
// @tparam Item
// @tparam VectorItem
//
template <typename Item, typename VectorItem>
void Liste<Item, VectorItem>::pop()
{
    if (itemList.empty())
    {
        throw std::out_of_range("Liste<>::pop(): empty stack");
    }
    itemList.pop_back();
}

//
// @brief returns liste size
//
// @return int
//
template <typename Item, typename VectorItem>
int Liste<Item, VectorItem>::getSize()
{
    return itemList.size();
}

//
// @brief append a temperature item element at the end
//
// @param item
//
template <typename Item, typename VectorItem>
void Liste<Item, VectorItem>::appendItem(Item item)
{
    itemList.push_back(item);
}

//
// @brief set temperature item at position
//
// @param ix
// @param item
// @return true
// @return false
//
template <typename Item, typename VectorItem>
bool Liste<Item, VectorItem>::setItemAt(int ix, Item item)
{
    if (itemList.size() < ix)
    {
        return false;
    }
    itemList[ix] = item;
    //itemList.insert(itemList.begin() + ix, item);
    return true;
}

//
// @brief display item at position
//
//
template <typename Item, typename VectorItem>
void Liste<Item, VectorItem>::displayAt(int ix)
{
    const Item item = items().at(ix);
    const std::string separator = "-------------------------";
    std::cout << separator << std::endl;
    std::cout << "- index " << item.index << std::endl;
    std::cout << "- port " << item.port << std::endl;
    std::cout << "- timestamp " << item.timestamp << std::endl;
    std::cout << "- type " << item.type << std::endl;
    std::cout << "- value " << item.value << std::endl;
    std::cout << separator << std::endl;
    std::cout << std::endl;
}

//
// @brief display all list items
//
//
template <typename Item, typename VectorItem>
void Liste<Item, VectorItem>::displayAll()
{
    const int max = items().size();
    for (int ix = 0; ix < max; ix++)
    {
        displayAt(ix);
    }
}

//
// @brief set sort Directions
//
// @param dir
//
template <typename Item, typename VectorItem>
Liste<Item, VectorItem> &Liste<Item, VectorItem>::setOrder(Directions dir)
{
    order = dir;
    return *this;
}

//
// @brief chain method to set view mode as MAIN or FILTERED
//
// @param mode
//
template <typename Item, typename VectorItem>
Liste<Item, VectorItem> &Liste<Item, VectorItem>::setView(Views mode)
{
    view = mode;
    return *this;
}

//
// @brief chain method to sort list by a name prop
//
//
template <typename Item, typename VectorItem>
Liste<Item, VectorItem> &Liste<Item, VectorItem>::sortBy(std::string name)
{
    const bool isAsc = (order == ASC);
    const std::string prop = name;
    
    std::sort(
        itemList.begin(),
        itemList.end(),
        [isAsc, prop]( Item &i1,  Item &i2) {
            //int ptrProp = Item::*p;
            //p = &Item::prop;
            //int* ptrToC2 =  &(i2->prop);
            return (isAsc) ? (i1.index < i2.index) : (i1.index > i2.index);
            //return (isAsc) ? (i1->*p < i2->*p) : (i1->*p > i2->*p);
        });
    return *this;
}

//
// @brief chain method to sort list by index
//
//
template <typename Item, typename VectorItem>
Liste<Item, VectorItem> &Liste<Item, VectorItem>::sortByIndex()
{
    const bool isAsc = (order == ASC);
    std::sort(
        itemList.begin(),
        itemList.end(),
        [isAsc](const Item &i1, const Item &i2) {
            return (isAsc) ? (i1.index < i2.index) : (i1.index > i2.index);
        });
    return *this;
}

//
// @brief chain method to sort by port
//
//
template <typename Item, typename VectorItem>
Liste<Item, VectorItem> &Liste<Item, VectorItem>::sortByPort()
{
    const bool isAsc = (order == ASC);
    std::sort(
        itemList.begin(),
        itemList.end(),
        [isAsc](const Item &i1, const Item &i2) {
            return (isAsc) ? (i1.port < i2.port) : (i1.port > i2.port);
        });
    return *this;
}

//
// @brief chain method to sort by value
//
//
template <typename Item, typename VectorItem>
Liste<Item, VectorItem> &Liste<Item, VectorItem>::sortByValue()
{
    const bool isAsc = (order == ASC);
    std::sort(
        itemList.begin(),
        itemList.end(),
        [isAsc](const Item &i1, const Item &i2) {
            return (isAsc) ? (i1.value < i2.value) : (i1.value > i2.value);
        });
    return *this;
}

//
// @brief multicriterias sort by port and value
//
//
template <typename Item, typename VectorItem>
Liste<Item, VectorItem> &Liste<Item, VectorItem>::sortByPortAndValue()
{
    const bool isAsc = (order == ASC);
    std::sort(
        itemList.begin(),
        itemList.end(),
        [isAsc](const Item &i1, const Item &i2) {
            return (isAsc)
                       ? std::tie(i1.port, i1.value) < std::tie(i2.port, i2.value)
                       : std::tie(i1.port, i1.value) > std::tie(i2.port, i2.value);
        });
    return *this;
}

//
// @brief copy filtered items by port to the filtered list
//
// @param portNumber
//
template <typename Item, typename VectorItem>
Liste<Item, VectorItem> &Liste<Item, VectorItem>::filterByPort(int portFilter)
{
    filteredList.clear();
    filteredList.resize(itemList.size());
    std::copy_if(
        itemList.begin(),
        itemList.end(),
        std::back_inserter(filteredList),
        [portFilter](const Item &i) { return i.port == portFilter; });
    return *this;
}

//
// @brief copy filtered items by value to the filtered list
//
// @param valueFilter
//
template <typename Item, typename VectorItem>
Liste<Item, VectorItem> &Liste<Item, VectorItem>::filterByValue(int valueFilter)
{
    filteredList.clear();
    filteredList.resize(itemList.size());
    std::copy_if(
        itemList.begin(),
        itemList.end(),
        std::back_inserter(filteredList),
        [valueFilter](const Item &i) { return i.value == valueFilter; });
    return *this;
}

} // namespace cppmodel
#endif