// 着色器类
#pragma once

#include <glad/glad.h> // 包含glad来获取所有的必须OpenGL头文件

#include <string>
#include <fstream>
#include <sstream>
#include <iostream>

class myShader {
    public:
    // 程序ID
    unsigned int ID;

    myShader(const char* vertexPath, const char* fragmentPath);

    // 使用激活函数
    void use();

};
