///	@Core.h
///	Where everything within the engine runs

#ifndef _CORE_H_
#define _CORE_H_

#include <SDL2/SDL.h>
#include <AL/al.h>
#include <AL/alc.h>

#include <memory>
#include <vector>

//Additional file includes
#include "KeyboardInput.h"
#include "Screen.h"

namespace RED
{

//Forward declaration of classes
class Entity;
class Screen;
class Camera;
class Core
{
public:
	static std::shared_ptr<Core> initialize();

	void Start(std::shared_ptr<Entity> player, std::shared_ptr<Entity> enemy, std::shared_ptr<Entity> enemy2, std::shared_ptr<Entity> enemy3, std::shared_ptr<Entity> enemy4, std::shared_ptr<Entity> enemy5);	//Main core loop
	void Stop();	//Stop core running, close program

	//Camera setter and getter
	void SetCurrentCamera(std::shared_ptr<Camera> _camera);
	std::shared_ptr<Camera> GetCurrentCamera();

	std::shared_ptr<Entity> addEntity();

	//Allow keyboard inputs
	KeyboardInput* input = new KeyboardInput();

private:
	bool loop;	//Main loop

	std::vector<std::shared_ptr<Entity> > entities;	//Store all entities
	std::weak_ptr<Core> self;

	std::weak_ptr<Camera> currentCamera;	//Camera

	//Audio setup variables
	ALCdevice* device;
	ALCcontext* context;

	//Screen variables
	Screen window;
	std::shared_ptr<Screen> screen;

	int score = 0;	//Game score
};
}
#endif //_CORE_H_