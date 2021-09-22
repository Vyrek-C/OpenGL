#include <glad/glad.h>
#include <EBO.h>
#include <GLFW/glfw3.h>
#include <glad/glad.h>


EBO::EBO()
{
	glGenBuffers(1, &ID);
}

void EBO::Bind(GLuint* indicies, GLsizeiptr size)
{
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ID);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, size, indicies, GL_STATIC_DRAW);
}

void EBO::UnBind()
{
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
}

void EBO::Delete()
{
	glDeleteBuffers(GL_ELEMENT_ARRAY_BUFFER, &ID);
}

