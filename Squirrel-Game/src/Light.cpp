#include "Light.h"

Light::Light(ELightType type)
{
	bindComponent(&transformComponent);
	bindComponent(&lightComponent);
}

void Light::BeginPlay()
{

}

void Light::Update()
{

}
