
#ifndef CPPMODEL_DEMO_HPP
#define CPPMODEL_DEMO_HPP

#include <string>
#include <iostream>
#include "../profile/profile.hpp"
#include "../model/liste_temperature.hpp"

namespace cppmodel
{
    class Demo
    {

        public:
            Demo(Profile &profiler, ItemTemperature &item, ListeTemperature &list);
            void populateList();
            void appendItem();
            void sortByIndex();
            void sortByPort();
            void sortByValue();
            void minima();
            void maxima();
            void filterItems();

        private:
            void println(std::string msg);
            Profile m_profiler;
            ItemTemperature m_item;
            ListeTemperature m_list;
    };
}

#endif