
#include "demo_generic.hpp"
#include <iterator>

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
    const std::string filename = "list_generic.csv";
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
    printTitle("> file save generic");
    save(filename);
    printTitle("> file load generic");
    //load(filename);
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
        .sortByComparator();
    displayAt(0);
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
        .sortByComparator();
    displayAt(0);
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
        .sortByComparator();
    displayAt(0);
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
        .sortByComparator();
    displayAt(0);
    m_profiler.elapse();
}

//
// @brief display minima for index,port,value
//
//
void DemoGeneric::minima()
{
    m_profiler.mark("minima generic");
    m_list.setSortComparator(
        [](
            const ItemTemperature &i1, const ItemTemperature &i2) {
            return (i1.index < i2.index);
        });
    println("min index " + std::to_string(m_list.getMin()->index));
    m_list.setSortComparator(
        [](
            const ItemTemperature &i1, const ItemTemperature &i2) {
            return (i1.port < i2.port);
        });
    println("min port " + std::to_string(m_list.getMin()->port));
    m_list.setSortComparator(
        [](
            const ItemTemperature &i1, const ItemTemperature &i2) {
            return (i1.value < i2.value);
        });
    println("min value " + std::to_string(m_list.getMin()->value));
    m_profiler.elapse();
}

//
// @brief display maxima for index,port,value
//
//
void DemoGeneric::maxima()
{
    m_profiler.mark("maxima generic");
    m_list.setSortComparator(
        [](
            const ItemTemperature &i1, const ItemTemperature &i2) {
            return (i1.index < i2.index);
        });
    println("max index " + std::to_string(m_list.getMax()->index));
    m_list.setSortComparator(
        [](
            const ItemTemperature &i1, const ItemTemperature &i2) {
            return (i1.port < i2.port);
        });
    println("max port " + std::to_string(m_list.getMax()->port));
    m_list.setSortComparator(
        [](
            const ItemTemperature &i1, const ItemTemperature &i2) {
            return (i1.value < i2.value);
        });
    println("max value " + std::to_string(m_list.getMax()->value));
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
        .setFilterComparator(
            [](const ItemTemperature &i) {
                return i.index == 0;
            })
        .filterByComparator()
        .setView(ListeTemplate<ItemTemperature>::FILTERED);
    const std::string strCountIndex = std::to_string(
        m_list.items().size());
    println("count filtered index 0 : " + strCountIndex);

    m_list
        .setView(ListeTemplate<ItemTemperature>::MAIN)
        .setFilterComparator(
            [](const ItemTemperature &i) {
                return i.value == 0;
            })
        .filterByComparator()
        .setView(ListeTemplate<ItemTemperature>::FILTERED);
    const std::string strCountValues = std::to_string(
        m_list.items().size());
    println("count filtered values 0 : " + strCountValues);

    m_list
        .setView(ListeTemplate<ItemTemperature>::MAIN)
        .setFilterComparator(
            [](const ItemTemperature &i) {
                return i.port == 0;
            })
        .filterByComparator()
        .setView(ListeTemplate<ItemTemperature>::FILTERED);
    const std::string strCountPorts = std::to_string(m_list.items().size());
    println("count filtered ports 0 : " + strCountPorts);
    m_list.setView(ListeTemplate<ItemTemperature>::MAIN);

    m_list
        .setView(ListeTemplate<ItemTemperature>::MAIN)
        .setFilterComparator(
            [](const ItemTemperature &i) {
                return i.port == 0 && i.value > 10 && i.value < 50;
            });
    const std::string strCountMultiCrit = std::to_string(m_list.countFiltered());
    println("count ports 0 and value interval ]10..50[ : " + strCountMultiCrit);

    m_profiler.elapse();
}

//
// @brief display item at position
//
//
void DemoGeneric::displayAt(int ix)
{
    const ItemTemperature item = m_list.items().at(ix);
    const std::string separator = "-------------------------";
    std::cout << separator << std::endl;
    std::cout << "- index " << item.index << std::endl;
    std::cout << "- port " << item.port << std::endl;
    std::cout << "- timestamp " << item.timestamp << std::endl;
    std::cout << "- type " << item.type << std::endl;
    std::cout << "- value " << item.value << std::endl;
    std::cout << separator << std::endl;
    std::cout << std::endl;
}

//
// @brief display all list items
//
//
//template <typename Item, typename VectorItem>
void DemoGeneric::displayAll()
{
    const int max = m_list.items().size();
    for (int ix = 0; ix < max; ix++)
    {
        displayAt(ix);
    }
}

//
// @brief load items from file to list
//
//
//template <typename Item, typename VectorItem>
void DemoGeneric::load(std::string filename)
{
    m_list.items().clear();
    std::ifstream myfile;
    myfile.open(filename);
    const std::string sep = ";";
    std::string line;
    if (myfile.is_open())
    {
        while (getline(myfile, line))
        {
            std::cout << line << std::endl;
        }
        myfile.close();
    }
}

//
// @brief save list to csv file ; separator
//
// @return int
//
void DemoGeneric::save(std::string filename)
{
    m_profiler.mark("save to file generic");
    m_list.save(filename);
    m_profiler.elapse();
}