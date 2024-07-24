#include "model.h"
#include "gameobject.h"

Model::Model()
{
    GameObject tank(3, 4, 10.3, 0.0, "tank.img");
    GameObject gun(3, 4, 10.3, 0.0, "gun.img");

    tank.show();
    gun.show();


    GameObject gun2;
    gun2 = gun; //Todo Зробити операторо копії(присвоєння)

    gun = gun; //Перший почистили. І нема чого копіювати...

//    gameObjects.push_back(tank); //!!!! Нема конструктора глибокої копії
//    gameObjects.push_back(gun);  //!!! Зробити наступного разу
}

Model::~Model()
{
    //dtor
}
