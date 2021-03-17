#include "FurStore.h"

GLFWwindow* furWindow;
std::vector<DrawCall*>* firstCommandBuffer = new std::vector<DrawCall*>;
EditorCamera* camera = new EditorCamera();