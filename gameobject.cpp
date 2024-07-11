#include "common.h"
#include "gameobject.h"
#include <fstream>
#include <string>
#include <iostream>
#include <math.h>

using namespace std;

GameObject::GameObject()
{
    //ctor
}

GameObject::GameObject(double y, double x, double speed, double angleDeg, const char* fileName){
    ifstream in(fileName);
    if (!in) {
        throw "cannot open file";
    }
    in >> h >> w;
    string s;
    getline(in, s);
    //cout << s << endl;

    matr = new char*[h];
    for (int i=0; i<h; i++){
        matr[i] = new char[w];
    }

    for (int i=0; i<h; i++)
    {
        for (int j=0; j<w; j++)
        {
            matr[i][j] = 32;
        }
    }

    for (int i=0; i<h; i++){
        getline(in, s);
        for (int j=0; j<s.length(); j++){
            matr[i][j] = s[j];
        }
    }

    this->x = x;
    this->y = y;
    speedX = speed * cos(degToRad(angleDeg));
    speedY = speed * sin(degToRad(angleDeg));
}

void GameObject::show() const{
    for (int i=0; i<h; i++)
    {
        for (int j=0; j<w; j++)
        {
            cout << matr[i][j];
        }
        cout << endl;
    }
}

GameObject::~GameObject(){
    for (int i=0; i<h; i++){
        delete[] matr[i];
    }
    delete [] matr;
}
