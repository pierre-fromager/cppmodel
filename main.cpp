
#include <chrono>
#include "model.h"

using namespace std;

/**
 * @brief time profiler
 * 
 * @return double 
 */
double microtime()
{
  return (double(std::chrono::duration_cast<std::chrono::microseconds>(std::chrono::system_clock::now().time_since_epoch()).count()) / double(1000000));
}

/**
 * @brief illustrate list manipulation as min max sort
 * g++ -g -std=c++11 -o testptr test-ptr.cpp
 * 
 * @return int 
 */
int main()
{
  Liste list;
  Item item;
  std::cout << "**** start generation" << std::endl;
  int itemAmount = 1000000;
  double profGen = microtime();
  for (int i = 0; i < itemAmount; i++)
  {
    item.index = i;
    item.port = i % 4; // 0..4
    item.timestamp = "2020-01-0" + to_string(i % 30);
    item.type = "temperature";
    item.value = rand() % 100; // 0..100
    list.appendItem(item);
  }
  std::cout << "++++ Profile generation : " << microtime() - profGen << "s" << std::endl;
  std::cout << "Liste size : " << list.getSize() << std::endl;
  item.index = 1000;
  item.value = 0;
  item.timestamp = "3020-20-20";
  list.appendItem(item);
  std::cout << "**** after append" << std::endl;
  std::cout << "Liste size : " << list.getSize() << std::endl;
  std::cout << "**** start sorting" << std::endl;
  std::cout << "**** start sort index" << std::endl;
  list.setOrder(Liste::DESC);
  double profIndex = microtime();
  list.sortByIndex();
  list.displayAt(0);
  std::cout << "++++ Profile sorted index : " << microtime() - profIndex << "s" << std::endl;
  std::cout << "**** start sort port" << std::endl;
  list.setOrder(Liste::ASC);
  double profPort = microtime();
  list.sortByPort();
  list.displayAt(0);
  std::cout << "++++ Profile sort port : " << microtime() - profPort << "s" << std::endl;
  std::cout << "**** start sort value" << std::endl;
  list.setOrder(Liste::DESC);
  double profValue = microtime();
  list.sortByValue();
  list.displayAt(0);
  std::cout << "++++ Profile sort value : " << microtime() - profValue << "s" << std::endl;
  std::cout << "**** min index " << list.getMinIndex() << std::endl;
  std::cout << "**** min port " << list.getMinPort() << std::endl;
  std::cout << "**** min value " << list.getMinValue() << std::endl;
  std::cout << "**** max index " << list.getMaxIndex() << std::endl;
  std::cout << "**** max port " << list.getMaxPort() << std::endl;
  std::cout << "**** max value " << list.getMaxValue() << std::endl;
  //list.display();
  return 0;
}