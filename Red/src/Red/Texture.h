/// @Texture.h
/// Handles reading in a texture and extracting the data of the texture

#ifndef _TEXTURE_H_
#define _TEXTURE_H_

#include <GL/glew.h>
#include <glm/glm.hpp>

#include <string>

class Texture
{
	GLuint id;
	glm::vec2 size;				//Size of texture

public:
	Texture(std::string path);	//Read in texture file path
	glm::vec2 getSize();		//Get texture size
	GLuint getId();
};
#endif //_TEXTURE_H_