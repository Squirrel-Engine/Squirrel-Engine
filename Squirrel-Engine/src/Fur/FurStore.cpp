#include "FurStore.h"

GLFWwindow* furWindow;
std::queue<DrawCall*>* firstCommandBuffer = new std::queue<DrawCall*>;
Squirrel::UNIFORM_DESC* uniformDesc = new Squirrel::UNIFORM_DESC;