
#include <iostream>
#include "demo/demo_temperature.hpp"
#include "demo/demo_templated_temperature.hpp"
#include "model/liste.tcc"
#include <algorithm>
#include <functional>

using namespace cppmodel;

//
// @brief illustrate vector featuring as min max sort filter
//
// @return int
//
int main()
{

    struct Toto
    {
        int index;
        std::string name;
    };

    typedef std::vector<Toto> TotoList;
    TotoList l;
    Toto t;

    const int max = 1000000;
    for (int c = 0; c < max; c++)
    {
        t.index = c;
        l.push_back(t);
    }

    int mod = 3;
    std::function<bool(Toto)> modulo3 = [mod](const Toto &i) {
        return (i.index % mod == 0);
    };

    std::cout << modulo3(t);
    // [isAsc](const ItemTemperature &i1, const ItemTemperature &i2)
    l.erase(
        std::remove_if(l.begin(), l.end(), modulo3),
        l.end());

    int size = l.size();
    for (int c = 0; c < size; c++)
    {
        const Toto item = l.at(c);
        std::cout << item.index << " -- " << item.name << std::endl;
    }

    /*
    Profile profiler;
    ItemTemperature item;

    ListeTemperature listTemp;
    DemoTemperature demo = DemoTemperature(profiler, item, listTemp);
    demo.run();

    Liste<ItemTemperature> listTemplated;
    DemoTemplatedTemperature demoTemplated = DemoTemplatedTemperature(
        profiler, item, listTemplated);
    demoTemplated.run();
*/

    return 0;
}