
#ifndef CPPMODEL_LISTE_GENERIC_TEMPLATE_HPP
#define CPPMODEL_LISTE_GENERIC_TEMPLATE_HPP

#include <string>
#include <vector>
#include <algorithm>
//#include <sstream>
#include <iostream>
#include <tuple>
#include <functional>

namespace cppmodel
{

//
// @brief ListeTemplate Class
//
//
template <typename Item, typename VectorItem = std::vector<Item>>
class ListeTemplate
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
    ListeTemplate();
    ~ListeTemplate();
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
    ListeTemplate &setView(Views mode);
    ListeTemplate &setOrder(Directions direction);
    ListeTemplate &setSortComparator(
        std::function<bool(Item i1, Item i2)> comparator);
    ListeTemplate &sortByComparator();
    ListeTemplate &filterByPort(int portFilter);
    ListeTemplate &filterByValue(int valueFilter);

private:
    std::function<bool(Item, Item)> sortComparator;
    //std::function<bool(Item i1, Item i2) &filterComparator();
    Directions order;
    Views view;
    VectorItem itemList;
    VectorItem filteredList;
};

//
// @brief Construct a new ListeTemplate of temperature items
//
//
template <typename Item, typename VectorItem>
ListeTemplate<Item, VectorItem>::ListeTemplate()
{
    order = ASC;
    resetAll();
}

//
// @brief Destroy the Temperature ListeTemplate
//
//
template <typename Item, typename VectorItem>
ListeTemplate<Item, VectorItem>::~ListeTemplate()
{
    resetAll();
}

//
// @brief reset lists
//
//
template <typename Item, typename VectorItem>
void ListeTemplate<Item, VectorItem>::resetAll()
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
int ListeTemplate<Item, VectorItem>::getMinValue()
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
int ListeTemplate<Item, VectorItem>::getMinPort()
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
int ListeTemplate<Item, VectorItem>::getMinIndex()
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
int ListeTemplate<Item, VectorItem>::getMaxValue()
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
int ListeTemplate<Item, VectorItem>::getMaxPort()
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
int ListeTemplate<Item, VectorItem>::getMaxIndex()
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
VectorItem ListeTemplate<Item, VectorItem>::items()
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
Item ListeTemplate<Item, VectorItem>::itemAt(int ix)
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
bool ListeTemplate<Item, VectorItem>::removeAt(const int ix)
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
void ListeTemplate<Item, VectorItem>::pop()
{
    if (itemList.empty())
    {
        throw std::out_of_range("ListeTemplate<>::pop(): empty stack");
    }
    itemList.pop_back();
}

//
// @brief returns liste size
//
// @return int
//
template <typename Item, typename VectorItem>
int ListeTemplate<Item, VectorItem>::getSize()
{
    return itemList.size();
}

//
// @brief append a temperature item element at the end
//
// @param item
//
template <typename Item, typename VectorItem>
void ListeTemplate<Item, VectorItem>::appendItem(Item item)
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
bool ListeTemplate<Item, VectorItem>::setItemAt(int ix, Item item)
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
void ListeTemplate<Item, VectorItem>::displayAt(int ix)
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
void ListeTemplate<Item, VectorItem>::displayAll()
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
ListeTemplate<Item, VectorItem> &ListeTemplate<Item, VectorItem>::setOrder(Directions dir)
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
ListeTemplate<Item, VectorItem> &ListeTemplate<Item, VectorItem>::setView(Views mode)
{
    view = mode;
    return *this;
}

//
// @brief sort by lambda comparator
//
// @tparam Item
// @tparam VectorItem
// @return ListeTemplate<Item, VectorItem>&
//
template <typename Item, typename VectorItem>
ListeTemplate<Item, VectorItem> &ListeTemplate<Item, VectorItem>::sortByComparator()
{
    std::sort(itemList.begin(), itemList.end(), sortComparator);
    return *this;
}

//
// @brief set lambda comparator
//
// @tparam Item
// @tparam VectorItem
// @param comparator
// @return ListeTemplate<Item, VectorItem>&
//
template <typename Item, typename VectorItem>
ListeTemplate<Item, VectorItem> &ListeTemplate<Item, VectorItem>::setSortComparator(
    std::function<bool(Item i1, Item i2)> comparator)
{
    sortComparator = comparator;
    return *this;
}

//
// @brief copy filtered items by port to the filtered list
//
// @param portNumber
//
template <typename Item, typename VectorItem>
ListeTemplate<Item, VectorItem> &ListeTemplate<Item, VectorItem>::filterByPort(int portFilter)
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
ListeTemplate<Item, VectorItem> &ListeTemplate<Item, VectorItem>::filterByValue(int valueFilter)
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