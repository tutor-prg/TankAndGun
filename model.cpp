#include "model.h"
#include "gameobject.h"

Model::Model()
{
    GameObject tank(3, 4, 10.3, 0.0, "tank.img");
    GameObject gun(3, 4, 10.3, 0.0, "gun.img");

    tank.show();
    gun.show();


    GameObject gun2;
    gun2 = gun; //Todo ������� ��������� ��ﳿ(���������)

    gun = gun; //������ ���������. � ���� ���� ��������...

//    gameObjects.push_back(tank); //!!!! ���� ������������ ������� ��ﳿ
//    gameObjects.push_back(gun);  //!!! ������� ���������� ����
}

Model::~Model()
{
    //dtor
}
