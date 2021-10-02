#ifndef CAMERA_HEADER
#define CAMERA_HEADER
#include <includeHeader.h>


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
    float lastX, lastY;
    float pitch, yaw;
    float sensitivity = 0.1f;
};

#endif