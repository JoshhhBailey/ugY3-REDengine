///	@Environment.h
///	Calculates delta time so the game runs the same speed no matter the FPS

#ifndef _ENVIRONMENT_H_
#define _ENVIRONMENT_H_

#include <SDL2/SDL.h>

namespace RED
{
class Environment
{
public:
	void Initialise();		//Variable initialisation
	float GetDeltaTime();	//Return deltaTime

private:
	//Required variables to calculate deltaTime
	float time;
	float idealTime;
	float diff;
	float deltaTime;
	float lastTime;
};
}
#endif //_ENVIRONMENT_H_