#include <Object/object.h>

glm::mat4 Object::RotateObject(float angle, glm::vec3 rotateAxis)
{
    glm::mat4 result = glm::mat4(1.0f);
    return glm::rotate(result, angle, rotateAxis);
}

glm::mat4 Object::MoveObject(glm::vec3 position)
{
    glm::mat4 result = glm::mat4(1.0f);
    return glm::translate(result, position);
}

std::vector<glm::vec3> Object::GenerateVerticies(float radius)
{
    glm::vec3 test = glm::vec3(1.0f);
	std::vector<glm::vec3> vectorArray;
	glm::vec3 centerCircle = glm::vec3(0.0f, 0.0f ,0.0f);
	float angle = 0.0f;
	for (int i = 0; i < 3; i++)
	{
		angle += rand() % 20 + 20;
		glm::vec3 circleVector = glm::vec3(glm::cos(angle) * radius, glm::sin(angle), 0.0f);
		glm::vec3 finalVector = centerCircle + circleVector;
		vectorArray.push_back(finalVector);
	}
	return vectorArray;
}

std::vector<unsigned int> Object::GenerateIndicies(std::vector<glm::vec3> verticies)
{
    std::vector<unsigned int> arr;
	for(int i = 0; i < verticies.size(); i++)
	{
		arr.push_back(i);
	}
	return arr;
}

void Object::RandomGenerateTrinagle(VAO &newVAO, VBO &newVBO, EBO &newEBO, std::vector<unsigned int> &indicies, int &seed)
{
    srand(seed);
	std::vector<glm::vec3> verticies = GenerateVerticies(rand() % 5 + 1);
	indicies = GenerateIndicies(verticies);
	LinkBuffers(newVAO, newVBO, newEBO, verticies, indicies);
}

void Object::LinkBuffers(VAO &newVAO, VBO &newVBO, EBO &newEBO, std::vector<glm::vec3> verticies, 
	std::vector<unsigned int> &indicies)
{
    newVAO.Bind();

	newVBO.Bind();	
	newVBO.BindBufferData(verticies.size() * sizeof(glm::vec3), verticies);

	newEBO.Bind();
	newEBO.BindBufferData(indicies);

	newVAO.LinkVBO(0, 0, (void*)0);
	newEBO.UnBind();
	newVBO.UnBind();
	newVAO.UnBind();
}

void Object::LinkBuffers(VAO &newVAO, VBO &newVBO, std::vector<glm::vec3> verticies)
{
    newVAO.Bind();

	newVBO.Bind();	
	newVBO.BindBufferData(verticies.size() * sizeof(glm::vec3), verticies);

	newVAO.LinkVBO(0, 0, (void*)0);
	newVBO.UnBind();
	newVAO.UnBind();
}