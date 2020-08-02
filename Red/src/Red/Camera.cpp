/// @Camera.cpp
///	Calculates the projection matrix

#include "Camera.h"

namespace RED
{
void Camera::Initialise()
{
}

glm::mat4 Camera::getProjectionMatrix()
{
	return glm::perspective(glm::radians(45.0f), (float)400 / (float)800, 0.1f, 100.f);		//Projection matrix calculation, based on screen width and height
}
}