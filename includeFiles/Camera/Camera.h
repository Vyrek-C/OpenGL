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
protected:
    glm::vec3 cameraDir;
    glm::vec3 cameraUp;
    glm::vec3 cameraPos;
private:
    float desiredSpeed;
    float cameraSpeed;
    float deltaTime, currentFrame, lastFrame;
};

#endif