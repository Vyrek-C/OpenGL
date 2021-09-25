#pragma once

#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <vector>

class EBO
{
public:
	EBO();
	GLuint ID;
	void Bind();
	void BindBufferData(std::vector<unsigned int> indicies);
	void UnBind();
	void Delete();
};