
#ifndef CPPMODEL_LISTE_HPP
#define CPPMODEL_LISTE_HPP

#include <string>
#include <vector>

namespace cppmodel
{

    //
    // @brief item structure
    //
    //
    typedef struct
    {
        int index;
        int port;
        std::string timestamp;
        std::string type;
        float value;
    } Item;

    typedef std::vector<Item> VectorItem;

    //
    // @brief Liste Class
    //
    //
    class Liste
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
            Liste();
            ~Liste();
            VectorItem items();
            Item itemAt(int ix);
            void resetAll();
            bool removeAt(int ix);
            void appendItem(Item item);
            bool setItemAt(int ix, Item item);
            int getSize();
            int getMinValue();
            int getMinPort();
            int getMinIndex();
            int getMaxValue();
            int getMaxPort();
            int getMaxIndex();
            void displayAt(int ix);
            void displayAll();
            Liste &setView(Views mode);
            Liste &setOrder(Directions direction);
            Liste &sortByIndex();
            Liste &sortByPort();
            Liste &sortByValue();
            Liste &sortByPortAndValue();
            Liste &filterByPort(int portFilter);
            Liste &filterByValue(int valueFilter);

        private:
            Directions order;
            Views view;
            VectorItem itemList;
            VectorItem filteredList;
    };

}
#endif