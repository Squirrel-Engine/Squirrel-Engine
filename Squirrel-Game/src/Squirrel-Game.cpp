// Squirrel-Engine.cpp : Defines the entry point for the application.
#include "../Squirrel-Engine/include/Squirrel.h"
#include "../Squirrel-Engine/include/SelectionNode.h"
#include "../Squirrel-Engine/include/Blackboard.h"
#include "include/Skeleton.h"
#include "include/Camera.h"
#include "include/Light.h"
#include "Squirrel-Game.h"

#include "Player.h"
#include "SkeletonAI/SampleDecorator.h"
#include "SkeletonAI/SampleSequence.h"

class Sandbox : public Application
{
public:
	Sandbox()
	{
	}

	~Sandbox() override
	{
	}

	void Run() override;
};

Application* CreateApplication()
{
	return new Sandbox();
}

void Sandbox::Run()
{
	auto testSchema = new TestControlSchema();
	getInterface<IP_Interface>().setControlSchema(testSchema);

	auto mainCamera = new Camera();
	getInterface<GM_Interface>().levelStore->spawnNewActor(EActorType::CAMERA, mainCamera);

	
	auto skeleton = new Skeleton();
	skeleton->health = 100;
	skeleton->attackPower = 50.5f;
	skeleton->transformComponent->setTransform(0, -2, -5);
	skeleton->renderComponent->C_ShaderID = 0;
	skeleton->renderComponent->C_ModelID = 2;
	skeleton->renderComponent->C_MaterialID_0 = 2;

	//----------------------
	Blackboard* blackBoard = new Blackboard();
	blackBoard->setVariable("test", &skeleton->health);

	blackBoard->setVariable("test1", &skeleton->attackPower);

	std::cout << blackBoard->isBlackboardUpdated() << std::endl;

	std::cout << *blackBoard->getIntVariable("test") << std::endl;
	
	
	skeleton->health = 1000;
	skeleton->attackPower = 70.5f;

	std::cout << blackBoard->isBlackboardUpdated() << std::endl;

	std::cout << blackBoard->isBlackboardUpdated() << std::endl;
	

	BehaviorTree* myTree = new BehaviorTree();
	SampleDecorator* sampleDecorator = new SampleDecorator();
	WalkToDoorAction* walkToDoorAction = new WalkToDoorAction();
	WalkToDoorAction2* walkToDoorAction2 = new WalkToDoorAction2();


	myTree->insertNode(new SelectionNode(), "sampleSelection", EAINode::SELECTION);
	//myTree->insertNode(new SequenceNode(), "sampleSequence", EAINode::SEQUENCE);
	myTree->insertNode(sampleDecorator, "sampleDecorator", EAINode::DECORATOR);
	myTree->insertNode(walkToDoorAction, "walkToDoor", EAINode::ACTION);
	myTree->insertNode(walkToDoorAction2, "walkToDoor2", EAINode::ACTION);
	
	myTree->linkNode("sampleSelection", "sampleDecorator");
	myTree->linkNode("sampleDecorator", "walkToDoor");
	myTree->linkNode("sampleSelection", "walkToDoor2");
	skeleton->aiComponent->behaviorTree = myTree;
	skeleton->aiComponent->blackBoard = blackBoard;
	//----------------------
	
	getInterface<GM_Interface>().levelStore->spawnNewActor(EActorType::ACTOR, skeleton);
	//
	auto light = new Light();
	light->transformComponent->setTransform(0, 5, +10);
	getInterface<GM_Interface>().levelStore->spawnNewActor(EActorType::LIGHT, light);




	
}