#include "model.h"
#include <iostream>


using namespace std;

int main()
{
    try {
        Model model;
    }
    catch (const char* msg){
        cout << msg << endl;
    }
    return 0;
}
