#pragma once
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

constexpr int numVAOs = 1;

// 生成着色项目
GLuint createShaderProgram();

// 读取着色文件
string readShaderSource(const char* filePath);

// 检错
void printShaderLog(GLuint shader);
void printProgramLog(int prog);
bool checkOpenGLError();


