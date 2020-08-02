/// @Screen.cpp
/// Initialises SDL, creates and window, handles clearing the screen

#include "Screen.h"

#include <iostream>
#include <GL/glew.h>

namespace RED
{
	//Setting window variable values
	int Screen::windowWidth = 400;
	int Screen::windowHeight = 800;
	int Screen::windowXpos = 100;
	int Screen::windowYpos = 100;

void Screen::Initialise()
{
	//Check SDL initialised correctly
	if (SDL_Init(SDL_INIT_VIDEO) < 0)
	{
		throw std::exception();
	}

	//Create an SDL window
	window = SDL_CreateWindow("RED Engine by Josh Bailey",
	GetWindowXPosition(), GetWindowYPosition(),
	GetWindowWidth(), GetWindowHeight(),
	SDL_WINDOW_RESIZABLE | SDL_WINDOW_OPENGL);

	//Check the window was created correctly
	if (!SDL_GL_CreateContext(window))
	{
		throw std::exception();
	}

	//Check GLEW initialised correctly
	if (glewInit() != GLEW_OK)
	{
		throw std::exception();
	}

	//Save memory by culling faces
	glFrontFace(GL_CCW);
	glEnable(GL_CULL_FACE);
	glEnable(GL_DEPTH_TEST);
}

void Screen::ClearBuffer()
{
	//Clear the screen, to free memory and so nothing draws over itself
	SDL_GetWindowSize(window, &windowWidth, &windowHeight);
	glViewport(0, 0, windowWidth, windowHeight);
	glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
}

void Screen::SwapScreen()
{
	SDL_GL_SwapWindow(window);
}

//Getter functions, just return variables
int Screen::GetWindowWidth()
{
	return windowWidth;
}

int Screen::GetWindowHeight()
{
	return windowHeight;
}
int Screen::GetWindowXPosition()
{
	return windowXpos;
}

int Screen::GetWindowYPosition()
{
	return windowYpos;
}
}