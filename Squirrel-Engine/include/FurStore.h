#pragma once
#include "DrawCall.h"
#include "Window.h"
#include <queue>

extern GLFWwindow* furWindow;
extern std::queue<DrawCall*>* firstCommandBuffer;
