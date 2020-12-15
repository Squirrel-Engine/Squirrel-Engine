#include "include/Renderer.h"

void furRender()
{
    float firstTriangle[] = {
        //positions          //colors                                       
        -0.9f, -0.5f, 0.0f,  1.0f, 0.0f, 0.0f,  // left 
        -0.0f, -0.5f, 0.0f,  0.0f, 1.0f, 0.0f,  // right
        -0.45f, 0.5f, 0.0f,  0.0f, 0.0f, 1.0f,  // top 
    };
    RenderObject obj(firstTriangle, sizeof(firstTriangle), "C:/Users/16070001006/Projects/Squirrel-Engine/Squirrel-Engine/res/shaders/Basic.shader");

    glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);

    obj.shader->use();
    obj.va->bind();
    glDrawArrays(GL_TRIANGLES, 0, 3);
	
    glfwSwapBuffers(furWindow);
    glfwPollEvents();
}

