#include "include/FurStore.h"

GLFWwindow* furWindow;
std::queue<DrawCall*>* firstCommandBuffer = new std::queue<DrawCall*>;
