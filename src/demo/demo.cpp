
#include "demo.hpp"

/**
 * @brief Construct a new Demo:: Demo object
 * 
 * @param profiler 
 * @param item 
 * @param list 
 */
Demo::Demo(Profile &profiler, Item &item, Liste &list)
    : m_profiler(profiler), m_item(item), m_list(list)
{
}

/**
 * @brief print message with a new line
 * 
 * @param msg 
 */
void Demo::println(std::string msg)
{
    std::cout << msg << std::endl;
}

/**
 * @brief populate list
 * 
 */
void Demo::populateList()
{
    m_profiler.mark("generation");
    std::cout << std::endl
              << "> start generation" << std::endl;
    int itemAmount = 1000000;
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

/**
 * @brief append a single item to the list
 * 
 */
void Demo::appendItem()
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

/**
 * @brief sort by index order desc
 * 
 */
void Demo::sortByIndex()
{
    m_profiler.mark("sort index");
    println("> start sort index");
    m_list.setOrder(Liste::DESC).sortByIndex().displayAt(0);
    m_profiler.elapse();
}

/**
 * @brief sort by port order asc
 * 
 */
void Demo::sortByPort()
{
    m_profiler.mark("sort port");
    println("> start sort port");
    m_list.setOrder(Liste::ASC).sortByPort().displayAt(0);
    m_profiler.elapse();
}

/**
 * @brief sort by value order asc
 * 
 */
void Demo::sortByValue()
{
    m_profiler.mark("sort value");
    println("> start sort value");
    m_list.setOrder(Liste::ASC).sortByValue().displayAt(0);
    m_profiler.elapse();
}

/**
 * @brief display minima for index,port,value
 * 
 */
void Demo::minima()
{
    m_profiler.mark("minima");
    println("min index " + std::to_string(m_list.getMinIndex()));
    println("min port " + std::to_string(m_list.getMinPort()));
    println("min value " + std::to_string(m_list.getMinValue()));
    m_profiler.elapse();
}

/**
 * @brief display maxima for index,port,value
 * 
 */
void Demo::maxima()
{
    m_profiler.mark("maxima");
    println("max index " + std::to_string(m_list.getMaxIndex()));
    println("max port " + std::to_string(m_list.getMaxPort()));
    println("max value " + std::to_string(m_list.getMaxValue()));
    m_profiler.elapse();
}

/**
 * @brief count filtered by port then by value
 * 
 */
void Demo::filterItems()
{
    m_profiler.mark("filters");
    m_list.setView(Liste::MAIN).filterByValue(0).setView(Liste::FILTERED);
    int countFilteredValue = m_list.items().size();
    println("count filtered values 0 : " + std::to_string(countFilteredValue));
    m_list.setView(Liste::MAIN).filterByPort(0).setView(Liste::FILTERED);
    const int countFilteredPort = m_list.items().size();
    println("count filteres ports 0 : " + std::to_string(countFilteredPort));
    m_list.setView(Liste::MAIN);
    m_profiler.elapse();
}