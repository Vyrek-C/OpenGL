#include <HeaderFiles/VAO.h>


VBO::VBO()
{
	glGenBuffers(1, &ID);
}

void VBO::Bind()
{
	glBindBuffer(GL_ARRAY_BUFFER, ID);
}

void VBO::BindBufferData(float size, std::vector<glm::vec3> &vertex)
{
	glBufferData(GL_ARRAY_BUFFER, size, vertex.data(), GL_STATIC_DRAW);
}

void VBO::UnBind()
{
	glBindBuffer(GL_ARRAY_BUFFER, 0);
}

void VBO::Delete()
{
	glDeleteBuffers(1, &ID);
}
