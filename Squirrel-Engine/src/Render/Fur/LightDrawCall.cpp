#include "LightDrawCall.h"

LightDrawCall::LightDrawCall(LightObject* light, Shader* shader, TRANSFORM_DESC* transformUniform, LIGHT_DESC* lightUniform)
	:light(light), shader(shader), transformUniform(transformUniform), lightUniform(lightUniform)
{

}

void LightDrawCall::draw()
{
	light->Draw(*this->shader, *this->transformUniform, *this->lightUniform);
}
