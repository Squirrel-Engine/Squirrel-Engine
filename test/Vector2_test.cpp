#include <gtest/gtest.h>
#include "../../Squirrel-Engine/include/SRMath.h"

class Vector2Test : public ::testing::Test
{
    protected:
        SRMath::Vector2 Vector_Sample_Empty; // Empty Vector2
        SRMath::Vector2 Vector_Sample_Full_1 = SRMath::Vector2(2, 3); // Full Vector2
        SRMath::Vector2 Vector_Sample_Full_2 = SRMath::Vector2(4, 5); // Full Vector2
    };

    TEST_F(Vector2Test, CreateVector)
    {
        ASSERT_EQ(Vector_Sample_Empty.x, 0);
        ASSERT_EQ(Vector_Sample_Full_1.x, 2);
        ASSERT_EQ(Vector_Sample_Full_1.y, 3);
    }

	TEST_F(Vector2Test, AddVector2)
    {
    	// VECTOR2 + VECTOR2
        ASSERT_EQ(SRMath::vec2Add(Vector_Sample_Full_1, Vector_Sample_Full_2).x, 6);
        ASSERT_EQ(SRMath::vec2Add(Vector_Sample_Full_1, Vector_Sample_Full_2).y, 8);
    	// VECTOR2 + SCALAR
        ASSERT_EQ(SRMath::vec2Add(Vector_Sample_Full_1, 4.0).x, 6);
        ASSERT_EQ(SRMath::vec2Add(Vector_Sample_Full_1, 4.0).y, 7);
    }

    TEST_F(Vector2Test, SubstractVector2)
    {
        ASSERT_EQ(SRMath::vec2Substract(Vector_Sample_Full_1, Vector_Sample_Full_2).x, -2);
        ASSERT_EQ(SRMath::vec2Substract(Vector_Sample_Full_1, Vector_Sample_Full_2).y, -2);

        // VECTOR2 - SCALAR
        ASSERT_EQ(SRMath::vec2Substract(Vector_Sample_Full_2, 1.0).x, 3);
        ASSERT_EQ(SRMath::vec2Substract(Vector_Sample_Full_2, 1.0).y, 4);
    }

    TEST_F(Vector2Test, DotProductVector2)
    {
        ASSERT_EQ(SRMath::vec2DotProduct(Vector_Sample_Full_1, Vector_Sample_Full_2), 23);
    }


    TEST_F(Vector2Test, MagnitudeVector2)
    {
        ASSERT_TRUE(SRMath::vec2Magnitude(Vector_Sample_Full_1) < 3.7 && SRMath::vec2Magnitude(Vector_Sample_Full_1) > 3.6) ;
    }

    TEST_F(Vector2Test, CompareVector2)
    {
        ASSERT_FALSE(SRMath::vec2Compare(Vector_Sample_Full_1, Vector_Sample_Full_2));
        ASSERT_TRUE(SRMath::vec2Compare(Vector_Sample_Full_1, Vector_Sample_Full_1));
    }
	


