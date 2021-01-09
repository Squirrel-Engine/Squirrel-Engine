#include "ActorComponent.h"
#include "Material.h"
#include "Mesh.h"


namespace Squirrel
{
	class RenderComponent : ActorComponent {
		Material* material; // This should be vector!!!
		Mesh* mesh;		
	};
}
 
