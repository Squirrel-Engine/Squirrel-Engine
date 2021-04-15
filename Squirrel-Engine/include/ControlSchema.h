#pragma once
namespace Squirrel
{
	class ControlSchematic
	{
	public:
		ControlSchematic() {}
		virtual void Key_SPACE() = 0;
		virtual void Mouse_Movement() = 0;
	};
}
