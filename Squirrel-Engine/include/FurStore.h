#pragma once
#include <queue>
#include "DrawCall.h"
#include "UniformDesc.h"
#include "GLFW/glfw3.h"


extern GLFWwindow* furWindow;
extern queue<DrawCall*>* firstCommandBuffer;
extern CAMERA_DESC* cameraDesc;
