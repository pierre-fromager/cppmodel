
#ifndef CPPMODEL_LISTE_GENERIC_TEMPLATE_HPP
#define CPPMODEL_LISTE_GENERIC_TEMPLATE_HPP

#include <string>
#include <vector>
#include <algorithm>
#include <functional>
#include <thread>

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
    auto getMin();
    auto getMax();
    void displayAt(int ix);
    void displayAll();
    ListeTemplate &setView(Views mode);
    ListeTemplate &setOrder(Directions direction);
    ListeTemplate &setSortComparator(const std::function<bool(const Item &i1, const Item &i2)> &comparator);
    ListeTemplate &sortByComparator();
    ListeTemplate &filterByPort(int portFilter);
    ListeTemplate &filterByValue(int valueFilter);

private:
    std::function<bool(Item, Item)> sortComparator;
    //std::function<bool(Item i1, Item i2) &filterComparator();
    Directions order;
    Views view;
    VectorItem _iV;  // MAIN STACK
    VectorItem _iVf; // FILTERED STACK
};

//
// @brief Construct a new ListeTemplate of temperature items
//
//
template <typename Item, typename VectorItem>
ListeTemplate<Item, VectorItem>::ListeTemplate()
{
    order = ASC;
    view = MAIN;
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
    _iV.clear();
    _iV.resize(0);
    _iVf.clear();
    _iVf.resize(0);
}

//
// @brief get min by sort compare lambda
//
// @return auto
//
template <typename Item, typename VectorItem>
auto ListeTemplate<Item, VectorItem>::getMin()
{
    return std::min_element(_iV.begin(), _iV.end(), sortComparator);
}

//
// @brief get max by sort compare lambda
//
// @return auto
//
template <typename Item, typename VectorItem>
auto ListeTemplate<Item, VectorItem>::getMax()
{
    return std::max_element(_iV.begin(), _iV.end(), sortComparator);
}

//
// @brief return the temperature list items
//
// @return VectorItem
//
template <typename Item, typename VectorItem>
VectorItem ListeTemplate<Item, VectorItem>::items()
{
    return (view == MAIN) ? _iV : _iVf;
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
    const int size = _iV.size();
    if (size > ix)
        ix = size;
    return _iV.at(ix);
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
    if (_iV.size() < ix)
        return false;
    _iV.erase(_iV.begin() + ix);
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
    if (_iV.empty())
    {
        throw std::out_of_range("ListeTemplate<>::pop(): empty stack");
    }
    _iV.pop_back();
}

//
// @brief returns liste size
//
// @return int
//
template <typename Item, typename VectorItem>
int ListeTemplate<Item, VectorItem>::getSize()
{
    return _iV.size();
}

//
// @brief append a temperature item element at the end
//
// @param item
//
template <typename Item, typename VectorItem>
void ListeTemplate<Item, VectorItem>::appendItem(Item item)
{
    _iV.push_back(item);
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
    if (_iV.size() < ix)
    {
        return false;
    }
    _iV[ix] = item;
    //_iV.insert(_iV.begin() + ix, item);
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
    std::sort(_iV.begin(), _iV.end(), sortComparator);
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
    const std::function<bool(const Item &i1, const Item &i2)> &comparator)
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
    _iVf.clear();
    _iVf.resize(_iV.size());
    std::copy_if(
        _iV.begin(),
        _iV.end(),
        std::back_inserter(_iVf),
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
    _iVf.clear();
    _iVf.resize(_iV.size());
    std::copy_if(
        _iV.begin(),
        _iV.end(),
        std::back_inserter(_iVf),
        [valueFilter](const Item &i) { return i.value == valueFilter; });
    return *this;
}

} // namespace cppmodel
#endif