#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H

class GameObject
{
    double x, y;
    int h, w;
    char** matr;
    double speedX, speedY;

public:
    GameObject();
    GameObject(double y, double x, double speed, double angleDeg, const char* fileName);
    GameObject(const GameObject& other);

    void show() const;
    virtual ~GameObject();
};

#endif // GAMEOBJECT_H
