
#include <iostream>
#include <chrono>
#include "profile.h"
#include "model.h"

using namespace std;

/**
 * @brief populate list
 * 
 * @param item 
 * @param list 
 */
void populateList(Item &item, Liste &list)
{
    std::cout << std::endl
              << "> start generation" << std::endl;
    int itemAmount = 1000000;
    for (int i = 0; i < itemAmount; i++)
    {
        item.index = i;
        item.port = i % 4; // 0..4
        item.timestamp = "2020-01-0" + to_string(i % 30);
        item.type = "temperature";
        item.value = rand() % 100; // 0..100
        list.appendItem(item);
    }
    std::cout << "> Liste size : " << list.getSize() << std::endl;
}

/**
 * @brief append a single item to the list
 * 
 * @param item 
 * @param list 
 */
void appendItem(Item &item, Liste &list)
{
    item.index = 1000;
    item.value = 0;
    item.timestamp = "3020-20-20";
    list.appendItem(item);
    std::cout << "> after append" << std::endl;
    std::cout << "> Liste size : " << list.getSize() << std::endl;
}

/**
 * @brief sort by index order desc
 * 
 * @param list 
 */
void sortByIndex(Liste &list)
{
    std::cout << std::endl
              << "> start sort index" << std::endl;
    list.setOrder(Liste::DESC);
    list.sortByIndex();
    list.displayAt(0);
}

/**
 * @brief sort by port order asc
 * 
 * @param list 
 */
void sortByPort(Liste &list)
{
    std::cout << "> start sort port" << std::endl;
    list.setOrder(Liste::ASC);
    list.sortByPort();
    list.displayAt(0);
}

/**
 * @brief sort by value order asc
 * 
 * @param list 
 */
void sortByValue(Liste &list)
{
    std::cout << "> start sort value" << std::endl;
    list.setOrder(Liste::ASC);
    list.sortByValue();
    list.displayAt(0);
}

/**
 * @brief display minima for index,port,value
 * 
 * @param list 
 */
void minima(Liste &list)
{
    std::cout << "min index " << list.getMinIndex() << std::endl;
    std::cout << "min port " << list.getMinPort() << std::endl;
    std::cout << "min value " << list.getMinValue() << std::endl;
}

/**
 * @brief display maxima for index,port,value
 * 
 * @param list 
 */
void maxima(Liste &list)
{
    std::cout << "max index " << list.getMaxIndex() << std::endl;
    std::cout << "max port " << list.getMaxPort() << std::endl;
    std::cout << "max value " << list.getMaxValue() << std::endl;
}

/**
 * @brief illustrate list manipulation as min max sort
 * 
 * @return int 
 */
int main()
{
    Profile profiler;
    Liste list;
    Item item;

    profiler.mark("generation");
    populateList(item, list);
    profiler.elapse();

    profiler.mark("append item");
    appendItem(item, list);
    profiler.elapse();

    std::cout << std::endl
              << "> start sorting" << std::endl
              << std::endl;

    profiler.mark("sort index");
    sortByIndex(list);
    profiler.elapse();

    profiler.mark("sort port");
    sortByPort(list);
    profiler.elapse();

    profiler.mark("sort value");
    sortByValue(list);
    profiler.elapse();

    std::cout << std::endl
              << "> start minima" << std::endl
              << std::endl;
    profiler.mark("minima");
    minima(list);
    profiler.elapse();

    std::cout << std::endl
              << "> start maxima" << std::endl
              << std::endl;
    profiler.mark("maxima");
    maxima(list);
    profiler.elapse();

    //list.display();
    return 0;
}