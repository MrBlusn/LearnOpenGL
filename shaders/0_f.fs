#version 330 core
    // "uniform vec4 myColor;\n"
in vec4 vertexColor;
in vec2 texCoor;
out vec4 FragColor;

uniform sampler2D myTexture;

void main() {
    FragColor = texture(myTexture, texCoor);
}
