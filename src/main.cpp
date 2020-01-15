
#include <iostream>
#include "demo/demo_temperature.hpp"
#include "demo/demo_templated_temperature.hpp"
#include "model/liste.hpp"

using namespace cppmodel;

//
// @brief illustrate vector featuring as min max sort filter
//
// @return int
//
int main()
{

    Profile profiler;
    ListeTemperature listTemp;
    ItemTemperature item;
    DemoTemperature demo = DemoTemperature(profiler, item, listTemp);

    Liste<ItemTemperature> listTemplated;
    DemoTemplatedTemperature demoTemplated = DemoTemplatedTemperature(
        profiler, item, listTemplated);

    demo.populateList();
    demo.appendItem();
    std::cout << std::endl
              << "> start sorting" << std::endl
              << std::endl;
    demo.sortByIndex();
    demo.sortByPort();
    demo.sortByValue();
    std::cout << std::endl
              << "> start minima" << std::endl
              << std::endl;
    demo.minima();
    std::cout << std::endl
              << "> start maxima" << std::endl
              << std::endl;
    demo.maxima();
    std::cout << std::endl
              << "> start filtering" << std::endl
              << std::endl;
    demo.filterItems();

    demoTemplated.populateList();
    demoTemplated.appendItem();
    std::cout << std::endl
              << "> start sorting" << std::endl
              << std::endl;
    demoTemplated.sortByIndex();
    demoTemplated.sortByPort();
    demoTemplated.sortByValue();
    std::cout << std::endl
              << "> start minima" << std::endl
              << std::endl;
    demoTemplated.minima();
    std::cout << std::endl
              << "> start maxima" << std::endl
              << std::endl;
    demoTemplated.maxima();
    std::cout << std::endl
              << "> start filtering" << std::endl
              << std::endl;
    demoTemplated.filterItems();

    return 0;
}