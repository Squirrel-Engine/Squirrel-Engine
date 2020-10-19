#include "SRMath.h"
#include "Vector3.h"
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

    //******************************************************************************************
	
    //--------------VECTOR 3--------------
    Vector3 vec3Add(Vector3 vec1, Vector3 vec2)
    {
        Vector3 out;
        out.x = vec1.x + vec2.x;
        out.y=  vec1.y + vec2.y;
        out.z = vec1.z + vec2.z;
        return out;
    }
    Vector3 vec3Add(Vector3 vec1, float scalarValue)
    {
        Vector3 out;
        out.x = vec1.x + scalarValue;
        out.y = vec1.y + scalarValue;
        out.z = vec1.z + scalarValue;
        return out;
    };
    Vector3 vec3Substract(Vector3 vec1, Vector3 vec2)
    {
        Vector3 out;
        out.x = vec1.x - vec2.x;
        out.y = vec1.y - vec2.y;
        out.z = vec1.z - vec2.z;
        return out;
    }
    Vector3 vec3Substract(Vector3 vec1, float scalarValue)
    {
        Vector3 out;
        out.x = vec1.x - scalarValue;
        out.y = vec1.y - scalarValue;
        out.z = vec1.z - scalarValue;
        return out;
    }
    float vec3DotProduct(Vector3 vec1, Vector3 vec2)
    {
        return vec1.x * vec2.x + vec1.y * vec2.y + vec1.z * vec2.z;
    }
	
    float vec3Magnitude(Vector3 vec1)
    {
        return sqrt(vec1.x * vec1.x + vec1.y * vec1.y + vec1.z * vec1.z);
    }
    bool vec3Compare(Vector3 vec1, Vector3 vec2)
    {
        if ((vec1.x == vec2.x) == true && (vec1.y == vec2.y) == true && (vec1.z == vec2.z) == true) { return true; }
        else { return false; }
    }

	
    float vec3Distance(Vector3 vec1, Vector3 vec2)
    {
        return std::sqrt(pow(vec2.x-vec1.x, 2) + pow(vec2.y - vec1.y, 2) + pow(vec2.z - vec1.z, 2));
    }
	
	float vec3Angle(Vector3 vec1, Vector3 vec2)
	{
        return std::acos(vec3DotProduct(vec1, vec2) / ((vec3Magnitude(vec1)) * vec3Magnitude(vec2)));
	}
    //--------------VECTOR 3--------------
	
}
