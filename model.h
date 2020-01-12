
#include <iostream>
#include <string>
#include <vector>

using namespace std;

/**
 * @brief item structure 
 * 
 */
typedef struct
{
    int index;
    int port;
    string timestamp;
    string type;
    float value;
} Item;

typedef vector<Item> VectorItem;

/**
 * @brief Liste Class
 * 
 */
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
    void sortByIndex();
    void sortByPort();
    void sortByValue();
    void sortByPortAndValue();
    int getSize();
    int getMinValue();
    int getMinPort();
    int getMinIndex();
    int getMaxValue();
    int getMaxPort();
    int getMaxIndex();
    void filterByPort(int portFilter);
    void filterByValue(int valueFilter);
    void displayFiltered();
    void displayAt(int ix);
    void displayAll();
    void setOrder(Directions direction);
    void setView(Views mode);

private:
    Directions order;
    Views view;
    VectorItem itemList;
    VectorItem filteredList;
};