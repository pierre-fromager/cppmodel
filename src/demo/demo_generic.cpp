
#include "demo_generic.hpp"

using namespace cppmodel;

//
// @brief Construct a new DemoGeneric object
//
// @param profiler
// @param item
// @param list
//
DemoGeneric::DemoGeneric(Profile &profiler, ItemTemperature &item, ListeTemplate<ItemTemperature> &list)
    : m_profiler(profiler), m_item(item), m_list(list)
{
}

//
// @brief print message with a new line
//
// @param msg
//
void DemoGeneric::println(std::string msg)
{
    std::cout << msg << std::endl;
}

//
// @brief print message with a new line
//
// @param msg
//
void DemoGeneric::printTitle(std::string msg)
{
    std::cout << std::endl
              << terminal::ansi::bold << terminal::ansi::fg_red
              << msg
              << terminal::ansi::reset << std::endl;
}

//
// @brief print message with a new line
//
// @param msg
//
void DemoGeneric::run()
{
    printTitle("> generate generic");
    populateList();
    appendItem();
    printTitle("> sorts generic");
    sortByIndex();
    sortByPort();
    sortByValue();
    sortByPortValue();
    printTitle("> minima generic");
    minima();
    printTitle("> maxima generic");
    maxima();
    printTitle("> filters generic");
    filterItems();
}

//
// @brief populate list
//
//
void DemoGeneric::populateList()
{
    m_profiler.mark("generation generic");
    const int itemAmount = 1000000;
    for (int i = 0; i < itemAmount; i++)
    {
        m_item.index = i;
        m_item.port = i % 11; // 0..10
        m_item.timestamp = "2020-01-0" + std::to_string(i % 30);
        m_item.type = "temperature";
        m_item.value = rand() % 101; // 0..99
        m_list.appendItem(m_item);
    }
    println("> Liste size : " + std::to_string(m_list.getSize()));
    m_profiler.elapse();
}

//
// @brief append a single item to the list
//
//
void DemoGeneric::appendItem()
{
    m_profiler.mark("append item generic");
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
void DemoGeneric::sortByIndex()
{
    m_profiler.mark("sort index generic");
    println("> start sort index");
    m_list
        .setOrder(ListeTemplate<ItemTemperature>::DESC)
        .setSortComparator(
            [](
                const ItemTemperature &i1, const ItemTemperature &i2) {
                return (i1.index > i2.index);
            })
        .sortByComparator()
        .displayAt(0);
    m_profiler.elapse();
}

//
// @brief sort by port order asc
//
//
void DemoGeneric::sortByPort()
{
    m_profiler.mark("sort port generic");
    println("> start sort port");
    m_list
        .setOrder(ListeTemplate<ItemTemperature>::DESC)
        .setSortComparator(
            [](
                const ItemTemperature &i1, const ItemTemperature &i2) {
                return (i1.port > i2.port);
            })
        .sortByComparator()
        .displayAt(0);
    m_profiler.elapse();
}

//
// @brief sort by value order asc
//
//
void DemoGeneric::sortByValue()
{
    m_profiler.mark("sort value generic");
    println("> start sort value");
    m_list
        .setOrder(ListeTemplate<ItemTemperature>::DESC)
        .setSortComparator(
            [](
                const ItemTemperature &i1, const ItemTemperature &i2) {
                return (i1.value > i2.value);
            })
        .sortByComparator()
        .displayAt(0);
    m_profiler.elapse();
}

//
// @brief sort by port and value order asc
//
//
void DemoGeneric::sortByPortValue()
{
    m_profiler.mark("sort port + value generic");
    println("> start sort port + value");
    m_list
        .setOrder(ListeTemplate<ItemTemperature>::DESC)
        .setSortComparator(
            [](
                const ItemTemperature &i1, const ItemTemperature &i2) {
                return std::tie(i1.port, i1.value) > std::tie(i2.port, i2.value);
            })
        .sortByComparator()
        .displayAt(0);
    m_profiler.elapse();
}

//
// @brief display minima for index,port,value
//
//
void DemoGeneric::minima()
{
    m_profiler.mark("minima generic");
    println("min index " + std::to_string(m_list.getMinIndex()));
    println("min port " + std::to_string(m_list.getMinPort()));
    println("min value " + std::to_string(m_list.getMinValue()));
    m_profiler.elapse();
}

//
// @brief display maxima for index,port,value
//
//
void DemoGeneric::maxima()
{
    m_profiler.mark("maxima generic");
    println("max index " + std::to_string(m_list.getMaxIndex()));
    println("max port " + std::to_string(m_list.getMaxPort()));
    println("max value " + std::to_string(m_list.getMaxValue()));
    m_profiler.elapse();
}

//
// @brief count filtered by port then by value
//
//
void DemoGeneric::filterItems()
{
    m_profiler.mark("filters generic");
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