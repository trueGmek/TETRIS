#version  330 core

uniform vec4 Color;
uniform sampler2D _texture;

in vec2 TexCoord;

out vec4 FragColor;

void main() {
    FragColor = Color * texture(_texture, TexCoord);
}
