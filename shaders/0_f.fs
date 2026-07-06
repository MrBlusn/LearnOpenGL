#version 330 core
// "uniform vec4 myColor;\n"
in vec4 vertexColor;
in vec2 texCoor;
out vec4 FragColor;

uniform sampler2D myTexture1;
uniform sampler2D myTexture2;

void main() {
    FragColor = mix(texture(myTexture1, texCoor), texture(myTexture2, texCoor), 0.2);
}
