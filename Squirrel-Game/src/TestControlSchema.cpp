#include "ControlSchema/TestControlSchema.h"

#include "Components/CameraComponent.h"

void TestControlSchema::Key_SPACE_RELEASE()
{
	std::cout << "RELEASE" << std::endl;
}

void TestControlSchema::Key_Space_HOLD()
{
	std::cout << "HOLD" << std::endl;
}

void TestControlSchema::Mouse_Movement()
{

}

void TestControlSchema::ScrollMovement()
{

}

void TestControlSchema::Mouse_Left_PRESS()
{
	//std::cout << "Left Button" << std::endl;
}

void TestControlSchema::Mouse_Left_HOLD()
{
	std::cout << "HOLD" << std::endl;
}

void TestControlSchema::W_HOLD()
{
	LevelStore::getActor(EActorType::CAMERA, "MainCamera")->getComponent<TransformComponent>()->getPosition() += LevelStore::getActor(EActorType::CAMERA, "MainCamera")->getComponent<CameraComponent>()->m_Front * cameraSpeed;
	std::cout << "W HOLD" << std::endl;
}

void TestControlSchema::S_HOLD()
{
	LevelStore::getActor(EActorType::CAMERA, "MainCamera")->getComponent<TransformComponent>()->getPosition() -= LevelStore::getActor(EActorType::CAMERA, "MainCamera")->getComponent<CameraComponent>()->m_Front * cameraSpeed;
}

void TestControlSchema::A_HOLD()
{
	
	LevelStore::getActor(EActorType::CAMERA, "MainCamera")->getComponent<TransformComponent>()->getPosition() -= glm::normalize(glm::cross(LevelStore::getActor(EActorType::CAMERA, "MainCamera")->getComponent<CameraComponent>()->m_Front, LevelStore::getActor(EActorType::CAMERA, "MainCamera")->getComponent<CameraComponent>()->m_Up)) * cameraSpeed;
}

void TestControlSchema::D_HOLD()
{
	LevelStore::getActor(EActorType::CAMERA, "MainCamera")->getComponent<TransformComponent>()->getPosition() += glm::normalize(glm::cross(LevelStore::getActor(EActorType::CAMERA, "MainCamera")->getComponent<CameraComponent>()->m_Front, LevelStore::getActor(EActorType::CAMERA, "MainCamera")->getComponent<CameraComponent>()->m_Up)) * cameraSpeed;
}

void TestControlSchema::E_HOLD()
{
	LevelStore::getActor(EActorType::CAMERA, "MainCamera")->getComponent<TransformComponent>()->getPosition() += LevelStore::getActor(EActorType::CAMERA, "MainCamera")->getComponent<CameraComponent>()->m_Up * cameraSpeed;
}

void TestControlSchema::Q_HOLD()
{
	LevelStore::getActor(EActorType::CAMERA, "MainCamera")->getComponent<TransformComponent>()->getPosition() -= LevelStore::getActor(EActorType::CAMERA, "MainCamera")->getComponent<CameraComponent>()->m_Up * cameraSpeed;
}
