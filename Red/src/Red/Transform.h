///	@Transform.h
///	Transform component that handles the translation, rotation and scaling of entities

#ifndef _TRANSFORM_H_
#define _TRANSFORM_H_

#define GLM_FORCE_CTOR_INIT
#include <GL/glew.h>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/glm.hpp>

#include <memory>

//Additional file includes
#include "Component.h"

namespace RED
{

class Transform : public Component	//Inheritance from component
{
public:
	/*void Translate(glm::mat4 &model);
	void Rotate(glm::mat4 &model);
	void Scale(glm::mat4 &model);
	float movementSpeed = 0.0f;
	float rotationSpeed = 0.0f;
	float scaleSize = 0.0f;*/

	//Constructor and destructor
	Transform();
	~Transform();

	void Translate(float x, float y, float z);
	void Rotate(float x2, float y2, float z2);

	//Model and view matrix getters
	glm::mat4 getModelMatrix();
	glm::mat4 getViewMatrix();

	//Position getter and setter
	glm::vec3 getPosition() { return position; }
	void setPosition(float x, float y, float z) { position.x = x; position.y = y; position.z = z; }   //Set default position of entity

	//Rotation getter and setter
	glm::vec3 getRotation() { return rotation; }
	void setRotation(float x2, float y2, float z2) { rotation.x = x2; rotation.y = y2; rotation.z = z2; }   //Set default rotation of entity

	//Scale getter and setter
	glm::vec3 getScale() { return scale; }
	void setScale(float x3, float y3, float z3) { scale.x = x3; scale.y = y3; scale.z = z3; }   //Set default scale of entity

	//Velocity getter and setter
	float getVelocity() { return velocity; } 
	void setVelocity(float _velocity) { velocity = _velocity; }   //Set velocity

private:
	/*KeyboardInput* input = new KeyboardInput();
	bool move;
	bool rotate;
	bool scale;*/

	//Variables to store position, rotation and scale data
	glm::vec3 position;
	glm::vec3 rotation;
	glm::vec3 scale;

	//Matrices
	glm::mat4 modelMat;
	glm::mat4 translationMat;
	glm::mat4 rotationMat;
	glm::mat4 scaleMat;

	float velocity;
};
}
#endif //_TRANSFORM_H_