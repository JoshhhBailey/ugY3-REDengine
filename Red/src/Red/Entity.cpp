/// @Entity.cpp
/// ///	Handles adding components, displaying and updating entities

#include "Entity.h"

//Additional file includes
#include "Transform.h"
#include "Component.h"

namespace RED
{

std::shared_ptr<Core> Entity::getCore()
{
	return core.lock();
}

void Entity::Update()
{
	//Iterate through vector of components
	for (std::vector<std::shared_ptr<Component> >::iterator it = components.begin();
		it != components.end(); it++)
	{
		if (!(*it)->began)
		{
			(*it)->onBegin();
			(*it)->began = true;
		}
		//Update entities
		(*it)->onTick();
	}
}

void Entity::Display()
{
	//Iterate through vector of components
	for (std::vector<std::shared_ptr<Component> >::iterator it = components.begin();
		it != components.end(); it++)
	{
		//Display entities
		(*it)->onDisplay();
	}
}

void Entity::SetTransformPositions()
{
	addComponent<RED::Transform>()->setPosition(0.0f, 0.0f, -10.0f);	//Set entity default position
	getComponent<RED::Transform>()->setRotation(0.0f, 0.0f, 0.0f);		//Set entity default rotation
	getComponent<RED::Transform>()->setScale(1.0f, 1.0f, 1.0f);			//Set entity default scale
}
}