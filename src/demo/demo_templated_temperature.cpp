
#include "demo_templated_temperature.hpp"

using namespace cppmodel;

//
// @brief Construct a new Demo:: Demo object
//
// @param profiler
// @param item
// @param list
//
DemoTemplatedTemperature::DemoTemplatedTemperature(Profile &profiler, ItemTemperature &item, ListeTemplate<ItemTemperature> &list)
    : m_profiler(profiler), m_item(item), m_list(list)
{
}

//
// @brief print message with a new line
//
// @param msg
//
void DemoTemplatedTemperature::println(std::string msg)
{
    std::cout << msg << std::endl;
}

//
// @brief print message with a new line
//
// @param msg
//
void DemoTemplatedTemperature::run()
{
    populateList();
    appendItem();
    std::cout << std::endl
              << terminal::ansi::fg_red
              << "> start sorting" << std::endl
              << terminal::ansi::reset << std::endl;
    sortByIndex();
    sortByPort();
    sortByValue();
    std::cout << std::endl
              << terminal::ansi::fg_red
              << "> start minima" << std::endl
              << terminal::ansi::reset << std::endl;
    minima();
    std::cout << std::endl
              << terminal::ansi::fg_red
              << "> start maxima" << std::endl
              << terminal::ansi::reset << std::endl;
    maxima();
    std::cout << std::endl
              << terminal::ansi::fg_red
              << "> start filtering" << std::endl
              << terminal::ansi::reset << std::endl;
    filterItems();
}

//
// @brief populate list
//
//
void DemoTemplatedTemperature::populateList()
{
    m_profiler.mark("generation");
    std::cout << std::endl
              << "> start generation" << std::endl;
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
    println("> Liste size : " + std::to_string(m_list.getSize()));
    m_profiler.elapse();
}

//
// @brief append a single item to the list
//
//
void DemoTemplatedTemperature::appendItem()
{
    m_profiler.mark("append item");
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
void DemoTemplatedTemperature::sortByIndex()
{
    m_profiler.mark("sort index");
    println("> start sort index");
    //m_list.setOrder(Liste<ItemTemperature>::DESC).sortByIndex().displayAt(0);
    const std::string key = "index";
    m_list.setOrder(ListeTemplate<ItemTemperature>::DESC).sortBy(key).displayAt(0);
    m_profiler.elapse();
}

//
// @brief sort by port order asc
//
//
void DemoTemplatedTemperature::sortByPort()
{
    m_profiler.mark("sort port");
    println("> start sort port");
    m_list.setOrder(ListeTemplate<ItemTemperature>::ASC).sortByPort().displayAt(0);
    m_profiler.elapse();
}

//
// @brief sort by value order asc
//
//
void DemoTemplatedTemperature::sortByValue()
{
    m_profiler.mark("sort value");
    println("> start sort value");
    m_list.setOrder(ListeTemplate<ItemTemperature>::ASC).sortByValue().displayAt(0);
    m_profiler.elapse();
}

//
// @brief display minima for index,port,value
//
//
void DemoTemplatedTemperature::minima()
{
    m_profiler.mark("minima");
    println("min index " + std::to_string(m_list.getMinIndex()));
    println("min port " + std::to_string(m_list.getMinPort()));
    println("min value " + std::to_string(m_list.getMinValue()));
    m_profiler.elapse();
}

//
// @brief display maxima for index,port,value
//
//
void DemoTemplatedTemperature::maxima()
{
    m_profiler.mark("maxima");
    println("max index " + std::to_string(m_list.getMaxIndex()));
    println("max port " + std::to_string(m_list.getMaxPort()));
    println("max value " + std::to_string(m_list.getMaxValue()));
    m_profiler.elapse();
}

//
// @brief count filtered by port then by value
//
//
void DemoTemplatedTemperature::filterItems()
{
    m_profiler.mark("filters");
    m_list
        .setView(ListeTemplate<ItemTemperature>::MAIN)
        .filterByValue(0)
        .setView(ListeTemplate<ItemTemperature>::FILTERED);
    int countFilteredValue = m_list.items().size();
    println("count filtered values 0 : " + std::to_string(countFilteredValue));
    m_list
        .setView(ListeTemplate<ItemTemperature>::MAIN)
        .filterByPort(0)
        .setView(ListeTemplate<ItemTemperature>::FILTERED);
    const int countFilteredPort = m_list.items().size();
    println("count filteres ports 0 : " + std::to_string(countFilteredPort));
    m_list.setView(ListeTemplate<ItemTemperature>::MAIN);
    m_profiler.elapse();
}