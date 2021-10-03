#pragma once

#include <iostream>

#include <HeaderFiles/Shader.h>

#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <glm/gtx/range.hpp>
#include <glm/gtc/random.inl>


class Camera
{
public:
    Camera(glm::vec3 position, float camSpeed);
    void processInput(GLFWwindow* window);
    void SetCameraSpeed(float camSpeed);
    void CalculateView(Shader &ourShader);
    void SetSensitivity(float sens);
    void MouseMovement(double xpos, double ypos);
protected:
    glm::vec3 cameraDir;
    glm::vec3 cameraUp;
    glm::vec3 WorldUp;
    glm::vec3 cameraPos;
    glm::vec3 cameraRight;
private:
    void RecalculateVectors();
    float desiredSpeed, cameraSpeed, deltaTime, currentFrame, lastFrame;
    float pitch, yaw;
};
