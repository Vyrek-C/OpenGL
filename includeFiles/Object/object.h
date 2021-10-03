#pragma once

#include <iostream>

#include <HeaderFiles/EBO.h>
#include <HeaderFiles/VAO.H>
#include <HeaderFiles/VBO.H>

#include <vector>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <glm/gtx/range.hpp>
#include <glm/gtc/random.inl>

class Object
{
public:
    inline glm::vec3 ObjectPos()
    {
        return objectPos;
    }
    
    glm::mat4 RotateObject(float angle, glm::vec3 rotateAxis);
    glm::mat4 MoveObject(glm::vec3 position);

    std::vector<glm::vec3> GenerateVerticies(float radius);

    std::vector<unsigned int> GenerateIndicies(std::vector<glm::vec3> verticies);

    void RandomGenerateTrinagle(VAO &newVAO, VBO &newVBO, EBO &newEBO, std::vector<unsigned int> &indicies, int &seed);

    void LinkBuffers(VAO &newVAO, VBO &newVBO, EBO &newEBO, std::vector<glm::vec3> verticies, 
	std::vector<unsigned int> &indicies);

    void LinkBuffers(VAO &newVAO, VBO &newVBO, std::vector<glm::vec3> verticies);

protected:
    glm::vec3 objectPos;
};