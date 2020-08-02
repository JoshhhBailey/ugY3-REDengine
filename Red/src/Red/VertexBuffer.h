/// @VertexBuffer.h
/// Collects all the coordinate data of an object to be stored within a VAO
/// Author: Karsten Pedersen

#ifndef _VERTEXBUFFER_H_
#define _VERTEXBUFFER_H

#include <GL/glew.h>
#include <glm/glm.hpp>

#include <vector>

namespace RED
{

class VertexBuffer
{
	GLuint id;
	int components;
	std::vector<GLfloat> data;
	bool dirty;

public:
	VertexBuffer();
	void Add(glm::vec2 value);
	void Add(glm::vec3 value);
	void Add(glm::vec4 value);
	int getComponents();
	int getDataSize();
	GLuint getId();
};
}
#endif //_VERTEXBUFFER_H_