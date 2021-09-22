#include <VAO.h>

void glClearError()
{
	while (glGetError() != GL_NO_ERROR);
}

int glLogError(const char* function, const char* file, int line)
{
	while (GLenum error = glGetError())
	{
		std::cout << "[OpenGL:ERROR] (code " << error << ") at " << function << " in " << file << ":" << line << std::endl;
		return 0;
	}

	return 1;
}
#define ASSERT(x) if (!(x)) __debugbreak();
#define GLCALL(x) glClearError();\
    x;\
    ASSERT(glLogError(#x, __FILE__, __LINE__))

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
	GLCALL(glBufferData(GL_ARRAY_BUFFER, size, vertex.data(), GL_STATIC_DRAW));
}

void VBO::UnBind()
{
	glBindBuffer(GL_ARRAY_BUFFER, 0);
}

void VBO::Delete()
{
	glDeleteBuffers(1, &ID);
}
