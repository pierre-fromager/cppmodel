
#include <string>

using namespace std;

class Profile
{
    
public:
    Profile();
    void mark(string msg);
    void elapse();

private:
    double microtime();
    double in;
    double out;
    string msg;
};