#include "FurStore.h"

GLFWwindow* furWindow;
std::queue<DrawCall*>* firstCommandBuffer = new std::queue<DrawCall*>;
Squirrel::CAMERA_DESC* cameraDesc = new Squirrel::CAMERA_DESC;