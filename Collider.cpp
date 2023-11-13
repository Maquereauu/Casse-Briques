#include "Collider.h"

#include "AABBCollider.h"
#include "CircleCollider.h"

Collider::Collider(float posX, float posY, float sizeX, float sizeY)
{
	_posX = posX;
	_posY = posY;
	_sizeX = sizeX;
	_sizeY = sizeY;
}

Collider::Collider(float posX, float posY, float radius)
{
	_radius = radius;
	posX = posX;
	posY = posY;
}


bool Collider::colliding(Collider* o_OtherCollider) 
{

	const AABBCollider* AABB = dynamic_cast<AABBCollider*>(o_OtherCollider);
	if (AABB != nullptr) 
	{
		return isColliding(*AABB);
	}

	const CircleCollider* circle = dynamic_cast<CircleCollider*>(o_OtherCollider);
	if (circle != nullptr)
	{
		return isColliding(*circle);
	}

}

std::string Collider::collidingSide(Collider* o_OtherCollider)
{

	const AABBCollider* AABB = dynamic_cast<AABBCollider*>(o_OtherCollider);
	if (AABB != nullptr)
	{
		return checkCollidingSide(*AABB);
	}

	const CircleCollider* circle = dynamic_cast<CircleCollider*>(o_OtherCollider);
	if (circle != nullptr)
	{
		return checkCollidingSide(*circle);
	}

}

