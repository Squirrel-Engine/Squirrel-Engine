#pragma once
#include <glm/glm.hpp>

namespace Squirrel
{
	typedef struct UNIFORM_DESC
	{
		glm::mat4 model;
	}UNIFORM_DESC;

	typedef struct CAMERA_DESC
	{
		glm::vec3 viewPos;
		glm::mat4 viewProjection;
	}CAMERA_DESC;

	typedef struct LIGHT_DESC
	{
		glm::vec3 lightPos;
		glm::vec3 viewPos;
		glm::mat4 viewProjection;
	}LIGHT_DESC;
}
