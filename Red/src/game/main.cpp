#include <Red/Red.h>

#include <iostream>

class TestScreen : public RED::Component
{
public:
	void onInit(std::string color)
	{
		//std::cout << "onInit " << color << std::endl;
	}

	void onBegin()
	{
		//std::cout << "onBegin" << std::endl;
	}

	void onTick()
	{
		//std::cout << "onTick" << std::endl;
	}

	void onDisplay()
	{
		//std::cout << "onTick" << std::endl;
	}
};

int main()
{
	std::shared_ptr<RED::Core> core = RED::Core::initialize();		//Initialise core
	std::shared_ptr<RED::Entity> MainCamera = core->addEntity();	//Create camera entity
	std::shared_ptr<RED::Entity> player = core->addEntity();		//Create player entity
	std::shared_ptr<RED::Sound> sound = std::make_shared<RED::Sound>("../resources/audio/game_audio.ogg");	//Load in audio

	std::shared_ptr<RED::Entity> enemy = core->addEntity();		//Create enemy
	std::shared_ptr<RED::Entity> enemy2 = core->addEntity();		//Create enemy
	std::shared_ptr<RED::Entity> enemy3 = core->addEntity();		//Create enemy
	std::shared_ptr<RED::Entity> enemy4 = core->addEntity();		//Create enemy
	std::shared_ptr<RED::Entity> enemy5 = core->addEntity();		//Create enemy

	//Play audio
	sound->Play();

	MainCamera->addComponent<RED::Camera>();	//Add camera component to camera entity
	MainCamera->getComponent<RED::Transform>()->Translate(0.0f, 0.0f, 0.0f);	//Initialise camera position

	std::shared_ptr<RED::MeshRenderer> meshrenderer = player->addComponent<RED::MeshRenderer>();	//Give player a mesh renderer component
	std::shared_ptr<RED::MeshRenderer> meshrenderer2 = enemy->addComponent<RED::MeshRenderer>();		//Give enemy a mesh renderer component
	std::shared_ptr<RED::MeshRenderer> meshrenderer3 = enemy2->addComponent<RED::MeshRenderer>();		//Give enemy a mesh renderer component
	std::shared_ptr<RED::MeshRenderer> meshrenderer4 = enemy3->addComponent<RED::MeshRenderer>();		//Give enemy a mesh renderer component
	std::shared_ptr<RED::MeshRenderer> meshrenderer5 = enemy4->addComponent<RED::MeshRenderer>();		//Give enemy a mesh renderer component
	std::shared_ptr<RED::MeshRenderer> meshrenderer6 = enemy5->addComponent<RED::MeshRenderer>();		//Give enemy a mesh renderer component


	//Initialise player position and scale
	player->getComponent<RED::Transform>()->Translate(0.0f, -5.0f, -20.0f);
	player->getComponent<RED::Transform>()->setScale(0.5f, 0.5f, 0.5f);
	
	player->addComponent<RED::BoxCollision>();	//Add box collider to player
	
	//Initialise enemy position and scale
	enemy->getComponent<RED::Transform>()->Translate(0.0f, 0.0f, -20.0f);
	enemy->getComponent<RED::Transform>()->setScale(0.25f, 0.25f, 0.25f);

	enemy2->getComponent<RED::Transform>()->Translate(1.0f, 5.0f, -20.0f);
	enemy2->getComponent<RED::Transform>()->setScale(0.25f, 0.25f, 0.25f);

	enemy3->getComponent<RED::Transform>()->Translate(2.0f, 10.0f, -20.0f);
	enemy3->getComponent<RED::Transform>()->setScale(0.25f, 0.25f, 0.25f);

	enemy4->getComponent<RED::Transform>()->Translate(-1.0f, 7.0f, -20.0f);
	enemy4->getComponent<RED::Transform>()->setScale(0.25f, 0.25f, 0.25f);

	enemy5->getComponent<RED::Transform>()->Translate(-2.0f, 11.0f, -20.0f);
	enemy5->getComponent<RED::Transform>()->setScale(0.25f, 0.25f, 0.25f);


	enemy->addComponent<RED::BoxCollision>();	//Add box collider to player
	enemy2->addComponent<RED::BoxCollision>();	//Add box collider to player
	enemy3->addComponent<RED::BoxCollision>();	//Add box collider to player
	enemy4->addComponent<RED::BoxCollision>();	//Add box collider to player
	enemy5->addComponent<RED::BoxCollision>();	//Add box collider to player
	
	core->Start(player, enemy, enemy2, enemy3, enemy4, enemy5);

	return 0;
}