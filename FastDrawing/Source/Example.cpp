#include "Mesh.h"
#include "Window.h"




int main(int argc, char* args[])
{
	Window window = Window("test", 400, 400);


	std::vector<Vertex> vertices;
	Vertex v1 = { -0.5f, -0.5f, 0.0f, };
	Vertex v2 = { 0.5f, -0.5f, 0.0f, };
	Vertex v3 = { 0.5f, 0.5f, 0.0f };

	Vertex v4 = { -0.5f, -0.5f, 0.0f, };
	Vertex v5 = { 0.5f, 0.5f, 0.0f, };
	Vertex v6 = { -0.5f, 0.5f, 0.0f };

	vertices.push_back(v1);
	vertices.push_back(v2);
	vertices.push_back(v3);

	vertices.push_back(v4);
	vertices.push_back(v5);
	vertices.push_back(v6);

	std::string vertex ="#version 330 core\n"
		"layout(location = 0) in vec3 aPos;\n"
		"void main()\n"
		"{\n"
		"gl_Position = vec4(aPos.x, aPos.y, aPos.z, 1.0);\n"
		"}\n";

	std::string fragment ="#version 330 core\n"
		"out vec4 FragColor;\n"
		"uniform vec4 ourColor;\n"
		"void main()\n"
		"{\n"
		"FragColor = ourColor;\n"
		"}\n";

	Mesh mesh = Mesh(vertex, fragment);
	mesh.SetVertices(vertices);
	mesh.Bind();

	/*Mesh mesh2 = Mesh(vertex, fragment);
	mesh2.SetVertices(vertices);
	mesh2.Bind();*/

	while (window.IsOpened()) {

		window.Clear();

		mesh.Draw();

		glfwPollEvents();
		window.Blit();
	}
}