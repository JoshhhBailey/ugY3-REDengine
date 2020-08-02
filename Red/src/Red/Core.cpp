/// @Core.cpp
/// Where everything within the engine runs, main game loop

#include <GL/glew.h>
#include <glm/ext.hpp>
#include <GLM/gtc/type_ptr.hpp>
#include <GLM/gtc/matrix_transform.hpp>

#include <iostream>
#include "Core.h"

//Additional file includes
#include "Entity.h"
#include "VertexBuffer.h"
#include "VertexArray.h"
#include "ShaderProgram.h"
#include "Texture.h"
#include "Screen.h"
#include "Camera.h"
#include "Transform.h"
#include "Environment.h"
#include "BoxCollision.h"

namespace RED
{
std::shared_ptr<Core> Core::initialize()
{
	std::shared_ptr<Core> rtn = std::make_shared<Core>();
	rtn->loop = false;
	rtn->self = rtn;

	//Initialise screen
	rtn->window.Initialise();

	bool quit = false;

	//OpenAL audio setup, throw exceptions if doesn't load in correctly
	rtn->device = alcOpenDevice(NULL);

	if (!rtn->device)
	{
		throw std::exception();
	}

	rtn->context = alcCreateContext(rtn->device, NULL);

	if (!rtn->context)
	{
		alcCloseDevice(rtn->device);
		throw std::exception();
	}

	if (!alcMakeContextCurrent(rtn->context))
	{
		alcDestroyContext(rtn->context);
		alcCloseDevice(rtn->device);
		throw std::exception();
	}

	return rtn;
}

void Core::Start(std::shared_ptr<Entity> player, std::shared_ptr<Entity> enemy, std::shared_ptr<Entity> enemy2, std::shared_ptr<Entity> enemy3, std::shared_ptr<Entity> enemy4, std::shared_ptr<Entity> enemy5)
{
	loop = true;

	while (loop)
	{
		SDL_Event event = { 0 };

		while (SDL_PollEvent(&event))
		{
			if (event.type == SDL_QUIT)
			{
				loop = false;
			}
		}

		score++;	//Increment score every frame
		std::cout << "Score: " << score << std::endl;	//Output score to console

		//List of cameras within the scene stored in a vector of entities
		std::vector < std::shared_ptr<Entity>> cameras;

		//Clears screen
		window.ClearBuffer();

		//Iterate through entities
		for (std::vector<std::shared_ptr<Entity> >::iterator it = entities.begin();
			it != entities.end(); it++)
		{
			//Update entities
			(*it)->Update();

			for (std::vector<std::shared_ptr<Entity> >::iterator it2 = entities.begin();
				it2 != entities.end(); it2++)
			{
				if ((*it)->checkComponent<BoxCollision>() == false || (*it2)->checkComponent<BoxCollision>() == false || (*it) == (*it2))
				{
					continue;
				}
				else
				{
					if ((*it)->getComponent<BoxCollision>()->checkCollisions(*it2) == true)
					{
						Stop();
					}
				}
			}

			//If entity contains a camera component
			if ((*it)->checkComponent<Camera>() == true)
			{
				//Push that into into cameras vector
				cameras.push_back(*it);
			}
		}

		//Iterate through cameras vector
		for (std::vector<std::shared_ptr<Entity> >::iterator it = cameras.begin();
			it != cameras.end(); it++)
		{
			SetCurrentCamera((*it)->getComponent<Camera>());
			//Display cameras
			(*it)->Display();
		}

		//Iterate through entities
		for (std::vector<std::shared_ptr<Entity> >::iterator it = entities.begin();
			it != entities.end(); it++)
		{
			//Display entities
			(*it)->Display();
		}

		enemy->getComponent<Transform>()->Translate(0.0f/**getDeltaTime()*/, -0.01f, 0.0f);
		enemy2->getComponent<Transform>()->Translate(0.0f/**getDeltaTime()*/, -0.01f, 0.0f);
		enemy3->getComponent<Transform>()->Translate(0.0f/**getDeltaTime()*/, -0.01f, 0.0f);
		enemy4->getComponent<Transform>()->Translate(0.0f/**getDeltaTime()*/, -0.01f, 0.0f);
		enemy5->getComponent<Transform>()->Translate(0.0f/**getDeltaTime()*/, -0.01f, 0.0f);

		//Update keyboard inputs
		input->UpdateKeyboard();

		//If 'Escape' is pressed
		if (input->KeyPressed(SDL_SCANCODE_ESCAPE))
		{
			//Exit program
			Stop();
		}


		//If "A" key is held
		if (input->KeyHeld(SDL_SCANCODE_A))
		{
			//Move player left
			player->getComponent<Transform>()->Translate(-1.0f/**getDeltaTime()*/, 0.0f, 0.0f);
		}
		//If "D" key is held
		if (input->KeyHeld(SDL_SCANCODE_D))
		{
			//Move player right
			player->getComponent<Transform>()->Translate(1.0f/**getDeltaTime()*/, 0.0f, 0.0f);
		}
		window.SwapScreen();

	}
}

void Core::Stop()
{
	//Close audio
	alcMakeContextCurrent(NULL);
	alcDestroyContext(context);
	alcCloseDevice(device);

	//End game loop
	loop = false;
}

std::shared_ptr<Entity> Core::addEntity()
{
	std::shared_ptr<Entity> rtn = std::make_shared<Entity>();
	entities.push_back(rtn);		//Push into entities vector
	rtn->SetTransformPositions();	//Setup its transform defaults
	rtn->addComponent<Transform>();	//Give entity a transform component
	rtn->getComponent<Transform>()->setScale(1.0f, 1.0f, 1.0f);	//Set scale
	rtn->self = rtn;
	rtn->core = self;

	return rtn;
}

void Core::SetCurrentCamera(std::shared_ptr<Camera> _camera)
{
	currentCamera = _camera;
}

std::shared_ptr<Camera> Core::GetCurrentCamera()
{
	return currentCamera.lock();
}
}