
#ifndef CPPMODEL_DEMO_TEMPERATURE_HPP
#define CPPMODEL_DEMO_TEMPERATURE_HPP

#include <string>
#include <iostream>
#include "../profile/profile.hpp"
#include "../model/liste_temperature.hpp"
#include "../terminal/ansi.tcc"

namespace cppmodel
{
    class DemoSpecific
    {

        public:
            DemoSpecific(Profile &profiler, ItemTemperature &item, ListeTemperature &list);
            void run();

        private:
            void println(const std::string &msg);
            void printTitle(const std::string &msg);
            void populateList();
            void appendItem();
            void sortByIndex();
            void sortByPort();
            void sortByValue();
            void sortByPortValue();
            void minima();
            void maxima();
            void filterItems();
            Profile m_profiler;
            ItemTemperature m_item;
            ListeTemperature m_list;
    };
}

#endif