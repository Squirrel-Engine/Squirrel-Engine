#pragma once
#include "DrawCall.h"
#include "EditorCamera.h"
#include <GLFW/glfw3.h>

extern GLFWwindow* furWindow;
extern std::vector<DrawCall*>* firstCommandBuffer;
extern EditorCamera* camera;
