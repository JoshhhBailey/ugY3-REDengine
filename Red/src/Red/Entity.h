///	@Entity.h
///	Handles adding components, displaying and updating entities

#ifndef _ENTITY_H_
#define _ENTITY_H_

#include <vector>
#include <memory>

//Definition created so code doesn't have to be retyped multiple times over
#define ADDCOMPONENT \
	std::shared_ptr<T> rtn = std::make_shared<T>(); \
	rtn->entity = self; \
	rtn->began = false; \
	components.push_back(rtn);

namespace RED
{

//Forward declaration of classes
class Core;
class Transform;
class Component;
class Entity
{
	friend class Core;
public:
	//Function that allows you to access a component attached to an entity
	template <typename T>
	std::shared_ptr<T> getComponent()
	{
		for (size_t i = 0; i < components.size(); i++)
		{
			std::shared_ptr<T> tst = std::dynamic_pointer_cast<T>(components.at(i));

			if (tst)
			{
				return tst;
			}
		}

		throw std::exception();
	}
	//Function that allows you to check if an entity has a specific component
	template <typename T>
	bool checkComponent()
	{
		for (size_t i = 0; i < components.size(); i++)
		{
			std::shared_ptr<T> tst = std::dynamic_pointer_cast<T>(components.at(i));

			if (tst)
			{
				return true;
			}
		}

		return false;
	}

	//Template to add first component to entity
	template <typename T>
	std::shared_ptr<T> addComponent()
	{
		ADDCOMPONENT
		rtn->onInit();

		return rtn;
	}
	//Template to add second component to entity
	template <typename T, typename A>
	std::shared_ptr<T> addComponent(A a)
	{
		ADDCOMPONENT
		rtn->onInit(a);

		return rtn;
	}
	//Template to add third component to entity
	template <typename T, typename A, typename B>
	std::shared_ptr<T> addComponent(A a, B b)
	{
		ADDCOMPONENT
		rtn->onInit(a, b);

		return rtn;
	}

	//Function to initially assign position, rotation, scale
	void SetTransformPositions();

	std::shared_ptr<Core> getCore();
	

private:
	std::weak_ptr<Entity> self;
	std::weak_ptr<Core> core;
	std::vector<std::shared_ptr<Component> > components;	//List of components

	void Update();		//Update entities
	void Display();		//Display entities
};
}
#endif //_ENTITY_H_