
#ifndef CPPMODEL_DEMO_TEMPLATED_TEMPERATURE_HPP
#define CPPMODEL_DEMO_TEMPLATED_TEMPERATURE_HPP

#include <string>
#include <iostream>
#include "../model/item_temperature.hpp"
#include "../profile/profile.hpp"
#include "../model/liste_generic.inl"
#include "../terminal/ansi.tcc"

namespace cppmodel
{
    class DemoGeneric
    {

        public:
            DemoGeneric(Profile &profiler, ItemTemperature &item, ListeTemplate<ItemTemperature> &list);
            void run();

        private:
            void println(std::string msg);
            void printTitle(std::string msg);
            void populateList();
            void appendItem();
            void sortByIndex();
            void sortByPort();
            void sortByValue();
            void sortByPortValue();
            void minima();
            void maxima();
            void filterItems();
            void displayAt(int ix);
            void displayAll();
            Profile m_profiler;
            ItemTemperature m_item;
            ListeTemplate<ItemTemperature> m_list;
    };
}

#endif