
#include <iostream>
#include "demo/demo_generic.hpp"
#include "demo/demo_specific.hpp"
#include "model/liste_generic.inl"
#include "model/item_temperature.hpp"
#include <algorithm>
#include <functional>

using namespace cppmodel;

template <typename TFunc>
void ProcessArguments(const TFunc &process)
{
}

template <typename TFunc, typename HEAD, typename... TAIL>
void ProcessArguments(const TFunc &process, const HEAD &head, const TAIL &... tail)
{
    process(head);
    ProcessArguments(process, tail...);
}

template <typename TFunc, typename HEAD, typename... TAIL>
bool ProcessArguments(const TFunc &process, const HEAD &head, const TAIL &... tail)
{
    process(head);
    return ProcessArguments(process, tail...);
}

template <typename I>
bool C(I){

}

void sortCompare(const ItemTemperature &i1, const ItemTemperature &i2)
{
    int mod = 3;
    [mod](const ItemTemperature &i) {
        return (i.index % mod == 0);
    };
}

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

    const int max = 1000;
    for (int c = 0; c < max; c++)
    {
        t.index = c;
        l.push_back(t);
    }
    int mod = 3;
    l.erase(
        std::remove_if(
            l.begin(),
            l.end(),
            &[&mod](const Toto &i) {return (i.index % mod == 0);}
            /*
            ProcessArguments<int(Toto)>(
                [&mod](const Toto &i) {
                    return (i.index % mod == 0);
                },
                &l)*/
                ),
        l.end());

    /*
    ProcessArguments<bool>([mod](const ItemTemperature &i) {
        return (i.index % mod == 0);
    });*/
    //[&p](const int &v) { *p++ = v; }, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10);
    //}
    /*
    struct Toto
    {
        int index;
        std::string name;
    };

    typedef std::vector<Toto> TotoList;
    TotoList l;
    Toto t;

    const int max = 1000;
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
    }*/

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