#pragma once
#include "DrawCall.h"
#include "EditorCamera.h"
#include <GLFW/glfw3.h>
#include <queue>

extern GLFWwindow* furWindow;
extern std::queue<DrawCall*>* firstCommandBuffer;
extern EditorCamera* camera;
