#include <VAO.h>

VAO::VAO()
{
	glGenVertexArrays(1, &ID);
}

void VAO::LinkVBO(GLuint index, GLsizei stride, const void* pointer)
{
	Bind();
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, stride, pointer);
	glEnableVertexAttribArray(0);
}

void VAO::Bind()
{
	glBindVertexArray(ID);
}

void VAO::UnBind()
{
	glBindVertexArray(0);
}

void VAO::Delete()
{
	glDeleteVertexArrays(1, &ID);
}
