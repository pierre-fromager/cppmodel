
#include "profile/profile.hpp"
#include "demo/demo_generic.hpp"
#include "demo/demo_specific.hpp"
#include "model/liste_generic.inl"

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
    DemoSpecific demo = DemoSpecific(profiler, item, listTemp);
    demo.run();

    ListeTemplate<ItemTemperature> listTemplated;
    DemoGeneric demoTemplated = DemoGeneric(profiler, item, listTemplated);
    demoTemplated.run();

    return 0;
}