///	@Camera.h
///	Handles the camera component and gets the projection matrix

#ifndef _CAMERA_H_
#define _CAMERA_H_

#include <glm/ext.hpp>

//Additional file includes
#include "Component.h"

namespace RED
{
class Camera : public Component	//Inheritance from Component
{
public:
	//Functions
	void Initialise();
	glm::mat4 getProjectionMatrix();
};
}
#endif //_CAMERA_H_