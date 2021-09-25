#ifndef VAO_H
#define VAO_H

#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <HeaderFiles/VBO.h>

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

#endif