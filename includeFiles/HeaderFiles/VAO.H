#pragma once

#include <glad/glad.h>
#include <GLFW/glfw3.h>

class VAO
{
public:
	unsigned int ID;
	VAO();
	void LinkVBO(GLuint index, GLsizei stride, const void* pointer);
	void Bind();
	void UnBind();
	void Delete();
	inline int GetID()
	{
		return ID;
	}
};