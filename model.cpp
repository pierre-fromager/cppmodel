
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <sstream>
#include <chrono>
#include <tuple>
#include "model.h"

using namespace std;

/**
 * @brief Construct a new Temperature Liste:: Temperature Liste object
 * 
 */
Liste::Liste()
{
  order = ASC;
  resetAll();
}

/**
 * @brief Destroy the Temperature Liste:: Temperature Liste object
 * 
 */
Liste::~Liste()
{
}

/**
 * @brief set view mode as MAIN or FILTERED
 * 
 * @param mode 
 */
void Liste::setView(Views mode)
{
  view = mode;
}

/**
 * @brief copy filtered items by port to the filtered list
 * 
 * @param portNumber 
 */
void Liste::filterByPort(int portFilter)
{
  filteredList = {};
  std::copy_if(
      itemList.begin(),
      itemList.end(),
      std::back_inserter(filteredList), [portFilter](const Item &i) { return i.port == portFilter; });
}

/**
 * @brief copy filtered items by value to the filtered list
 * 
 * @param portNumber 
 */
void Liste::filterByValue(int valueFilter)
{
  filteredList = {};
  std::copy_if(
      itemList.begin(),
      itemList.end(),
      std::back_inserter(filteredList), [valueFilter](const Item &i) { return i.value == valueFilter; });
}

/**
 * @brief reset lists
 * 
 */
void Liste::resetAll()
{
  itemList = {};
  filteredList = {};
}

/**
 * @brief minimum value
 * 
 * @return int 
 */
int Liste::getMinValue()
{
  const auto min = std::min_element(
      itemList.begin(),
      itemList.end(),
      [](const Item &i1, const Item &i2) {
        return i1.value < i2.value;
      });
  return min->value;
}

/**
 * @brief minimum port
 * 
 * @return int 
 */
int Liste::getMinPort()
{
  const auto min = std::min_element(
      itemList.begin(),
      itemList.end(),
      [](const Item &i1, const Item &i2) {
        return i1.port < i2.port;
      });
  return min->port;
}

/**
 * @brief minimum index
 * 
 * @return int 
 */
int Liste::getMinIndex()
{
  const auto min = std::min_element(
      itemList.begin(),
      itemList.end(),
      [](const Item &i1, const Item &i2) {
        return i1.index < i2.index;
      });
  return min->index;
}

/**
 * @brief maximum value
 * 
 * @return int 
 */
int Liste::getMaxValue()
{
  const auto max = std::max_element(
      itemList.begin(),
      itemList.end(),
      [](const Item &i1, const Item &i2) {
        return i1.value < i2.value;
      });
  return max->value;
}

/**
 * @brief maximum port
 * 
 * @return int 
 */
int Liste::getMaxPort()
{
  const auto max = std::max_element(
      itemList.begin(),
      itemList.end(),
      [](const Item &i1, const Item &i2) {
        return i1.port < i2.port;
      });
  return max->port;
}

/**
 * @brief maximum index
 * 
 * @return int 
 */
int Liste::getMaxIndex()
{
  const auto max = std::max_element(
      itemList.begin(),
      itemList.end(),
      [](const Item &i1, const Item &i2) {
        return i1.index < i2.index;
      });
  return max->index;
}

/**
 * @brief sort list by index
 * 
 */
void Liste::sortByIndex()
{
  const bool isAsc = (order == ASC);
  std::sort(
      itemList.begin(),
      itemList.end(),
      [isAsc](const Item &i1, const Item &i2) {
        return (isAsc) ? (i1.index < i2.index) : (i1.index > i2.index);
      });
}

/**
 * @brief sort by port
 * 
 */
void Liste::sortByPort()
{
  const bool isAsc = (order == ASC);
  std::sort(
      itemList.begin(),
      itemList.end(),
      [isAsc](const Item &i1, const Item &i2) {
        return (isAsc) ? (i1.port < i2.port) : (i1.port > i2.port);
      });
}

/**
 * @brief sort by value
 * 
 */
void Liste::sortByValue()
{
  const bool isAsc = (order == ASC);
  std::sort(
      itemList.begin(),
      itemList.end(),
      [isAsc](const Item &i1, const Item &i2) {
        return (isAsc) ? (i1.value < i2.value) : (i1.value > i2.value);
      });
}

/**
 * @brief multicriterias sort by port and value
 * 
 */
void Liste::sortByPortAndValue()
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
}

/**
 * @brief return the temperature list items
 * 
 * @return VectorItem
 */
VectorItem Liste::items()
{
  return (view == MAIN) ? itemList : filteredList;
}

/**
 * @brief get temperature item at position
 * 
 * @param ix 
 * @return Item 
 */
Item Liste::itemAt(int ix)
{
  const int size = itemList.size();
  if (size > ix)
    ix = size;
  return itemList.at(ix);
}

/**
 * @brief remove a temperature item at position
 * 
 * @param ix 
 * @return true 
 * @return false 
 */
bool Liste::removeAt(const int ix)
{
  if (itemList.size() < ix)
    return false;
  itemList.erase(itemList.begin() + ix);
  return true;
}

/**
 * @brief returns liste size
 * 
 * @return int 
 */
int Liste::getSize()
{
  return itemList.size();
}

/**
 * @brief append a temperature item element at the end
 * 
 * @param item 
 */
void Liste::appendItem(Item item)
{
  itemList.push_back(item);
}

/**
 * @brief set temperature item at position
 * 
 * @param ix 
 * @param item 
 * @return true 
 * @return false 
 */
bool Liste::setItemAt(int ix, Item item)
{
  if (itemList.size() < ix)
    return false;
  itemList[ix] = item;
  //itemList.insert(itemList.begin() + ix, item);
  return true;
}

/**
 * @brief display item at position
 * 
 */
void Liste::displayAt(int ix)
{
  const Item item = items().at(ix);
  std::cout << "-------------------------" << std::endl;
  std::cout << "index " << item.index << std::endl;
  std::cout << "port " << item.port << std::endl;
  std::cout << "timestamp " << item.timestamp << std::endl;
  std::cout << "type " << item.type << std::endl;
  std::cout << "value " << item.value << std::endl;
}

/**
 * @brief display all list items
 * 
 */
void Liste::displayAll()
{
  const int max = items().size();
  for (int ix = 0; ix < max; ix++)
  {
    displayAt(ix);
  }
}

/**
 * @brief set sort Directions
 * 
 * @param dir 
 */
void Liste::setOrder(Directions dir)
{
  order = dir;
}
