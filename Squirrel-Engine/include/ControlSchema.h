#pragma once
namespace Squirrel
{
	class ControlSchematic
	{
	public:
		ControlSchematic() {}
		virtual void Key_SPACE_PRESS() {};
		virtual void Key_SPACE_RELEASE() {};
		virtual void Key_Space_HOLD() {};

		virtual void Mouse_Movement() {};

		virtual void ScrollMovement() {};

		virtual void Mouse_Left_PRESS() {};
		virtual void Mouse_Left_RELEASE() {};
		virtual void Mouse_Left_HOLD() {};

		virtual void Mouse_Right_PRESS() {};
		virtual void Mouse_Right_RELEASE() {};
		virtual void Mouse_Right_HOLD() {};

	};
}
