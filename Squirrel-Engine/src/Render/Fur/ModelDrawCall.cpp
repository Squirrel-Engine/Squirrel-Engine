#include "ModelDrawCall.h"

ModelDrawCall::ModelDrawCall(Model* model, Shader* shader, TRANSFORM_DESC* uniformDesc)
	:m_Model(model), m_Shader(shader), m_UniformDesc(uniformDesc)
{

}

void ModelDrawCall::draw()
{
	m_Model->Draw(*this->m_Shader, *this->m_UniformDesc);
}
