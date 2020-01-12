
#include <string>
#include <iostream>
#include "profile.h"
#include "model.h"

using namespace std;

/**
 * @brief print message with a new line
 * 
 * @param msg 
 */
void println(string msg)
{
    std::cout << msg << std::endl;
}

/**
 * @brief populate list
 * 
 * @param profiler 
 * @param item 
 * @param list 
 */
void populateList(Profile &profiler, Item &item, Liste &list)
{
    profiler.mark("generation");
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
    profiler.elapse();
}

/**
 * @brief append a single item to the list
 * 
 * @param profiler 
 * @param item 
 * @param list 
 */
void appendItem(Profile &profiler, Item &item, Liste &list)
{
    profiler.mark("append item");
    item.index = 1000;
    item.value = 0;
    item.timestamp = "3020-20-20";
    list.appendItem(item);
    println("> after append");
    println("> Liste size : " + std::to_string(list.getSize()));
    profiler.elapse();
}

/**
 * @brief sort by index order desc
 * 
 * @param profiler 
 * @param list 
 */
void sortByIndex(Profile &profiler, Liste &list)
{
    profiler.mark("sort index");
    println("> start sort index");
    list.setOrder(Liste::DESC).sortByIndex().displayAt(0);
    profiler.elapse();
}

/**
 * @brief sort by port order asc
 * 
 * @param profiler 
 * @param list 
 */
void sortByPort(Profile &profiler, Liste &list)
{
    profiler.mark("sort port");
    println("> start sort port");
    list.setOrder(Liste::ASC).sortByPort().displayAt(0);
    profiler.elapse();
}

/**
 * @brief sort by value order asc
 * 
 * @param profiler 
 * @param list 
 */
void sortByValue(Profile &profiler, Liste &list)
{
    profiler.mark("sort value");
    println("> start sort value");
    list.setOrder(Liste::ASC).sortByValue().displayAt(0);
    profiler.elapse();
}

/**
 * @brief display minima for index,port,value
 * 
 * @param profiler 
 * @param list 
 */
void minima(Profile &profiler, Liste &list)
{
    profiler.mark("minima");
    println("min index " + std::to_string(list.getMinIndex()));
    println("min port " + std::to_string(list.getMinPort()));
    println("min value " + std::to_string(list.getMinValue()));
    profiler.elapse();
}

/**
 * @brief display maxima for index,port,value
 * 
 * @param profiler 
 * @param list 
 */
void maxima(Profile &profiler, Liste &list)
{
    profiler.mark("maxima");
    println("max index " + std::to_string(list.getMaxIndex()));
    println("max port " + std::to_string(list.getMaxPort()));
    println("max value " + std::to_string(list.getMaxValue()));
    profiler.elapse();
}

/**
 * @brief count filtered by port then by value
 * 
 * @param profiler 
 * @param list 
 */
void filterItems(Profile &profiler, Liste &list)
{
    profiler.mark("filters");
    list.setView(Liste::MAIN).filterByValue(0).setView(Liste::FILTERED);
    int countFilteredValue = list.items().size();
    println("count filtered values 0 : " + std::to_string(countFilteredValue));
    list.setView(Liste::MAIN).filterByPort(0).setView(Liste::FILTERED);
    const int countFilteredPort = list.items().size();
    println("count filteres ports 0 : " + std::to_string(countFilteredPort));
    list.setView(Liste::MAIN);
    profiler.elapse();
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

    populateList(profiler, item, list);

    appendItem(profiler, item, list);

    std::cout << std::endl
              << "> start sorting" << std::endl
              << std::endl;

    sortByIndex(profiler, list);

    sortByPort(profiler, list);

    sortByValue(profiler, list);

    std::cout << std::endl
              << "> start minima" << std::endl
              << std::endl;

    minima(profiler, list);

    std::cout << std::endl
              << "> start maxima" << std::endl
              << std::endl;
    maxima(profiler, list);

    std::cout << std::endl
              << "> start filtering" << std::endl
              << std::endl;

    filterItems(profiler, list);

    list.displayAt(0);
    return 0;
}