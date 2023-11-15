#include "Cannon.h"

#include "GameObjectEnum.h"
#include "Ball.h"
Cannon::Cannon(float sizeX, float sizeY, float posX, float posY, float speed) : GameObject(sizeX, sizeY, posX, posY, speed,GoLabel::cannon)
{
    this->setOriginPointOnBase(); // défini l'origine du canon
    _oldAngle = 90.f;
    _angle = 90.f;
}

Cannon::Cannon() : Cannon(50.f, 100.f, 1920 / 2, 1080 * 0.9, 90.f) {};

void Cannon::move(Math::Vector2 mouseVector) 
{
    _oldAngle = Math::Vector2::leftVector.getAngle(mouseVector) - _angle;
    _angle = Math::Vector2::leftVector.getAngle(mouseVector);
    this->rotateShape(_oldAngle);
}

void Cannon::fire(Math::Vector2 mouseVector, Ball* o_ball)
{
    float x = getPos().x - (o_ball->getRadius() / 2);
    float y = getPos().y - (o_ball->getRadius() / 2);

    o_ball->setPos(x, y);
    o_ball->setVector(mouseVector.x, mouseVector.y);
}