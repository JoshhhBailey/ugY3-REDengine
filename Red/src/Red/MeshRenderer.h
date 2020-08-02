///	@MeshRenderer.h
///	Assigns an object, texture and shader to display to the screen

#ifndef _MESHRENDERER_H_
#define _MESHRENDERER_H_

#include <memory>

#include <glm/ext.hpp>
#include "Component.h"

class Texture;

namespace RED
{
//Forward declaration of classes
class Transform;
class VertexArray;
class ShaderProgram;

class MeshRenderer : public Component	//Inheritance from component
{
public:
  void onInit();

private:
  void onDisplay();

  //Variables that an object, texture and shader are applied to
  std::shared_ptr<VertexArray> shape;
  std::shared_ptr<ShaderProgram> shader;
  std::shared_ptr<Texture> mat;

  std::shared_ptr<VertexArray> shape2;

};
}
#endif //_MESHRENDERER_H_