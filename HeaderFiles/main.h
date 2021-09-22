#pragma once
#define _USE_MATH_DEFINES

#include <iostream>
#include <vector>
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <stdlib.h>  
#include <time.h> 
#include <cmath>

#include <Shader.h>
#include <VAO.H>
#include <VBO.H>
#include <EBO.h>
#include <imgui/imgui_impl_opengl3.h>
#include <imgui/imgui_impl_glfw.h>
#include <imgui/imgui.h>

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <glm/gtx/range.hpp>
#include <glm/gtc/random.inl>

void RegenerateTriangle();
std::vector<glm::vec3> trinagleVertices(float radius);
void processInput(GLFWwindow* window);
void framebuffer_size_callback(GLFWwindow* window, int width, int height);
const int windowWidth = 800;
const int windowHeight = 600;
float aspectRatio = (float)windowWidth / (float)windowHeight;

int success;
char infoLog[512];

float color[4] = { 0.2f, 0.6f, 0.5f, 1.0f };
float sizeMultipe[3] = { 1.0f, 1.0f, 1.0f };
bool bDrawTriangle = true;

long long int seed = time(NULL);


