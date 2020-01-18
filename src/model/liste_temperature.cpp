
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <sstream>
#include <chrono>
#include <tuple>
#include "liste_temperature.hpp"

using namespace cppmodel;

//
// @brief Construct a new Liste of temperature items
//
//
ListeTemperature::ListeTemperature()
{
  order = ASC;
  view = MAIN;
  resetAll();
}

//
// @brief Destroy the Temperature Liste
//
//
ListeTemperature::~ListeTemperature()
{
  resetAll();
}

//
// @brief reset lists
//
//
void ListeTemperature::resetAll()
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
int ListeTemperature::getMinValue()
{
  const auto min = std::min_element(
      itemList.begin(),
      itemList.end(),
      [](const ItemTemperature &i1, const ItemTemperature &i2) {
        return i1.value < i2.value;
      });
  return min->value;
}

//
// @brief minimum port
//
// @return int
//
int ListeTemperature::getMinPort()
{
  const auto min = std::min_element(
      itemList.begin(),
      itemList.end(),
      [](const ItemTemperature &i1, const ItemTemperature &i2) {
        return i1.port < i2.port;
      });
  return min->port;
}

//
// @brief minimum index
//
// @return int
//
int ListeTemperature::getMinIndex()
{
  const auto min = std::min_element(
      itemList.begin(),
      itemList.end(),
      [](const ItemTemperature &i1, const ItemTemperature &i2) {
        return i1.index < i2.index;
      });
  return min->index;
}

//
// @brief maximum value
//
// @return int
//
int ListeTemperature::getMaxValue()
{
  const auto max = std::max_element(
      itemList.begin(),
      itemList.end(),
      [](const ItemTemperature &i1, const ItemTemperature &i2) {
        return i1.value < i2.value;
      });
  return max->value;
}

//
// @brief maximum port
//
// @return int
//
int ListeTemperature::getMaxPort()
{
  const auto max = std::max_element(
      itemList.begin(),
      itemList.end(),
      [](const ItemTemperature &i1, const ItemTemperature &i2) {
        return i1.port < i2.port;
      });
  return max->port;
}

//
// @brief maximum index
//
// @return int
//
int ListeTemperature::getMaxIndex()
{
  const auto max = std::max_element(
      itemList.begin(),
      itemList.end(),
      [](const ItemTemperature &i1, const ItemTemperature &i2) {
        return i1.index < i2.index;
      });
  return max->index;
}

//
// @brief return the temperature list items
//
// @return VectorItem
//
VectorItem ListeTemperature::items()
{
  return (view == MAIN) ? itemList : filteredList;
}

//
// @brief get temperature item at position
//
// @param ix
// @return ItemTemperature
//
ItemTemperature ListeTemperature::itemAt(unsigned int ix)
{
  const unsigned int size = itemList.size();
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
bool ListeTemperature::removeAt(const unsigned int ix)
{
  if (itemList.size() < ix)
    return false;
  itemList.erase(itemList.begin() + ix);
  return true;
}

//
// @brief returns liste size
//
// @return int
//
int ListeTemperature::getSize()
{
  return itemList.size();
}

//
// @brief append a temperature item element at the end
//
// @param item
//
void ListeTemperature::appendItem(ItemTemperature item)
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
bool ListeTemperature::setItemAt(unsigned int ix, ItemTemperature item)
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
void ListeTemperature::displayAt(unsigned int ix)
{
  const ItemTemperature item = items().at(ix);
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
void ListeTemperature::displayAll()
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
ListeTemperature &ListeTemperature::setOrder(Directions dir)
{
  order = dir;
  return *this;
}

//
// @brief chain method to set view mode as MAIN or FILTERED
//
// @param mode
//
ListeTemperature &ListeTemperature::setView(Views mode)
{
  view = mode;
  return *this;
}

//
// @brief chain method to sort list by index
//
//
ListeTemperature &ListeTemperature::sortByIndex()
{
  const bool isAsc = (order == ASC);
  std::sort(
      itemList.begin(),
      itemList.end(),
      [isAsc](const ItemTemperature &i1, const ItemTemperature &i2) {
        return (isAsc) ? (i1.index < i2.index) : (i1.index > i2.index);
      });
  return *this;
}

//
// @brief chain method to sort by port
//
//
ListeTemperature &ListeTemperature::sortByPort()
{
  const bool isAsc = (order == ASC);
  std::sort(
      itemList.begin(),
      itemList.end(),
      [isAsc](const ItemTemperature &i1, const ItemTemperature &i2) {
        return (isAsc) ? (i1.port < i2.port) : (i1.port > i2.port);
      });
  return *this;
}

//
// @brief chain method to sort by value
//
//
ListeTemperature &ListeTemperature::sortByValue()
{
  const bool isAsc = (order == ASC);
  std::sort(
      itemList.begin(),
      itemList.end(),
      [isAsc](const ItemTemperature &i1, const ItemTemperature &i2) {
        return (isAsc) ? (i1.value < i2.value) : (i1.value > i2.value);
      });
  return *this;
}

//
// @brief multicriterias sort by port and value
//
//
ListeTemperature &ListeTemperature::sortByPortAndValue()
{
  const bool isAsc = (order == ASC);
  std::sort(
      itemList.begin(),
      itemList.end(),
      [isAsc](const ItemTemperature &i1, const ItemTemperature &i2) {
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
ListeTemperature &ListeTemperature::filterByPort(int portFilter)
{
  filteredList.clear();
  filteredList.resize(itemList.size());
  std::copy_if(
      itemList.begin(),
      itemList.end(),
      std::back_inserter(filteredList),
      [portFilter](const ItemTemperature &i) { return i.port == portFilter; });
  return *this;
}

//
// @brief copy filtered items by value to the filtered list
//
// @param valueFilter
//
ListeTemperature &ListeTemperature::filterByValue(int valueFilter)
{
  filteredList.clear();
  filteredList.resize(itemList.size());
  std::copy_if(
      itemList.begin(),
      itemList.end(),
      std::back_inserter(filteredList),
      [valueFilter](const ItemTemperature &i) { return i.value == valueFilter; });
  return *this;
}
