
#ifndef CPPMODEL_LISTE_TEMPERATURE_HPP
#define CPPMODEL_LISTE_TEMPERATURE_HPP

#include <string>
#include <vector>
#include "item_temperature.hpp"
#include "item_comparator.hpp"

namespace cppmodel
{

    typedef std::vector<ItemTemperature> VectorItem;

    //
    // @brief Liste Class
    //
    //
    class ListeTemperature
    {

        public:
            enum Directions
            {
                ASC,
                DESC
            };
            enum Views
            {
                MAIN,
                FILTERED
            };
            ListeTemperature();
            ~ListeTemperature();
            VectorItem items();
            ItemTemperature itemAt(unsigned int ix);
            void resetAll();
            bool removeAt(unsigned int ix);
            void appendItem(ItemTemperature item);
            bool setItemAt(unsigned int ix, ItemTemperature item);
            int getSize();
            int getMinValue();
            int getMinPort();
            int getMinIndex();
            int getMaxValue();
            int getMaxPort();
            int getMaxIndex();
            void displayAt(unsigned int ix);
            void displayAll();
            bool &indexComparator(const ItemTemperature &i1,const ItemTemperature &i2);
            ListeTemperature &setView(Views mode);
            ListeTemperature &setOrder(Directions direction);
            ListeTemperature &sortByIndex();
            ListeTemperature &sortByPort();
            ListeTemperature &sortByValue();
            ListeTemperature &sortByPortAndValue();
            ListeTemperature &filterByPort(int portFilter);
            ListeTemperature &filterByValue(int valueFilter);

        private:
            Directions order;
            Views view;
            VectorItem _iV;
            VectorItem filteredList;
    };

}
#endif