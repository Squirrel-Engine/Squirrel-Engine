#include "LightObject.h"
#include "FurStore.h"

LightObject::LightObject(float lightIntensity, glm::vec3& lightColour)
	: m_Intensity(lightIntensity), m_LightColour(lightColour) {}
LightObject::LightObject()
	: m_Intensity(5.0f), m_LightColour(255.0, 255.0, 255.0) {}

LightObject::~LightObject()
{

}