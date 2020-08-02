/// @BoxCollision.h
/// Checks if one object is colliding with another

#include <glm/ext.hpp>

#include "BoxCollision.h"

//Additional file includes
#include "Entity.h"
#include "Transform.h"

namespace RED
{
	BoxCollision::~BoxCollision()
	{
	}

	// Using AABB collision detection
	bool BoxCollision::checkCollisions(std::shared_ptr<Entity> otherEntity)
	{
		// Uses two entities positions and scale to work out if theyre colliding by comparing each values. If collision has occured return true
		if (getEntity()->getComponent<Transform>()->getPosition().x <= (otherEntity->getComponent<Transform>()->getPosition().x + otherEntity->getComponent<Transform>()->getScale().x / 0.5f)
			&& getEntity()->getComponent<Transform>()->getPosition().x >= (otherEntity->getComponent<Transform>()->getPosition().x - otherEntity->getComponent<Transform>()->getScale().x / 0.5f))
		{
			if (getEntity()->getComponent<Transform>()->getPosition().y <= (otherEntity->getComponent<Transform>()->getPosition().y + otherEntity->getComponent<Transform>()->getScale().y / 0.5f)
				&& getEntity()->getComponent<Transform>()->getPosition().y >= (otherEntity->getComponent<Transform>()->getPosition().y - otherEntity->getComponent<Transform>()->getScale().y / 0.5f))
			{
				if (getEntity()->getComponent<Transform>()->getPosition().z <= (otherEntity->getComponent<Transform>()->getPosition().z + otherEntity->getComponent<Transform>()->getScale().z / 0.5f)
					&& getEntity()->getComponent<Transform>()->getPosition().z >= (otherEntity->getComponent<Transform>()->getPosition().z - otherEntity->getComponent<Transform>()->getScale().z / 0.5f))
				{
					// Takes entities velocity and reverses it so they move away from each other
					//getEntity()->getComponent<Transform>()->setVelocity(-getEntity()->getComponent<Transform>()->getVelocity());
					std::cout << "Collided" << std::endl;

					return true;
				}
			}
		}

		// If no collision has occured return false
		return false;
	}
}
