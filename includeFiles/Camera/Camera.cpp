#include <includeHeader.h>

Camera::Camera(glm::vec3 position, float camSpeed)
{
    cameraPos = position;
    WorldUp = glm::vec3(0.0f, 1.0f, 0.0f);
    cameraDir = glm::vec3(0.0f, 0.0f, -1.0f);
    lastX = 400;
    lastY = 300;
    yaw = -90.f;
    pitch = 0.f;
    desiredSpeed = camSpeed;
    RecalculateVectors();
}

void Camera::processInput(GLFWwindow* window)
{
    currentFrame = (float)glfwGetTime();
    deltaTime = currentFrame - lastFrame;
    lastFrame = currentFrame;
    cameraSpeed = desiredSpeed * deltaTime;
    if(glfwGetKey(window, GLFW_KEY_W))
        cameraPos += cameraSpeed * cameraDir;
    if(glfwGetKey(window, GLFW_KEY_S))
        cameraPos -= cameraSpeed * cameraDir;
    if(glfwGetKey(window, GLFW_KEY_A))
        cameraPos -= cameraSpeed * cameraRight;
    if(glfwGetKey(window, GLFW_KEY_D))
        cameraPos += cameraSpeed * cameraRight;
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

void Camera::MouseMovement(double xpos, double ypos)
{
	double sensitivity = 0.1f;
    xpos *= sensitivity;
    ypos *= sensitivity;

    yaw += xpos;
    pitch += ypos;

    if(pitch > 89.f)
        pitch = 89.f;
    if (pitch < -89.f)
        pitch = -89.f;

    RecalculateVectors();
}

void Camera::RecalculateVectors()
{
    glm::vec3 dir;
    dir.x = cos(glm::radians(yaw)) * cos(glm::radians(pitch));
    dir.y = sin(glm::radians(pitch));
    dir.z = sin(glm::radians(yaw)) * cos(glm::radians(pitch));
    cameraDir = glm::normalize(dir);

    cameraRight = glm::normalize(glm::cross(cameraDir, WorldUp));
    cameraUp = glm::normalize(glm::cross(cameraRight, cameraDir));
}