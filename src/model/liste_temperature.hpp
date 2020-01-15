
#ifndef CPPMODEL_LISTE_TEMPERATURE_HPP
#define CPPMODEL_LISTE_TEMPERATURE_HPP

#include <string>
#include <vector>
#include "item_temperature.hpp"

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
            ItemTemperature itemAt(int ix);
            void resetAll();
            bool removeAt(int ix);
            void appendItem(ItemTemperature item);
            bool setItemAt(int ix, ItemTemperature item);
            int getSize();
            int getMinValue();
            int getMinPort();
            int getMinIndex();
            int getMaxValue();
            int getMaxPort();
            int getMaxIndex();
            void displayAt(int ix);
            void displayAll();
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
            VectorItem itemList;
            VectorItem filteredList;
    };

}
#endif