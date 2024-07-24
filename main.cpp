#include "model.h"
#include <iostream>


using namespace std;

int main()
{
    try {
        //Model model;
        GameObject g(5, 4, 8, 33, "tank.img");
        GameObject g1(g);

        GameObject g2;
        g2 = g;
    }
    catch (const char* msg){
        cout << msg << endl;
    }
    return 0;
}
