#pragma once
#include <vector>
#include <iostream>
#include "../include/Color.h"
#include "../include/Texture.h"
#include "glad/glad.h"
//#include <GLFW/glfw3.h>


#define LAYOUT_POSITION 0
#define LAYOUT_UV 1

typedef struct {
	float x, y, z, u, v;
}Vertex;



class Mesh
{
public:
	Mesh(std::string vertexShaderText, std::string fragmentShaderText);
	//Mesh(std::string filePath);
	~Mesh();

	void SetVertices(std::vector<Vertex> vertices);
	void Bind();

	//various drawing
	void DrawSolidColor(Color color);
	void DrawTexture(Texture* texture);
	void Draw();


private:

	GLuint VBO, VAO, program;
	GLint mvpLocation, vPosLocation, vColLocation;

	std::string vertexShaderText;
	std::string fragmentShaderText;

	size_t textureMode, textureWrapping;

	std::vector<Vertex> vertices;
};

//enum TEXTURE_MODE{TWO_D = GL_TEXTURE_2D};
//enum TEXTURE_WRAPPING{REPEAT = GL_REPEAT, MIRRORED_REPEAT = GL_MIRRORED_REPEAT, CLAMP_EDGE = GL_CLAMP_TO_EDGE, CLAMP_BORDER = GL_CLAMP_TO_BORDER};

