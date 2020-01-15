
#include <iostream>
#include "demo/demo.hpp"

using namespace cppmodel;

//
// @brief illustrate vector featuring as min max sort filter
//
// @return int
//
int main()
{

    Profile profiler;
    Liste list;
    ItemTemperature item;
    Demo demo = Demo(profiler, item, list);
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
    return 0;
}