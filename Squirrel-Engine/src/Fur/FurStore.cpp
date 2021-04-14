#include "FurStore.h"

GLFWwindow* furWindow;
std::queue<DrawCall*>* tempDrawCallBuffer = new std::queue<DrawCall*>;
std::queue<DrawCall*>* firstCommandBuffer = new std::queue<DrawCall*>;
Squirrel::CAMERA_DESC* cameraDesc = new Squirrel::CAMERA_DESC;
Squirrel::LIGHT_DESC* lightDesc = new Squirrel::LIGHT_DESC;