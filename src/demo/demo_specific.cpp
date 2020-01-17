
#include "demo_specific.hpp"

using namespace cppmodel;

//
// @brief Construct a new DemoSpecific object
//
// @param profiler
// @param item
// @param list
//
DemoSpecific::DemoSpecific(Profile &profiler, ItemTemperature &item, ListeTemperature &list)
    : m_profiler(profiler), m_item(item), m_list(list)
{
}

//
// @brief print message with a new line
//
// @param msg
//
void DemoSpecific::println(std::string msg)
{
    std::cout << msg << std::endl;
}

//
// @brief print message with a new line
//
// @param msg
//
void DemoSpecific::printTitle(std::string msg)
{
    std::cout << std::endl
              << terminal::ansi::bold << terminal::ansi::fg_red
              << msg
              << terminal::ansi::reset << std::endl;
}

//
// @brief run demo
//
//
void DemoSpecific::run()
{
    printTitle("> generate specific");
    populateList();
    appendItem();
    printTitle("> sorts specific");
    sortByIndex();
    sortByPort();
    sortByValue();
    printTitle("> minima specific");
    minima();
    printTitle("> maxima specific");
    maxima();
    printTitle("> filters specific");
    filterItems();
}

//
// @brief populate list
//
//
void DemoSpecific::populateList()
{
    m_profiler.mark("generation specific");
    const int itemAmount = 1000000;
    for (int i = 0; i < itemAmount; i++)
    {
        m_item.index = i;
        m_item.port = i % 4; // 0..4
        m_item.timestamp = "2020-01-0" + std::to_string(i % 30);
        m_item.type = "temperature";
        m_item.value = rand() % 100; // 0..100
        m_list.appendItem(m_item);
    }
    println("* First item");
    m_list.displayAt(0);
    println("* Last item");
    m_list.displayAt(m_list.getSize() - 1);
    println("> Liste size : " + std::to_string(m_list.getSize()));
    m_profiler.elapse();
}

//
// @brief append a single item to the list
//
//
void DemoSpecific::appendItem()
{
    m_profiler.mark("append item specific");
    m_item.index = 1000;
    m_item.value = 0;
    m_item.timestamp = "3020-20-20";
    m_list.appendItem(m_item);
    println("> after append");
    println("> Liste size : " + std::to_string(m_list.getSize()));
    m_profiler.elapse();
}

//
// @brief sort by index order desc
//
//
void DemoSpecific::sortByIndex()
{
    m_profiler.mark("sort index specific");
    println("> start sort index");
    m_list.setOrder(ListeTemperature::DESC).sortByIndex().displayAt(0);
    m_profiler.elapse();
}

//
// @brief sort by port order asc
//
//
void DemoSpecific::sortByPort()
{
    m_profiler.mark("sort port specific");
    println("> start sort port");
    m_list.setOrder(ListeTemperature::ASC).sortByPort().displayAt(0);
    m_profiler.elapse();
}

//
// @brief sort by value order asc
//
//
void DemoSpecific::sortByValue()
{
    m_profiler.mark("sort value specific");
    println("> start sort value");
    m_list.setOrder(ListeTemperature::ASC).sortByValue().displayAt(0);
    m_profiler.elapse();
}

//
// @brief display minima for index,port,value
//
//
void DemoSpecific::minima()
{
    m_profiler.mark("minima specific");
    println("min index " + std::to_string(m_list.getMinIndex()));
    println("min port " + std::to_string(m_list.getMinPort()));
    println("min value " + std::to_string(m_list.getMinValue()));
    m_profiler.elapse();
}

//
// @brief display maxima for index,port,value
//
//
void DemoSpecific::maxima()
{
    m_profiler.mark("maxima specific");
    println("max index " + std::to_string(m_list.getMaxIndex()));
    println("max port " + std::to_string(m_list.getMaxPort()));
    println("max value " + std::to_string(m_list.getMaxValue()));
    m_profiler.elapse();
}

//
// @brief count filtered by port then by value
//
//
void DemoSpecific::filterItems()
{
    m_profiler.mark("filters specific");
    m_list.setView(ListeTemperature::MAIN).filterByValue(0).setView(ListeTemperature::FILTERED);
    int countFilteredValue = m_list.items().size();
    println("count filtered values 0 : " + std::to_string(countFilteredValue));
    m_list.setView(ListeTemperature::MAIN).filterByPort(0).setView(ListeTemperature::FILTERED);
    const int countFilteredPort = m_list.items().size();
    println("count filteres ports 0 : " + std::to_string(countFilteredPort));
    m_list.setView(ListeTemperature::MAIN);
    m_profiler.elapse();
}