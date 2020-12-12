#include "iostream"
#include <string.h>
namespace Fur
{
	 struct RenderOptions
	{
		int screenWidth;
		int screenHeight;
		std::string windowName;
	};
		
	//RenderOptions_t renderOptions;
	//struct RenderOptions *renderOptions = (struct RenderOptions*)malloc(sizeof(RenderOptions));
	//RenderOptions* renderOptions = new RenderOptions();
	 extern RenderOptions* renderOptions;
}
