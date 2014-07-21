#include <iostream>
#include "IsWin64.h"

using namespace std;

int main()
{
    string str = "";
    if(Is64BitWindows())
    {
        str = "64bit\n";
    }
    else
    {
        str = "32bit\n";
    }


    cout << str << endl;
    return 0;
}
