
#include <string>
#include <iostream>
#include "../profile/profile.h"
#include "../model/model.h"

using namespace std;

class Demo
{

public:
    Demo(Profile &profiler, Item &item, Liste &list);
    void println(string msg);
    void populateList();
    void appendItem();
    void sortByIndex();
    void sortByPort();
    void sortByValue();
    void minima();
    void maxima();
    void filterItems();

private:
    Profile _profiler;
    Item _item;
    Liste _list;
};