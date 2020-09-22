#pragma once
namespace Squirrel {
	class IWindowRenderer
	{
	public:
		virtual void startUp(int screenWidth, int screenHeight, std::string windowName) = 0;
		virtual void shutDown() = 0;
		virtual Squirrel::Window getWindow() = 0;
		virtual void render() = 0;
	};
}


