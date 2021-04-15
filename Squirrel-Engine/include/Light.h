#pragma once
#include "Shader.h"
#include "UniformDesc.h"

namespace Squirrel {
	class Light {
	private:
		unsigned int VBO;
	public:
		Light();
		~Light();

		void Draw(Shader& shader, Squirrel::TRANSFORM_DESC& transformUniform, Squirrel::LIGHT_DESC& lightUniform);
	public:
		unsigned int lightCubeVAO;
	};
}