#include "ModelDrawCall.h"

ModelDrawCall::ModelDrawCall(Model* model, Shader* shader, TRANSFORM_DESC* uniformDesc)
	:model(model), shader(shader), uniformDesc(uniformDesc)
{

}

void ModelDrawCall::draw()
{
	model->Draw(*this->shader, *this->uniformDesc);
}
