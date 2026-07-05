# include <glad/glad.h>
# include <glfw/glfw3.h>
# include <iostream>
# include "stb_image.h"
#include <cmath>
#include "shader.h"
using namespace std;


// 视口大小回调函数，声明
void adjustViewSize_callback(GLFWwindow*, int, int);

// 用户按下esc键，就退出窗口
void processInput(GLFWwindow*);

int main() {
    // 实例化窗口
    // 初始化窗口
    glfwInit();
    // 配置窗口参数
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);  // 使用核心模式

    // 创建窗口对象
    GLFWwindow* window = glfwCreateWindow(2000, 1500, "My OpenGL Window", nullptr, nullptr);
    if (!window)
    {   
        const char* desc;
        int err = glfwGetError(&desc);
        cout << "创建窗口失败！错误码: " << err << "，描述: " << desc << endl;
        cout << "Fail to Create Window !" << endl;
        return -1;
    }
    glfwMakeContextCurrent(window);       // 绑定窗口上下文
    // 注册视口大小回调函数
    glfwSetFramebufferSizeCallback(window, adjustViewSize_callback);

    // 初始化glad
    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
    {
        cout << "Fail to init GLAD !" << endl;
        return -1;
    }


    // // 创建顶点着色器
    // GLuint vertexShader = glCreateShader(GL_VERTEX_SHADER);
    // glShaderSource(vertexShader, 1,  &vertexShaderSource, nullptr);
    // glCompileShader(vertexShader);

    // // 创建片段着色器
    // GLuint fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
    // glShaderSource(fragmentShader, 1, &fragmentShaderSource, nullptr);
    // glCompileShader(fragmentShader);

    // // 链接着色器到着色器程序
    // // 创建程序
    // GLuint shaderProgram = glCreateProgram();
    // // 挂载
    // glAttachShader(shaderProgram, vertexShader);
    // glAttachShader(shaderProgram, fragmentShader);
    // // 链接
    // glLinkProgram(shaderProgram);
    // // 激活着色器
    // glUseProgram(shaderProgram);
    

    // // 删除着色器
    // glDeleteShader(vertexShader);
    // glDeleteShader(fragmentShader);

    myShader myShader_0("C:/Users/27410/Desktop/LearnOpenGL/shaders/0_v.vs", "C:/Users/27410/Desktop/LearnOpenGL/shaders/0_f.fs");


    // 设置顶点数据
    GLfloat vertexs[] = {
        0.5, 0.5, 0,       1, 0, 0,       1, 1,
        0.5, -0.5, 0,       0, 1, 0,        1, 0,
        -0.5, -0.5, 0,        0, 0, 1,      0, 0,
        -0.5, 0.5, 0,       1, 1, 0,        0, 1
    };


    // 索引数组
    GLuint indicates[] = {
        0, 1, 2,
        0, 2, 3
    };

    // 创建VAO，存属性配置
    GLuint vao;
    glGenVertexArrays(1, &vao);
    glBindVertexArray(vao);

    // 创建VBO，存这些数据
    GLuint vbo;
    glGenBuffers(1, &vbo);
    glBindBuffer(GL_ARRAY_BUFFER, vbo);
    // 复制数据到GPU
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertexs), vertexs, GL_STATIC_DRAW );


    // 创建EBO
    GLuint ebo;
    glGenBuffers(1, &ebo);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ebo);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indicates), indicates, GL_STATIC_DRAW);

    // 配置GPU如何解释这些顶点，配置顶点属性
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 8*sizeof(GLfloat), (void*)0);
    glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 8*sizeof(GLfloat), (void*)(3*sizeof(float)));
    glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, 8*sizeof(float), (void*)(6 * sizeof(float)));
    

    // 启用配置
    glEnableVertexAttribArray(0);
    glEnableVertexAttribArray(1);
    glEnableVertexAttribArray(2);
    

    // 配置纹理
    GLuint texture;
    glGenTextures(1, &texture);
    glBindTexture(GL_TEXTURE_2D, texture);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

    // 加载创建纹理
    int width, height, nrChannels;
    unsigned char* data = stbi_load("C:/Users/27410/Desktop/LearnOpenGL/textures/container.jpg", &width, &height, &nrChannels, 0);
     if (data)
    {
        glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, data);
        glGenerateMipmap(GL_TEXTURE_2D);
    }
    else
    {
        std::cout << "Failed to load texture" << std::endl;
    }

    stbi_image_free(data);


    // 循环渲染
    while (!glfwWindowShouldClose(window))
    {   
        // 输入
        processInput(window);

        // 设置清屏颜色
        glClearColor(0, 0, 0, 0.5);
        glClear(GL_COLOR_BUFFER_BIT);
        

        glBindTexture(GL_TEXTURE_2D, texture);

        // 激活着色器
        // glUseProgram(shaderProgram);
        myShader_0.use();


        // 更新uniform颜色
        // float timeVal = glfwGetTime();
        // float colorVal = (sin(timeVal)/2) +0.5;
        // int uniformLocation = glGetUniformLocation(shaderProgram, "myColor");
        // glUniform4f(uniformLocation, 0, 0, colorVal, 1);


        // 绑定vao
        glBindVertexArray(vao);
        // glDrawArrays(GL_TRIANGLES, 0, 6);
        glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);

        // 交换缓冲，检查事件
        glfwSwapBuffers(window);
        glfwPollEvents();
    }
    
    // 释放资源
    glfwTerminate();

    return 0;
}

void adjustViewSize_callback(GLFWwindow* window, int width, int height) {
    glViewport(0, 0, width, height);
}

void processInput(GLFWwindow* window) {
    if (glfwGetKey(window, GLFW_KEY_ESCAPE))
    {
        glfwSetWindowShouldClose(window, true);
    } 
}