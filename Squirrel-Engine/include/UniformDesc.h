#pragma once
#include <glm/glm.hpp>

namespace Squirrel
{
	class Uniforms {
	public:
		Uniforms() {};
		virtual void setup() = 0;
	};

	class TRANSFORM_DESC : public Uniforms {
	public:
		TRANSFORM_DESC() {};
		inline void setup() override {};
		glm::mat4 model;
	};

	class CAMERA_DESC : public Uniforms {
	public:
		CAMERA_DESC() {};
		inline void setup() override {};
		glm::vec3 viewPos;
		glm::mat4 viewProjection;
	};

	class LIGHT_DESC : public Uniforms {
	public:
		LIGHT_DESC() {};
		inline void setup() override {};
		
		glm::vec3 lightColor;
		glm::vec3 lightPos;

		float constant;
		float linear;
		float quadratic;
	};
}
