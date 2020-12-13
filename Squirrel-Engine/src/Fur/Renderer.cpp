#include "include/Renderer.h"
#include <iostream>


void furRender()
{
    // render
    // ------
    glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);

    glfwSwapBuffers(furWindow);
    glfwPollEvents();
}
