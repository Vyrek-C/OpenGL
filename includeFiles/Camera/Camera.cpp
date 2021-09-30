#include <includeHeader.h>

Camera::Camera(glm::vec3 position, float camSpeed)
{
    cameraPos = position;
    cameraUp = glm::vec3(0.0f, 1.0f, 0.0f);
    cameraDir = glm::vec3(0.0f, 0.0f, -1.0f);
    desiredSpeed = camSpeed;
}

void Camera::processInput(GLFWwindow* window)
{
    currentFrame = glfwGetTime();
    deltaTime = currentFrame - lastFrame;
    lastFrame = currentFrame;
    cameraSpeed = desiredSpeed * deltaTime;
    std::cout << cameraSpeed << std::endl;
    if(glfwGetKey(window, GLFW_KEY_W))
        cameraPos += cameraSpeed * cameraDir;
    if(glfwGetKey(window, GLFW_KEY_S))
        cameraPos -= cameraSpeed * cameraDir;
    if(glfwGetKey(window, GLFW_KEY_A))
        cameraPos += cameraSpeed * glm::cross(cameraUp, cameraDir);
    if(glfwGetKey(window, GLFW_KEY_D))
        cameraPos -= cameraSpeed * glm::cross(cameraUp, cameraDir);
}

void Camera::SetCameraSpeed(float camSpeed)
{
    desiredSpeed = camSpeed;
}

void Camera::CalculateView(Shader &ourShader)
{
    glm::mat4 view = glm::mat4(1.0f);
    view = glm::lookAt(cameraPos, cameraPos + cameraDir, cameraUp);
    ourShader.setMat4("view", view);
}