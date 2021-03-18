#pragma once
#include <queue>
#include "DrawCall.h"
#include "EditorCamera.h"
#include <GLFW/glfw3.h>

extern GLFWwindow* furWindow;
extern queue<DrawCall*>* firstCommandBuffer;
extern EditorCamera* camera;
