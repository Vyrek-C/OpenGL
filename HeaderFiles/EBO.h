#pragma once

#include <GLFW/glfw3.h>
#include <glad/glad.h>

class EBO
{
public:
	EBO();
	GLuint ID;
	void Bind(GLuint* indicies, GLsizeiptr size);
	void UnBind();
	void Delete();
};