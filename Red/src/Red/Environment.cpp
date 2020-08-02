///	@Environment.h
///	Calculates delta time so the game runs the same speed no matter the FPS

#include "Environment.h"

namespace RED
{
//Variable initialisation
void Environment::Initialise()
{
	time = SDL_GetTicks();
	diff = time - lastTime;
	deltaTime = (diff / 1000.0f);
	lastTime = time;

	idealTime = (1.0f / 60.0f);
}

//Calculate delta time
float Environment::GetDeltaTime()
{
	if (idealTime > deltaTime)
	{
		SDL_Delay((idealTime - deltaTime) * 1000.0f);
	}

	return deltaTime;
}
}