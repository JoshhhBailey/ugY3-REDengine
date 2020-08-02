///	@Transform.h
///	Transform component that handles the translation, rotation and scaling of entities

#include <memory>
#include "Transform.h"

//Additional file includes
#include "Entity.h"

#include <glm/ext.hpp>

namespace RED
{
/*void Transform::Translate(glm::mat4 &model)
{
	//Translate object left
	if (input->KeyHeld(SDL_SCANCODE_A))
	{
		model = glm::translate(model, glm::vec3(movementSpeed, 0.0f, 0.0f));
		movementSpeed -= 0.01f;
	}
	//Translate object right
	if (input->KeyHeld(SDL_SCANCODE_D))
	{
		model = glm::translate(model, glm::vec3(movementSpeed, 0.0f, 0.0f));
		movementSpeed += 0.01f;
	}
	//Translate object down
	if (input->KeyHeld(SDL_SCANCODE_S))
	{
		model = glm::translate(model, glm::vec3(0.0f, movementSpeed, 0.0f));
		movementSpeed -= 0.01f;
	}
	//Translate object up
	if (input->KeyHeld(SDL_SCANCODE_W))
	{
		model = glm::translate(model, glm::vec3(0.0f, movementSpeed, 0.0f));
		movementSpeed += 0.01f;
	}
	
}

void Transform::Rotate(glm::mat4 &model)
{
	if (input->KeyHeld(SDL_SCANCODE_A))
	{
		model = glm::rotate(model, glm::radians(rotationSpeed), glm::vec3(0, 1, 0));
		rotationSpeed -= 0.01f;
	}
	if (input->KeyHeld(SDL_SCANCODE_D))
	{
		model = glm::rotate(model, glm::radians(rotationSpeed), glm::vec3(0, 1, 0));
		rotationSpeed += 0.01f;
	}
}

void Transform::Scale(glm::mat4 &model)
{
	//Scale object up
	if (input->KeyHeld(SDL_SCANCODE_UP))
	{
		
	}
	//Scale object down
	if (input->KeyHeld(SDL_SCANCODE_DOWN))
	{
		
	}
}*/

	//Constructor
	Transform::Transform()
	{
	}

	//Destructor
	Transform::~Transform()
	{
	}

	void Transform::Translate(float x, float y, float z)
	{
		position += glm::vec3(x, y, z);		//Add position to current position values
	}

	void Transform::Rotate(float x2, float y2, float z2)
	{
		rotation += glm::vec3(x2, y2, z2);	//Add rotation to current rotation values
	}

	glm::mat4 Transform::getModelMatrix()
	{
		//Calculations for model matrix
		rotationMat = glm::rotate(glm::mat4(1.0f), rotation.y, glm::vec3(1.0f, 0.0f, 0.0f));
		rotationMat = glm::rotate(rotationMat, rotation.x, glm::vec3(0.0f, 1.0f, 0.0f));
		rotationMat = glm::rotate(rotationMat, rotation.z, glm::vec3(0.0f, 0.0f, 1.0f));
		modelMat = glm::translate(glm::mat4(1.0f), position) * rotationMat * glm::scale(glm::mat4(1), scale);
		return modelMat;
	}

	glm::mat4 Transform::getViewMatrix()
	{
		return glm::inverse(getModelMatrix());
	}
}