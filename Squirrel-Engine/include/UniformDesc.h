#pragma once
#include <glm/glm.hpp>

namespace Squirrel
{
	typedef struct UNIFORM_DESC
	{
		glm::vec3 lightPos;
		glm::vec3 viewPos;
		glm::mat4 viewProjection;
		glm::vec3 model;
		glm::vec3 rotation;
	}UNIFORM_DESC;

}
