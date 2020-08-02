///	@Component.h
/// Added to entities containing a component type

#ifndef _COMPONENT_H_
#define _COMPONENT_H_

#include <memory>

namespace RED
{
//Forward declaration of classes
class Entity;
class Core;

class Component
{
	friend class Entity;
public:
	virtual ~Component();
	std::shared_ptr<Core> getCore();
	std::shared_ptr<Entity> getEntity();

private:
	std::weak_ptr<Entity> entity;
	bool began;

	//Virtual functions to override the original functions within main
	virtual void onInit();
	virtual void onBegin();
	virtual void onTick();
	virtual void onDisplay();
};
}
#endif //_COMPONENT_H_