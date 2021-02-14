#include "ActorComponent.h"
#include "Material.h"
#include "Mesh.h"


namespace Squirrel
{
	class RenderComponent : ActorComponent {
		int meshID;
		int textureID;

		void generateDrawCalls();
		void submitDrawCalls();

		void BeginPlay() override;
		void Update() override;
	};
}
 
