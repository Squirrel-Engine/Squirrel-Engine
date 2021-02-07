#pragma once
#include "DrawCall.h"
#include <GLFW/glfw3.h>
#include <queue>

extern GLFWwindow* furWindow;
extern std::queue<DrawCall*>* firstCommandBuffer;
