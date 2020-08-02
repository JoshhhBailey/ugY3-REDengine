/// @VertexArray.h
///	An array storing all VBO's of an object
/// Author: Karsten Pedersen

#ifndef _VERTEXARRAY_H_
#define _VERTEXARRAY_H_

#include <GL/glew.h>
#include <glm/glm.hpp>

#include <vector>
#include <string>

namespace RED
{

class VertexBuffer;

class VertexArray
{
	GLuint id;
	bool dirty;
	std::vector<VertexBuffer *> buffers;

	void splitStringWhitespace(std::string& input, std::vector<std::string>& output);
	void splitString(std::string& input, char splitter, std::vector<std::string>& output);

public:
	VertexArray();
	VertexArray(std::string path);
	void setBuffer(std::string attribute, VertexBuffer *buffer);
	int getVertexCount();
	GLuint getId();
};
}
#endif //_VERTEXARRAY_H_