#pragma once
#include "ControlSchema.h"
#include "InterfaceFactory.h"

class TestControlSchema : public ControlSchematic
{
public:
	TestControlSchema()
	{
	};


	const float cameraSpeed = 0.6f; // adjust accordingly


	bool firstMouse = true;

	float lastX;
	float lastY;

	void Key_SPACE_RELEASE() override;
	void Key_Space_HOLD() override;
	void Mouse_Movement() override;
	void ScrollMovement() override;

	void Mouse_Left_PRESS() override;
	void Mouse_Left_HOLD() override;

	void W_HOLD() override;
	void S_HOLD() override;
	void A_HOLD() override;
	void D_HOLD() override;

	void E_HOLD() override;
	void Q_HOLD() override;
};