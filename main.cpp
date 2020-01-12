
#include <string>
#include <iostream>
#include <chrono>
#include "profile.h"
#include "model.h"

using namespace std;

void println(string msg)
{
    std::cout << msg << std::endl;
}

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
    println("> Liste size : " + std::to_string(list.getSize()));
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
    println("> after append");
    println("> Liste size : " + std::to_string(list.getSize()));
}

/**
 * @brief sort by index order desc
 * 
 * @param list 
 */
void sortByIndex(Liste &list)
{
    println("> start sort index");
    list.setOrder(Liste::DESC).sortByIndex().displayAt(0);
}

/**
 * @brief sort by port order asc
 * 
 * @param list 
 */
void sortByPort(Liste &list)
{
    println("> start sort port");
    list.setOrder(Liste::ASC).sortByPort().displayAt(0);
}

/**
 * @brief sort by value order asc
 * 
 * @param list 
 */
void sortByValue(Liste &list)
{
    println("> start sort value");
    list.setOrder(Liste::ASC).sortByValue().displayAt(0);
}

/**
 * @brief display minima for index,port,value
 * 
 * @param list 
 */
void minima(Liste &list)
{
    println("min index " + std::to_string(list.getMinIndex()));
    println("min port " + std::to_string(list.getMinPort()));
    println("min value " + std::to_string(list.getMinValue()));
}

/**
 * @brief display maxima for index,port,value
 * 
 * @param list 
 */
void maxima(Liste &list)
{
    println("max index " + std::to_string(list.getMaxIndex()));
    println("max port " + std::to_string(list.getMaxPort()));
    println("max value " + std::to_string(list.getMaxValue()));
}

/**
 * @brief count filtered by port then by value
 * 
 * @param list 
 */
void filterItems(Liste &list)
{
    list.setView(Liste::MAIN).filterByValue(0).setView(Liste::FILTERED);
    int countFilteredValue = list.items().size();
    println("count filtered values 0 : " + std::to_string(countFilteredValue));
    list.setView(Liste::MAIN).filterByPort(0).setView(Liste::FILTERED);
    const int countFilteredPort = list.items().size();
    println("count filteres ports 0 : " + std::to_string(countFilteredPort));
    list.setView(Liste::MAIN);
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

    std::cout << std::endl
              << "> start filtering" << std::endl
              << std::endl;
    profiler.mark("filters");
    filterItems(list);
    profiler.elapse();

    list.displayAt(0);
    return 0;
}