
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
    ItemTemperature item;

    ListeTemperature listTemp;
    DemoTemperature demo = DemoTemperature(profiler, item, listTemp);
    demo.run();

    Liste<ItemTemperature> listTemplated;
    DemoTemplatedTemperature demoTemplated = DemoTemplatedTemperature(
        profiler, item, listTemplated);
    demoTemplated.run();

    return 0;
}