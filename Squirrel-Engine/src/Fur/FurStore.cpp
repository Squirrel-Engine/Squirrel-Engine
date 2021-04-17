#include "FurStore.h"

GLFWwindow* furWindow;
std::queue<DrawCall*>* firstCommandBuffer = new std::queue<DrawCall*>;
CAMERA_DESC* cameraDesc = new CAMERA_DESC;