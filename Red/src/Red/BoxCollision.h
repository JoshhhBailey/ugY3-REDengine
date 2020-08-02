/// @BoxCollision.h
/// Checks if one object is colliding with another

#ifndef _BOXCOLLISION_H_
#define _BOXCOLLISON_H_

#include <memory>
#include <iostream>

//Additional file includes
#include "Component.h"

namespace RED
{
	class BoxCollision : public Component   //Inheritance from component
	{
	public:

		~BoxCollision();   // Deconstructor for BoxCollision

		bool checkCollisions(std::shared_ptr<Entity> otherEntity);   // Check collisions function for BoxCollision component
	};
}
#endif //_BOXCOLLISION_H_