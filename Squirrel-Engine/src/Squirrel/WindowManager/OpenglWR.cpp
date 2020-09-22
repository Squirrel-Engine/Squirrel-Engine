#include "../../../include/OpenglWR.h"

namespace Squirrel
{
    void OpenGLWR::startUp(int screenWidth, int screenHeight, std::string windowName) {
        glfwInit();
        window.setGLWindow(glfwCreateWindow(screenWidth, screenHeight, const_cast<char*>(windowName.c_str()), NULL, NULL)); //TODO Implement std::string to char *


        if (window.getGLWindow() == NULL)
        {
            std::cout << "Pencere Olusturulamadi" << std::endl;

            glfwTerminate();
        }

        glfwMakeContextCurrent(window.getGLWindow());
    }

    void OpenGLWR::render() {
        while (!glfwWindowShouldClose(window.getGLWindow()))
        {
            glfwSwapBuffers(window.getGLWindow());

            glfwPollEvents();
        }
    }

    void OpenGLWR::shutDown() {
        glfwTerminate();
    }

    Squirrel::Window OpenGLWR::getWindow() {
        return window;
    }
}
