#include "Skeleton.h"

Skeleton::Skeleton()
{
	bindComponent(&transformComponent);
	bindComponent(&renderComponent);
	bindComponent(&audioComponent);

}

void Skeleton::BeginPlay()
{
	//audioComponent->play();
}

void Skeleton::Update()
{
	
}
