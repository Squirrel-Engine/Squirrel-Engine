#pragma once
#include <queue>
#include "DrawCall.h"
#include "UniformDesc.h"
#include <GLFW/glfw3.h>


extern GLFWwindow* furWindow;
extern queue<DrawCall*>* firstCommandBuffer;
extern Squirrel::CAMERA_DESC* cameraDesc;
extern Squirrel::LIGHT_DESC* lightDesc;
extern std::queue<DrawCall*>* tempDrawCallBuffer;

