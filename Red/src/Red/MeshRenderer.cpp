///	@MeshRenderer.cpp
///	Assigns an object, texture and shader to display to the screen

#include <iostream>
#include "MeshRenderer.h"

//Additional file includes
#include "VertexArray.h"
#include "VertexBuffer.h"
#include "ShaderProgram.h"
#include "Entity.h"
#include "Texture.h"
#include "Transform.h"
#include "Core.h"
#include "Camera.h"

#include <glm/ext.hpp>

namespace RED
{

void MeshRenderer::onInit()
{
	shape = std::make_shared<VertexArray>("../resources/models/curuthers.obj");		//Pointer to model file directory
	mat = std::make_shared<Texture>("../resources/textures/curuthers_diffuse.png");	//Pointer to texture file directory
	shader = std::make_shared<ShaderProgram>("../resources/shaders/simple.vert", "../resources/shaders/simple.frag");	//Pointer to vert and frag shader directories
}

void MeshRenderer::onDisplay()
{
	shader->setUniform("in_Model", getEntity()->getComponent<RED::Transform>()->getModelMatrix());	//Model matrix
	shader->setUniform("in_Projection", getCore()->GetCurrentCamera()->getProjectionMatrix());		//Projection matrix
	shader->setUniform("in_View", getCore()->GetCurrentCamera()->getEntity()->getComponent<RED::Transform>()->getViewMatrix());	//View matrix
	shader->setUniform("in_Texture", mat);

	//Draw model
	shader->draw(shape);
}

}
