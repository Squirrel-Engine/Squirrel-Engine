#include "Light.h"

Light::Light()
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
