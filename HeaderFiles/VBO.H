#ifndef VBO_H
#define VBO_H

#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <iostream>
#include <vector>

class VBO
{
public:


	unsigned int ID;
	VBO();
	void Bind();
	void BindBufferData(float size, std::vector<glm::vec3> &vertex);
	void UnBind();
	void Delete();
	inline int GetID()
	{
		return ID;
	}
};

#endif