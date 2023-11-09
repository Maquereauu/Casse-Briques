#include "Cannon.h"

Cannon::Cannon(float sizeX, float sizeY, float posX, float posY, float speed) : GameObject(sizeX, sizeY, posX, posY, speed)
{
    this->setOriginPointOnBase(); // défini l'origine du canon
}

void Cannon::cannonMove(Math::Vector2 mouseVector, float* oldAngle, float* angle) 
{
    *oldAngle = Math::Vector2::leftVector.getAngle(mouseVector) - *angle;
    *angle = Math::Vector2::leftVector.getAngle(mouseVector);

    this->rotateShape(*oldAngle);
}