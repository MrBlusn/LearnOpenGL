// #include <glad/glad.h>
// #include <GLFW/glfw3.h>
// #include <iostream>
// #include "shaderProgram.h"

// // 当用户调整窗口大小时，视口大小也对应调整，回调函数
// void framebuffer_size_callback(GLFWwindow* window, int width, int height);


// int main() {
//     // 初始化GLFW
//     glfwInit();
//     // 配置GLFW，最低GLFW版本3.3
//     glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
//     glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
//     glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);      // 明确告诉glfw，我们使用的是核心模式（core_profile）

//     // 创建窗口对象
//     GLFWwindow* window = glfwCreateWindow(800, 600, "MyOpenGL", nullptr, nullptr);
//     if (!window)
//     {
//         std::cout << "Fail to create GLFW window !" << std::endl;
//         return -1;
//     }
//     glfwMakeContextCurrent(window);


//     // 注册视口回调函数，交给glfw库保管
//     glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);


//     // 初始化GLAD
//     if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
//     {
//         std::cout << "Fail to initialize GLAD !" << std::endl;
//         return -1;
//     }

//     // 渲染对象
//     GLuint renderingProgram;
//     GLuint vao[numVAOs];
//     renderingProgram = createShaderProgram();
//     glGenVertexArrays(numVAOs, vao);
//     glBindVertexArray(vao[0]);

//     // 动画参数
//     float x = 0;
//     float inc = 0.01;

//     GLuint offsetLoc = glGetUniformLocation(renderingProgram, "offset");

//     // 循环渲染
//     while (!glfwWindowShouldClose(window))      //每次循环前，检查一下glfw是否被要求退出
//     {

//         glClearColor(0, 0, 0, 1);
//         glClear(GL_COLOR_BUFFER_BIT);

//         glUseProgram(renderingProgram);

//         x += inc;
//         if (x > 1) inc = -0.01;
//         if (x < -1) inc = 0.01;
        
//         glUniform1f(offsetLoc, x);

        
//         // glPointSize(60);
//         // glDrawArrays(GL_POINTS, 0, 1);
//         glDrawArrays(GL_TRIANGLES, 0, 3);


//         glfwSwapBuffers(window);                // 交换颜色缓冲
//         glfwPollEvents();                       // 检查有没触发什么事件
//     }

//     // 释放资源
//     glfwTerminate();
//     return 0;
    
    

// }


// void framebuffer_size_callback(GLFWwindow* window, int width, int height) {
//     glViewport(0, 0, width, height);
// }




