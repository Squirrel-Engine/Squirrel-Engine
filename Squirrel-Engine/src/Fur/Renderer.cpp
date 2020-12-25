#include "include/Renderer.h"

void furRender()
{
    float firstTriangle[] = {
        //positions          //colors          //coordinates                             
        -0.9f, -0.5f, 0.0f,  1.0f, 0.0f, 0.0f,  0.0f, 0.0f,   // left 
        -0.0f, -0.5f, 0.0f,  0.0f, 1.0f, 0.0f,  1.0f, 0.0f,   // right
        -0.45f, 0.5f, 0.0f,  0.0f, 0.0f, 1.0f,  0.5f, 1.0f   // top 
    };
    RenderObject obj(firstTriangle, sizeof(firstTriangle), "../../Squirrel-Engine/res/shaders/Basic.shader", "../../Squirrel-Engine/res/textures/wall.jpg");

    glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);

	obj.texture->bind(0);
    obj.shader->use();
    obj.shader->setInt("u_Texture", 0);
    obj.vertexArray->bind();
    glDrawArrays(GL_TRIANGLES, 0, 3);
	
    glfwSwapBuffers(furWindow);
    glfwPollEvents();
}

