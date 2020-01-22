
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <sstream>
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
  _iV.clear();
  _iV.resize(0);
  filteredList.clear();
  filteredList.resize(0);
}

//
// @brief maximum index
//
// @return int
//
int ListeTemperature::getMaxIndex()
{
  const auto max = std::max_element(_iV.begin(), _iV.end(), ItemIndexComparator(true));
  return max->index;
}

//
// @brief minimum value
//
// @return int
//
int ListeTemperature::getMinValue()
{
  const auto min = std::min_element(_iV.begin(), _iV.end(), ItemValueComparator(true));
  return min->value;
}

//
// @brief minimum port
//
// @return int
//
int ListeTemperature::getMinPort()
{
  const auto min = std::min_element(_iV.begin(), _iV.end(), ItemPortComparator(true));
  return min->port;
}

//
// @brief minimum index
//
// @return int
//
int ListeTemperature::getMinIndex()
{
  const auto min = std::min_element(_iV.begin(), _iV.end(), ItemIndexComparator(true));
  return min->index;
}

//
// @brief maximum value
//
// @return int
//
int ListeTemperature::getMaxValue()
{
  const auto max = std::max_element(_iV.begin(), _iV.end(), ItemValueComparator(true));
  return max->value;
}

//
// @brief maximum port
//
// @return int
//
int ListeTemperature::getMaxPort()
{
  const auto max = std::max_element(_iV.begin(), _iV.end(), ItemPortComparator(true));
  return max->port;
}

//
// @brief return the temperature list items
//
// @return VectorItem
//
VectorItem ListeTemperature::items()
{
  return (view == MAIN) ? _iV : filteredList;
}

//
// @brief get temperature item at position
//
// @param ix
// @return ItemTemperature
//
ItemTemperature ListeTemperature::itemAt(unsigned int ix)
{
  const unsigned int size = _iV.size();
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
bool ListeTemperature::removeAt(const unsigned int ix)
{
  if (_iV.size() < ix)
    return false;
  _iV.erase(_iV.begin() + ix);
  return true;
}

//
// @brief returns liste size
//
// @return int
//
int ListeTemperature::getSize()
{
  return _iV.size();
}

//
// @brief append a temperature item element at the end
//
// @param item
//
void ListeTemperature::appendItem(ItemTemperature item)
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
bool ListeTemperature::setItemAt(unsigned int ix, ItemTemperature item)
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
void ListeTemperature::displayAt(unsigned int ix)
{
  const ItemTemperature item = items().at(ix);
  const std::string separator = "-------------------------";

  std::cout << "\t" << separator << std::endl;
  std::cout << "\t"
            << "- index " << item.index << std::endl;
  std::cout << "\t"
            << "- port " << item.port << std::endl;
  std::cout << "\t"
            << "- timestamp " << item.timestamp << std::endl;
  std::cout << "\t"
            << "- type " << item.type << std::endl;
  std::cout << "\t"
            << "- value " << item.value << std::endl;
  std::cout << "\t" << separator << std::endl;
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

  std::sort(_iV.begin(), _iV.end(), ItemIndexComparator(order == ASC));
  return *this;
}

//
// @brief chain method to sort by port
//
//
ListeTemperature &ListeTemperature::sortByPort()
{
  std::sort(_iV.begin(), _iV.end(), ItemPortComparator(order == ASC));
  return *this;
}

//
// @brief chain method to sort by value
//
//
ListeTemperature &ListeTemperature::sortByValue()
{
  std::sort(_iV.begin(), _iV.end(), ItemValueComparator(order == ASC));
  return *this;
}

//
// @brief multicriterias sort by port and value
//
//
ListeTemperature &ListeTemperature::sortByPortAndValue()
{
  std::sort(_iV.begin(), _iV.end(), ItemPortValueComparator(order == ASC));
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
  filteredList.resize(_iV.size());
  std::copy_if(
      _iV.begin(),
      _iV.end(),
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
  filteredList.resize(_iV.size());
  std::copy_if(
      _iV.begin(),
      _iV.end(),
      std::back_inserter(filteredList),
      [valueFilter](const ItemTemperature &i) { return i.value == valueFilter; });
  return *this;
}
