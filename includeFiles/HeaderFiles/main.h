#define _USE_MATH_DEFINES

#include <iostream>
#include <vector>
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <stdlib.h>  
#include <time.h> 
#include <cmath>

#include <HeaderFiles/Shader.h>
#include <HeaderFiles/VAO.H>
#include <HeaderFiles/VBO.H>
#include <HeaderFiles/EBO.h>
#include <imgui/imgui.h>
#include <imgui/imgui_impl_glfw.h>
#include <imgui/imgui_impl_opengl3.h>

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <glm/gtx/range.hpp>
#include <glm/gtc/random.inl>

void RegenerateTriangle();
std::vector<unsigned int> GenerateIndicies(std::vector<glm::vec3> vertices);
void InitImGui(GLFWwindow* window);
std::vector<glm::vec3> trinagleVertices(float radius);
void processInput(GLFWwindow* window);
void framebuffer_size_callback(GLFWwindow* window, int width, int height);
void GenerateTriangle(VAO newVAO, VBO newVBO, EBO newEBO,std::vector<glm::vec3> &vertices, std::vector<unsigned int> indicies);
const int windowWidth = 800;
const int windowHeight = 600;
float aspectRatio = (float)windowWidth / (float)windowHeight;

int success;
char infoLog[512];

float color[4] = { 0.2f, 0.6f, 0.5f, 1.0f };
float sizeMultipe[3] = { 1.0f, 1.0f, 1.0f };
bool bDrawTriangle = true;
long long int seed = time(NULL);