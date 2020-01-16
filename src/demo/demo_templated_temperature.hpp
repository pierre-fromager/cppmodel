
#ifndef CPPMODEL_DEMO_TEMPLATED_TEMPERATURE_HPP
#define CPPMODEL_DEMO_TEMPLATED_TEMPERATURE_HPP

#include <string>
#include <iostream>
#include "../profile/profile.hpp"
#include "../model/item_temperature.hpp"
#include "../model/liste.hpp"

namespace cppmodel
{
    class DemoTemplatedTemperature
    {

        public:
            DemoTemplatedTemperature(Profile &profiler, ItemTemperature &item, Liste<ItemTemperature> &list);
            void run();

        private:
            void println(std::string msg);
            void populateList();
            void appendItem();
            void sortByIndex();
            void sortByPort();
            void sortByValue();
            void minima();
            void maxima();
            void filterItems();
            Profile m_profiler;
            ItemTemperature m_item;
            Liste<ItemTemperature> m_list;
    };
}

#endif