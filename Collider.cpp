#include "Collider.h"


Collider::Collider(float sizeX, float sizeY, float posX, float posY, float speed) : GameObject(sizeX, sizeY, posX, posY, speed)
{

}

bool Collider::isColliding(const GameObject& object)
{

}

std::string Collider::checkCollidingSide(const GameObject& object)
{

}

bool Collider::ballIsColliding(const GameObject& object)
{

}

std::string Collider::ballCheckCollidingSide(const GameObject& object)
{

}

void Collider::collide(const std::vector<GameObject*>& list)
{

}

void Collider::ballCollide(const std::vector<GameObject*>& list)
{

}