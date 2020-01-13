
#ifndef CPPMODEL_DEMO_HPP
#define CPPMODEL_DEMO_HPP

#include <string>
#include <iostream>
#include "../profile/profile.hpp"
#include "../model/liste.hpp"

namespace cppmodel
{
    class Demo
    {

        public:
            Demo(Profile &profiler, Item &item, Liste &list);
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
            Item m_item;
            Liste m_list;
    };
}

#endif