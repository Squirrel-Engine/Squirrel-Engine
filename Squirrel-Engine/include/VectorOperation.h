#include "../../Squirrel-Engine/include/SRMath.h"

namespace SRMath
{
	//--------------VECTOR 2--------------

	// VECTOR2 + VECTOR2
    Vector2 vec2Add(Vector2 vec1, Vector2 vec2) {
        Vector2 out;
        out.x = vec1.x + vec2.x;
        out.y = vec1.y + vec2.y;
        return out;
    }
    // VECTOR2 + SCALAR
    Vector2 vec2Add(Vector2 vec1, float scalarValue) {
        Vector2 out;
        out.x = vec1.x + scalarValue;
        out.y = vec1.y + scalarValue;
        return out;
    }
    // VECTOR2 - VECTOR2
    Vector2 vec2Substract(Vector2 vec1, Vector2 vec2) {
        Vector2 out;
        out.x = vec1.x - vec2.x;
        out.y = vec1.y - vec2.y;
        return out;
    }
    // VECTOR2 - SCALAR
    Vector2 vec2Substract(Vector2 vec1, float scalarValue) {
        Vector2 out;
        out.x = vec1.x - scalarValue;
        out.y = vec1.y - scalarValue;
        return out;
    }
	

	float vec2DotProduct(Vector2 vec1, Vector2 vec2)
    {
        return ((vec1.x * vec2.x) + (vec1.y * vec2.y));
    }

	//|A| = sqrt(x^2 + y^2)
    float vec2Magnitude(Vector2 vec1)
    {
        return sqrt(((pow(vec1.x,2))+(pow(vec1.y,2))));
    }

	bool vec2Compare(Vector2 vec1, Vector2 vec2)
    {
	    if( (vec1.x == vec2.x) == true && (vec1.y == vec2.y) == true){ return true; } else { return false; }
    }
	
    //--------------VECTOR 2--------------


	
    //--------------VECTOR 3--------------
    //--------------VECTOR 3--------------
	
}
