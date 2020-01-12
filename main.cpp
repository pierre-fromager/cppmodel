
#include <iostream>
#include <chrono>
#include "profile.h"
#include "model.h"

using namespace std;

/**
 * @brief time profiler
 * 
 * @return double 
 */
double microtime()
{
    return (double(std::chrono::duration_cast<std::chrono::microseconds>(std::chrono::system_clock::now().time_since_epoch()).count()) / double(1000000));
}

/**
 * @brief illustrate list manipulation as min max sort
 * g++ -g -std=c++11 -o testptr test-ptr.cpp
 * 
 * @return int 
 */
int main()
{
    Profile profiler;
    Liste list;
    Item item;

    profiler.mark("generation");
    std::cout << "**** start generation" << std::endl;
    int itemAmount = 1000000;
    for (int i = 0; i < itemAmount; i++)
    {
        item.index = i;
        item.port = i % 4; // 0..4
        item.timestamp = "2020-01-0" + to_string(i % 30);
        item.type = "temperature";
        item.value = rand() % 100; // 0..100
        list.appendItem(item);
    }
    std::cout << "Liste size : " << list.getSize() << std::endl;
    profiler.elapse();

    item.index = 1000;
    item.value = 0;
    item.timestamp = "3020-20-20";
    list.appendItem(item);
    std::cout << "**** after append" << std::endl;
    std::cout << "Liste size : " << list.getSize() << std::endl;

    std::cout << "**** start sorting" << std::endl;

    profiler.mark("sort index");
    std::cout << "**** start sort index" << std::endl;
    list.setOrder(Liste::DESC);
    list.sortByIndex();
    list.displayAt(0);
    profiler.elapse();

    profiler.mark("sort port");
    std::cout << "**** start sort port" << std::endl;
    list.setOrder(Liste::ASC);
    double profPort = microtime();
    list.sortByPort();
    list.displayAt(0);
    profiler.elapse();

    profiler.mark("sort value");
    std::cout << "**** start sort value" << std::endl;
    list.setOrder(Liste::DESC);
    list.sortByValue();
    list.displayAt(0);
    profiler.elapse();

    profiler.mark("minima");
    std::cout << "**** start sort value" << std::endl;
    std::cout << "**** min index " << list.getMinIndex() << std::endl;
    std::cout << "**** min port " << list.getMinPort() << std::endl;
    std::cout << "**** min value " << list.getMinValue() << std::endl;
    profiler.elapse();

    profiler.mark("maxima");
    std::cout << "**** max index " << list.getMaxIndex() << std::endl;
    std::cout << "**** max port " << list.getMaxPort() << std::endl;
    std::cout << "**** max value " << list.getMaxValue() << std::endl;
    profiler.elapse();
    //list.display();
    return 0;
}