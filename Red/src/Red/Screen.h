///	@Screen.h
///	Creates an SDL window, handles window position and dimensions, initialisation of SDL and clearing the buffer

#ifndef _SCREEN_H_
#define _SCREEN_H_

#include <SDL2/SDL.h>

namespace RED
{
class Screen
{
public:
	//Functions
	void Initialise();
	void ClearBuffer();
	void SwapScreen();

	//Getter functions
	int GetWindowWidth();
	int GetWindowHeight();
	int GetWindowXPosition();
	int GetWindowYPosition();

private:
	//Window dimension and position variables
	static int windowWidth;
	static int windowHeight;
	static int windowXpos;
	static int windowYpos;

	SDL_Window* window;
};
}
#endif //_SCREEN_H_