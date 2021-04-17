#pragma once
#include "ControlSchema.h"
#include <GLFW/glfw3.h>
#include "FurStore.h"
#include "InputStore.h"

class IP_Interface
{
public:
	IP_Interface();
	ControlSchematic* controlSchematic;
	void execInput();
	void setControlSchema(ControlSchematic* _controlSchema);
	float mouseX;
	float mouseY;

	float scrollX;
	float scrollY;
};
