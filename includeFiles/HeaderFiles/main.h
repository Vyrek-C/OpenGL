#pragma once
#ifndef _USE_MATH_DEFINES
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
#include <Object/object.h>
#include <Camera/Camera.h>

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <glm/gtx/range.hpp>
#include <glm/gtc/random.inl>

#include <imgui/imgui.h>
#include <imgui/imgui_impl_glfw.h>
#include <imgui/imgui_impl_opengl3.h>

void framebuffer_size_callback(GLFWwindow* window, int width, int height);

void InitImGui(GLFWwindow* window);

void mouse_callback(GLFWwindow* window, double xpos, double ypos);

void processInput(GLFWwindow* window);

Camera newCamera(glm::vec3(0.0f), 2.f);

Object newObject;

const int windowWidth = 800;
const int windowHeight = 600;
float aspectRatio = (float)windowWidth / (float)windowHeight;

int success;
char infoLog[512];

double lastX = windowWidth/2;
double lastY = windowHeight/2;

double yaw, pitch;

float angle = 0;
float color[4] = { 0.2f, 0.6f, 0.5f, 1.0f };
float sizeMultipe[3] = { 1.0f, 1.0f, 1.0f };
bool bDrawTriangle = true;
int seed = (int)time(NULL);

#endif