
#include <string>
#include <iostream>
#include "demo/demo.h"

using namespace std;

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

    //list.displayAt(0);
    return 0;
}