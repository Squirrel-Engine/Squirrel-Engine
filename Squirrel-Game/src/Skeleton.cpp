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
	transformComponent.rotate(0, 0.2, 0);

	/*for (int i =0; i<1000000; i++)
	{

	}*/
}
