#include "LightObject.h"
#include "FurStore.h"
#include <glad/glad.h>

LightObject::LightObject(float lightIntensity, glm::vec3& lightColour)
	: m_Intensity(lightIntensity), m_LightColour(lightColour)
{
	
}

LightObject::~LightObject()
{

}