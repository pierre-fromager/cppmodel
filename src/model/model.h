
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
    int getSize();
    int getMinValue();
    int getMinPort();
    int getMinIndex();
    int getMaxValue();
    int getMaxPort();
    int getMaxIndex();
    void displayAt(int ix);
    void displayAll();
    Liste& setView(Views mode);
    Liste& setOrder(Directions direction);
    Liste& sortByIndex();
    Liste& sortByPort();
    Liste& sortByValue();
    Liste& sortByPortAndValue();
    Liste& filterByPort(int portFilter);
    Liste& filterByValue(int valueFilter);

private:
    Directions order;
    Views view;
    VectorItem itemList;
    VectorItem filteredList;
};