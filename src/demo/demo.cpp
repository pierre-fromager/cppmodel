
#include "demo.h"

Demo::Demo(Profile &profiler, Item &item, Liste &list)
{
    _profiler = profiler;
    _item = item;
    _list = list;
}

/**
 * @brief print message with a new line
 * 
 * @param msg 
 */
void Demo::println(string msg)
{
    std::cout << msg << std::endl;
}

/**
 * @brief populate list
 * 
 */
void Demo::populateList()
{
    _profiler.mark("generation");
    std::cout << std::endl
              << "> start generation" << std::endl;
    int itemAmount = 1000000;
    for (int i = 0; i < itemAmount; i++)
    {
        _item.index = i;
        _item.port = i % 4; // 0..4
        _item.timestamp = "2020-01-0" + to_string(i % 30);
        _item.type = "temperature";
        _item.value = rand() % 100; // 0..100
        _list.appendItem(_item);
    }
    println("> Liste size : " + std::to_string(_list.getSize()));
    _profiler.elapse();
}

/**
 * @brief append a single item to the list
 * 
 */
void Demo::appendItem()
{
    _profiler.mark("append item");
    _item.index = 1000;
    _item.value = 0;
    _item.timestamp = "3020-20-20";
    _list.appendItem(_item);
    println("> after append");
    println("> Liste size : " + std::to_string(_list.getSize()));
    _profiler.elapse();
}

/**
 * @brief sort by index order desc
 * 
 */
void Demo::sortByIndex()
{
    _profiler.mark("sort index");
    println("> start sort index");
    _list.setOrder(Liste::DESC).sortByIndex().displayAt(0);
    _profiler.elapse();
}

/**
 * @brief sort by port order asc
 * 
 */
void Demo::sortByPort()
{
    _profiler.mark("sort port");
    println("> start sort port");
    _list.setOrder(Liste::ASC).sortByPort().displayAt(0);
    _profiler.elapse();
}

/**
 * @brief sort by value order asc
 * 
 */
void Demo::sortByValue()
{
    _profiler.mark("sort value");
    println("> start sort value");
    _list.setOrder(Liste::ASC).sortByValue().displayAt(0);
    _profiler.elapse();
}

/**
 * @brief display minima for index,port,value
 * 
 */
void Demo::minima()
{
    _profiler.mark("minima");
    println("min index " + std::to_string(_list.getMinIndex()));
    println("min port " + std::to_string(_list.getMinPort()));
    println("min value " + std::to_string(_list.getMinValue()));
    _profiler.elapse();
}

/**
 * @brief display maxima for index,port,value
 * 
 */
void Demo::maxima()
{
    _profiler.mark("maxima");
    println("max index " + std::to_string(_list.getMaxIndex()));
    println("max port " + std::to_string(_list.getMaxPort()));
    println("max value " + std::to_string(_list.getMaxValue()));
    _profiler.elapse();
}

/**
 * @brief count filtered by port then by value
 * 
 */
void Demo::filterItems()
{
    _profiler.mark("filters");
    _list.setView(Liste::MAIN).filterByValue(0).setView(Liste::FILTERED);
    int countFilteredValue = _list.items().size();
    println("count filtered values 0 : " + std::to_string(countFilteredValue));
    _list.setView(Liste::MAIN).filterByPort(0).setView(Liste::FILTERED);
    const int countFilteredPort = _list.items().size();
    println("count filteres ports 0 : " + std::to_string(countFilteredPort));
    _list.setView(Liste::MAIN);
    _profiler.elapse();
}