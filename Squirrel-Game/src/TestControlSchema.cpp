#include "ControlSchema/TestControlSchema.h"
#include "Components/CameraComponent.h"

void TestControlSchema::Key_SPACE_PRESS()
{
	glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
}

void TestControlSchema::Key_SPACE_RELEASE()
{
	glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
}

void TestControlSchema::Key_Space_HOLD()
{

}

void TestControlSchema::Mouse_Movement()
{
	if (firstMouse)
	{
		lastX = getInterface<IP_Interface>().mouseX;
		lastY = getInterface<IP_Interface>().mouseY;
		firstMouse = false;
	}

	float xoffset = getInterface<IP_Interface>().mouseX - lastX;
	float yoffset = getInterface<IP_Interface>().mouseY - lastY;

	lastX = getInterface<IP_Interface>().mouseX;
	lastY = getInterface<IP_Interface>().mouseY;

	
	xoffset *= sensitivity;
	yoffset *= sensitivity;

	LevelStore::getActor(EActorType::CAMERA, "Player")->getComponent<TransformComponent>()->rotate(yoffset, xoffset, 0);

}

void TestControlSchema::ScrollMovement()
{
	if (cameraSpeed >= 0) {
		cameraSpeed += (getInterface<IP_Interface>().scrollY) / 100.f;
	}
	else {
		cameraSpeed = 0.0f;
	}
}

void TestControlSchema::Mouse_Left_PRESS()
{

}

void TestControlSchema::Mouse_Left_HOLD()
{

}

void TestControlSchema::W_HOLD()
{
	LevelStore::getActor(EActorType::CAMERA, "Player")->getComponent<TransformComponent>()->getPosition() += LevelStore::getActor(EActorType::CAMERA, "Player")->getComponent<CameraComponent>()->getFrontDirection() * cameraSpeed;
}

void TestControlSchema::S_HOLD()
{
	LevelStore::getActor(EActorType::CAMERA, "Player")->getComponent<TransformComponent>()->getPosition() -= LevelStore::getActor(EActorType::CAMERA, "Player")->getComponent<CameraComponent>()->getFrontDirection() * cameraSpeed;
}

void TestControlSchema::A_HOLD()
{

	LevelStore::getActor(EActorType::CAMERA, "Player")->getComponent<TransformComponent>()->getPosition() -= LevelStore::getActor(EActorType::CAMERA, "Player")->getComponent<CameraComponent>()->getRightDirection() * cameraSpeed;
}

void TestControlSchema::D_HOLD()
{
	LevelStore::getActor(EActorType::CAMERA, "Player")->getComponent<TransformComponent>()->getPosition() += LevelStore::getActor(EActorType::CAMERA, "Player")->getComponent<CameraComponent>()->getRightDirection() * cameraSpeed;
}

void TestControlSchema::E_HOLD()
{

	LevelStore::getActor(EActorType::CAMERA, "Player")->getComponent<TransformComponent>()->getPosition() += glm::vec3(0, 1, 0) * cameraSpeed;
}

void TestControlSchema::Q_HOLD()
{
	LevelStore::getActor(EActorType::CAMERA, "Player")->getComponent<TransformComponent>()->getPosition() -= glm::vec3(0, 1, 0) * cameraSpeed;
}