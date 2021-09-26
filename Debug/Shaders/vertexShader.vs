#version 330 core
layout (location = 0) in vec3 aPos;

out vec4 ourColor;

uniform mat4 translateMove;
uniform mat4 proj;
uniform vec4 color;
uniform vec3 size;

void main()
{
    gl_Position = proj * translateMove * vec4(size * aPos, 1.0f);
    ourColor = color;
}