#pragma once
#include <glm/glm.hpp>
using namespace glm;
class Uniforms
{
public:
	Uniforms()
	{
	};
	virtual void setup() = 0;
};

class TRANSFORM_DESC : public Uniforms
{
public:
	TRANSFORM_DESC()
	{
	};

	void setup() override
	{
	};
	mat4 model;
};

class CAMERA_DESC : public Uniforms
{
public:
	CAMERA_DESC()
	{
	};

	void setup() override
	{
	};
	vec3 viewPos;
	mat4 viewProjection;
};

class LIGHT_DESC : public Uniforms
{
public:
	LIGHT_DESC()
	{
	};

	void setup() override
	{
	};

	vec3 position;

	float intensity;
	vec3 lightColour;
	float attenuationRadius;
};
