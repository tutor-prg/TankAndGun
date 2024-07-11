#include "gameobject.h"
#include <iostream>

using namespace std;

int main()
{
    try {
        GameObject g(3, 4, 10.3, 12.0, "tank.img");
        g.show();
    }
    catch (const char* msg){
        cout << msg << endl;
    }
    return 0;
}
