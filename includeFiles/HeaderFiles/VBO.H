#ifndef VBO_H
#define VBO_H

#include <includeHeader.h>

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