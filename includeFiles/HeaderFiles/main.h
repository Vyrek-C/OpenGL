#include <includeHeader.h>


void RegenerateTriangle();
std::vector<unsigned int> GenerateIndicies(std::vector<glm::vec3> verticies);
void InitImGui(GLFWwindow* window);
std::vector<glm::vec3> GenerateVerticies(float radius);
void processInput(GLFWwindow* window);
void framebuffer_size_callback(GLFWwindow* window, int width, int height);

void RandomGenerateTrinagle(VAO &newVAO, VBO &newVBO, EBO &newEBO, std::vector<unsigned int> &indicies);

void LinkBuffers(VAO &newVAO, VBO &newVBO, EBO &newEBO, std::vector<glm::vec3> verticies, 
	std::vector<unsigned int> &indicies);

void LinkBuffers(VAO &newVAO, VBO &newVBO, std::vector<glm::vec3> verticies);

const int windowWidth = 800;
const int windowHeight = 600;
float aspectRatio = (float)windowWidth / (float)windowHeight;

int success;
char infoLog[512];

float angle = 0;
float color[4] = { 0.2f, 0.6f, 0.5f, 1.0f };
float sizeMultipe[3] = { 1.0f, 1.0f, 1.0f };
bool bDrawTriangle = true;
int seed = time(NULL);