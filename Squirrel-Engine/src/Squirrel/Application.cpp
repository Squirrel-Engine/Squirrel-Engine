#include "../../include/Application.h"
#include <iostream>
#include <GLFW/glfw3.h>
namespace Squirrel {

	Application::Application()
	{
	}


	Application::~Application()
	{
	}

    void Application::Run()
    {
        glfwInit();
        GLFWwindow* window = glfwCreateWindow(800, 600, "llk Programým", NULL, NULL);


        if (window == NULL)
        {
            std::cout << "Pencere Olusturulamadi" << std::endl;

            glfwTerminate();
        }

        glfwMakeContextCurrent(window);


        while (!glfwWindowShouldClose(window))
        {
            glfwSwapBuffers(window);

            glfwPollEvents();
        }
    }
}
