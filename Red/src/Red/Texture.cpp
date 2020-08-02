/// @Texture.cpp
/// Handles reading in a texture and extracting the data of the texture

#include "Texture.h"

#include <stb_image/stb_image.h>

Texture::Texture(std::string path)
{
	int w = 0;	//Texture width
	int h = 0;	//Texture height
	int channels = 0;

	unsigned char *data = stbi_load(path.c_str(), &w, &h, &channels, 4);

	//If texture data is false, throw exception
	if (!data)
	{
		throw std::exception();
	}

	size.x = w;
	size.y = h;

	glGenTextures(1, &id);

	//If texture id is false, throw exception
	if (!id)
	{
		throw std::exception();
	}

	glBindTexture(GL_TEXTURE_2D, id);
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, w, h, 0, GL_RGBA, GL_UNSIGNED_BYTE, data);
	free(data);
	glGenerateMipmap(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, 0);
}

//Return texture size
glm::vec2 Texture::getSize()
{
	return size;
}

//Return texture id
GLuint Texture::getId()
{
	return id;
}
