#include "shaderProgram.h"

// 生成着色项目
GLuint createShaderProgram() {
    string vshaderSourceStr = readShaderSource("C:/Users/27410/Desktop/LearnOpenGL/shaders/vertxShader.glsl");
    string fshaderSourceStr = readShaderSource("C:/Users/27410/Desktop/LearnOpenGL/shaders/fragShader.glsl");

    const char *vertxShaderSrc = vshaderSourceStr.c_str();
    const char *fragShaderSrc = fshaderSourceStr.c_str();

    GLuint vShader = glCreateShader(GL_VERTEX_SHADER);
    GLuint fShader = glCreateShader(GL_FRAGMENT_SHADER);

    glShaderSource(vShader, 1, &vertxShaderSrc, nullptr);
    glShaderSource(fShader, 1, &fragShaderSrc, nullptr);
    glCompileShader(vShader);
    glCompileShader(fShader);

    GLuint vfProgram = glCreateProgram();
    glAttachShader(vfProgram, vShader);
    glAttachShader(vfProgram, fShader);
    glLinkProgram(vfProgram);

    return vfProgram;
}

// 读取着色文件
string readShaderSource(const char* filePath) {
    string content;
    ifstream fileStream(filePath);

    if (!fileStream.is_open())
    {
        cerr << "无法打开着色器文件:" << filePath << endl;
        return "";
    }

    string line = "";
    while (!fileStream.eof())
    {
        getline(fileStream, line);
        content.append(line + "\n");
    }

    fileStream.close();
    return content;
}

// 检查模块
void printShaderLog(GLuint shader){
    int len = 0;
    int chWrittn = 0;
    char* log;
    glGetShaderiv(shader, GL_INFO_LOG_LENGTH, &len);
    if (len > 0)
    {
        log = (char*)malloc(len);
        glGetShaderInfoLog(shader, len, &chWrittn, log);
        cout << "Shader Info Log : " << log << endl;
        free(log);
    }
}


void printProgramLog(int prog){
    int len = 0;
    int chWrittn = 0;
    char* log;
    glGetProgramiv(prog, GL_INFO_LOG_LENGTH, &len);
    if (len > 0)
    {
        log = (char*)malloc(len);
        glGetProgramInfoLog(prog, len, &chWrittn, log);
        cout << "Program Info Log : " << log << endl;
        free(log);
    }
}


bool checkOpenGLError(){
    bool foundError = false;
    int glErr = glGetError();
    while (glErr != GL_NO_ERROR)
    {
        cout << "glError : " << glErr << endl;
        foundError = true;
        glErr = glGetError();
    }
    return foundError;
}

