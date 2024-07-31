#include "model.h"
#include "gameobject.h"

Model::Model()
{
    gameObjects.reserve(10);
    GameObject tank(3, 4, 10.3, 0.0, "tank.img");
    gameObjects.push_back(tank);

    GameObject gun(3, 4, 10.3, 0.0, "gun.img");
    gameObjects.push_back(gun);
}

Model::~Model()
{
    //dtor
}
