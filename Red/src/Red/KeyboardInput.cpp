///	@KeyboardInput.cpp
///	Reads the keyboard for inputs, knows when a key is pressed, held and released

#include <iostream>
#include "KeyboardInput.h"

namespace RED
{

KeyboardInput::KeyboardInput()
{
	//Set cyrrentKeyState to get the current state of the keyboard
	currentKeyState = SDL_GetKeyboardState(&numKeys);

	//Create two arrays with 'numKeys' elements
	currentFrameKeys = new Uint8[numKeys];		//Keys pressed in current frame
	previousFrameKeys = new Uint8[numKeys];		//Keys pressed in previous frame
}

KeyboardInput::~KeyboardInput()
{
	//Delete arrays
	delete[] currentFrameKeys;		//Delete keys pressed in current frame
	delete[] previousFrameKeys;		//Delete keys pressed in previous frame
}

void KeyboardInput::UpdateKeyboard()
{
	//Store keys pressed from last frame in previousFrameKeys array
	std::memcpy(previousFrameKeys, currentFrameKeys, numKeys);				//Previous array, current array, array length
	//Overwrite currentFrameKeys array with the current keyboard state
	std::memcpy(currentFrameKeys, currentKeyState, numKeys);				//Current array, keyboard frame snapshot, array length
}

bool KeyboardInput::KeyPressed(SDL_Scancode _key)
{
	//If you were pressing '_key' this frame but not last frame
	if (currentFrameKeys[_key] && !previousFrameKeys[_key])
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool KeyboardInput::KeyHeld(SDL_Scancode _key)
{
	//If you were pressing '_key' last frame and still are this frame
	if (currentFrameKeys[_key] && previousFrameKeys[_key])
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool KeyboardInput::KeyReleased(SDL_Scancode _key)
{
	//If you were pressing '_key' last from but are no longer this frame
	if (!currentFrameKeys[_key] && previousFrameKeys[_key])
	{
		return true;
	}
	else
	{
		return false;
	}
}
}