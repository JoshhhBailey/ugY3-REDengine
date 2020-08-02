/// @Component.cpp
/// Added to entities containing a component type

#include "Component.h"

//Additional file includes
#include "Entity.h"
#include "Transform.h"

namespace RED
{

Component::~Component() { }

//Functions to be overidden by different classes
void Component::onInit() { }
void Component::onBegin() { }
void Component::onTick() { }
void Component::onDisplay() { }

std::shared_ptr<Entity> Component::getEntity()
{
	return entity.lock();
}

std::shared_ptr<Core> Component::getCore()
{
	return getEntity()->getCore();
}

}
