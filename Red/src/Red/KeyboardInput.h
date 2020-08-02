///	@KeyboardInput.h
///	Reads the keyboard for inputs, knows when a key is pressed, held and released

#ifndef _KEYBOARDINPUT_H_
#define _KEYBOARDINPUT_H_

#include <SDL2/SDL.h>
#include <map>

namespace RED
{

class KeyboardInput
{
public:
	//Constructor and Destructor
	KeyboardInput();
	~KeyboardInput();

	//Check what keys are being pressed every frame
	void UpdateKeyboard();

	//Keystate functions
	bool KeyPressed(SDL_Scancode _key);
	bool KeyHeld(SDL_Scancode _key);
	bool KeyReleased(SDL_Scancode _key);

private:
	const Uint8* currentKeyState;

	//Number of keys stored
	int numKeys;
	
	//Arrays where keys are stored
	Uint8* currentFrameKeys;
	Uint8* previousFrameKeys;

};
}
#endif //_KEYBOARDINPUT_H_