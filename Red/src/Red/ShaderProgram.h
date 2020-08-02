///	@ShaderProgram.h
///	Handles shaders
///	Author: Karsten Pedersen

#ifndef _SHADERPROGRAM_H_
#define _SHADERPROGRAM_H_

#include <GL/glew.h>
#include <glm/glm.hpp>

#include <string>
#include <vector>
#include <memory>

class Texture;

namespace RED
{
class VertexArray;

struct Sampler
{
	GLint id;
	std::shared_ptr<Texture> texture;
};

class ShaderProgram
{
	GLuint id;
	std::vector<Sampler> samplers;

public:
	ShaderProgram(std::string vert, std::string frag);
	void draw(std::shared_ptr<VertexArray> vArray);
	void setUniform(std::string uniform, glm::vec4 value);
	void setUniform(std::string uniform, float value);
	void setUniform(std::string uniform, glm::mat4 value);
	void setUniform(std::string uniform, std::shared_ptr<Texture> texture);
	GLuint getId();

};
}
#endif //_SHADERPROGRAM_H_