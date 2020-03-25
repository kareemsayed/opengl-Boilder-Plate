#include "pch.h"




void processInput(GLFWwindow* window)
{
	if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
		glfwSetWindowShouldClose(window, true);
}

int main()
{
	if (!glfwInit())
		return -1;


	GLFWwindow* window = glfwCreateWindow(960, 540, "WINDOW!", nullptr, nullptr);
	if (window == nullptr)
	{
		std::cout << "Failed to create GLFW window" << std::endl;
		glfwTerminate();
		return -1;
	}
	glfwMakeContextCurrent(window);
	glfwSwapInterval(0);
	if (!gladLoadGLLoader(GLADloadproc(glfwGetProcAddress)))
	{
		std::cout << "Failed to initialize GLAD" << std::endl;
		return -1;
	}

	std::cout << glGetString(GL_VERSION) << std::endl;


	while (!glfwWindowShouldClose(window))
	{
		processInput(window);

		glfwSwapBuffers(window);
		glfwPollEvents();
	}


	glfwTerminate();
	std::cout << "okay" << std::endl;
	return 0;
}
