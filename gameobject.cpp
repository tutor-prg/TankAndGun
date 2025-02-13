#include "common.h"
#include "gameobject.h"
#include <fstream>
#include <string>
#include <iostream>
#include <math.h>

using namespace std;

GameObject::GameObject()
{
    x = 0;
    y = 0;
    h = 0;
    w = 0;
    speedX = 0;
    speedY = 0;
    matr = NULL;
   // cout << "--c1--" << endl;
}

GameObject::GameObject(double y, double x, double speed, double angleDeg, const char* fileName)
{
    ifstream in(fileName);
    if (!in)
    {
        throw "cannot open file";
    }
    in >> h >> w;
    string s;
    getline(in, s);
    //cout << s << endl;

    matr = new char*[h];
    for (int i=0; i<h; i++)
    {
        matr[i] = new char[w];
    }

    for (int i=0; i<h; i++)
    {
        for (int j=0; j<w; j++)
        {
            matr[i][j] = 32;//space
        }
    }

    for (int i=0; i<h; i++)
    {
        getline(in, s);
        for (int j=0; j<s.length(); j++)
        {
            matr[i][j] = s[j];
        }
    }

    this->x = x;
    this->y = y;
    speedX = speed * cos(degToRad(angleDeg));
    speedY = speed * sin(degToRad(angleDeg));
    name = fileName;
    //cout << "--c2--" << name << endl;
}

GameObject::GameObject(const GameObject& other)
{
    x = other.x;
    y = other.y;
    h = other.h;
    w = other.w;
    speedX = other.speedX;
    speedY = other.speedY;

    matr = new char*[h];
    for (int i=0; i<h; i++)
    {
        matr[i] = new char[w];
    }

    for (int i=0; i<h; i++)
    {
        for (int j=0; j<w; j++)
        {
            matr[i][j] = other.matr[i][j];
        }
    }
    name = other.name;
    //cout << "--cc_go--" << name << endl;
}

GameObject& GameObject::operator=(const GameObject& other){
    if (this == &other) return *this;
    if (matr != NULL)
    {
        for (int i=0; i<h; i++)
        {
            delete[] matr[i];
        }
        delete [] matr;
    }

    x = other.x;
    y = other.y;
    h = other.h;
    w = other.w;
    speedX = other.speedX;
    speedY = other.speedY;

    matr = new char*[h];
    for (int i=0; i<h; i++)
    {
        matr[i] = new char[w];
    }

    for (int i=0; i<h; i++)
    {
        for (int j=0; j<w; j++)
        {
            matr[i][j] = other.matr[i][j];
        }
    }
   // cout << "fun = " << endl;
    name = other.name;
    return *this;
}

void GameObject::show() const
{
    for (int i=0; i<h; i++)
    {
        for (int j=0; j<w; j++)
        {
            cout << matr[i][j];
        }
        cout << endl;
    }
}

GameObject::~GameObject()
{
    if (matr != NULL)
    {
        for (int i=0; i<h; i++)
        {
            delete[] matr[i];
        }
        delete [] matr;
        //cout << "--d--" << name << endl;
    }
}
