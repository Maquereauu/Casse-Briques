#include "Cannon.h"

Cannon::Cannon(float sizeX, float sizeY, float posX, float posY, float speed) : GameObject(sizeX, sizeY, posX, posY, speed)
{
    this->setOriginPointOnBase(); // défini l'origine du canon
    _oldAngle = 90.f;
    _angle = 90.f;
}

void Cannon::cannonMove(Math::Vector2 mouseVector) 
{
    _oldAngle = Math::Vector2::leftVector.getAngle(mouseVector) - _angle;
    _angle = Math::Vector2::leftVector.getAngle(mouseVector);

    this->rotateShape(_oldAngle);
}

void Cannon::cannonFire(Math::Vector2 mouseVector, Ball o_ball)
{
   o_ball.Vector()
}