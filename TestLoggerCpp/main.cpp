#include <iostream>
#include <string>
#include <ctime>
#include "Test.h"

using namespace std;

inline string getCurrentDateTime( ){


    time_t     now = time(0);
    struct tm  tstruct;
    char       buf[80];
    tstruct = *localtime(&now);
    strftime(buf, sizeof(buf), "%Y-%m-%d.%X", &tstruct);

    return buf;

}


int main()
{

    cout << "Hello World!" << endl;
    string now = getCurrentDateTime();

    freopen("output.txt","aw",stdout);
    freopen("error.txt","aw",stderr);
    cout << now << " : OutPut message" << endl;
    cerr << now << " : Error Message" << endl;

    Test t;

    return 0;
}
