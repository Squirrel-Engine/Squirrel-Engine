#include "../../../include/OpenglWR.h"
#include "../../../src/Utilities/StringUtilities.cpp"
namespace Squirrel
{
    void OpenGLWR::startUp(int screenWidth, int screenHeight, std::string windowName) {
        glfwInit();
        window.setGLWindow(glfwCreateWindow(screenWidth, screenHeight, convertStdStringToConst(windowName), NULL, NULL));


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
