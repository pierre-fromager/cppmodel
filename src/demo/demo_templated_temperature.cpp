
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
void DemoTemplatedTemperature::printTitle(std::string msg)
{
    std::cout << std::endl
              << terminal::ansi::fgbold_red
              << msg << terminal::ansi::reset << std::endl;
}

//
// @brief print message with a new line
//
// @param msg
//
void DemoTemplatedTemperature::run()
{
    printTitle("> generate");
    populateList();
    appendItem();
    printTitle("> sorts");
    sortByIndex();
    sortByPort();
    sortByValue();
    printTitle("> minima");
    minima();
    printTitle("> maxima");
    maxima();
    printTitle("> filters");
    filterItems();
}

//
// @brief populate list
//
//
void DemoTemplatedTemperature::populateList()
{
    m_profiler.mark("generation");
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
    const std::function<bool(ItemTemperature,ItemTemperature)> comparator = [](
        const ItemTemperature &i1,const ItemTemperature &i2
        ) {
        return (i1.index < i2.index);
    };
    m_list
        .setOrder(ListeTemplate<ItemTemperature>::DESC)
        .sortBy(comparator)
        .displayAt(0);
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
    m_list
        .setOrder(ListeTemplate<ItemTemperature>::ASC)
        .sortByPort()
        .displayAt(0);
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
    m_list
        .setOrder(ListeTemplate<ItemTemperature>::ASC)
        .sortByValue()
        .displayAt(0);
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
    const std::string strCountValues = std::to_string(
        m_list.items().size());
    println("count filtered values 0 : " + strCountValues);
    m_list
        .setView(ListeTemplate<ItemTemperature>::MAIN)
        .filterByPort(0)
        .setView(ListeTemplate<ItemTemperature>::FILTERED);
    const std::string strCountPorts = std::to_string(m_list.items().size());
    println("count filteres ports 0 : " + strCountPorts);
    m_list.setView(ListeTemplate<ItemTemperature>::MAIN);
    m_profiler.elapse();
}