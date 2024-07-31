#ifndef MODEL_H
#define MODEL_H
#include "gameobject.h"
#include <vector>

using namespace std;

class Model
{
    vector<GameObject> gameObjects;
public:
    Model();
    virtual ~Model();
};

#endif // MODEL_H
