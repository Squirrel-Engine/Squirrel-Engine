#include <gtest/gtest.h>
#include "../../Squirrel-Engine/include/SRMath.h"

class Vector3Test : public ::testing::Test
{
protected:
    SRMath::Vector3 Vector_Sample_Empty; // Empty Vector2
    SRMath::Vector3 Vector_Sample_Full_1 = SRMath::Vector3(2, 3, 4); // Full Vector2
    SRMath::Vector3 Vector_Sample_Full_2 = SRMath::Vector3(5, 6, 7); // Full Vector2
};

TEST_F(Vector3Test, CreateVector3)
{
    ASSERT_EQ(Vector_Sample_Empty.x, 0);
    ASSERT_EQ(Vector_Sample_Full_1.x, 2);
    ASSERT_EQ(Vector_Sample_Full_1.y, 3);
    ASSERT_EQ(Vector_Sample_Full_1.z, 4);
}

TEST_F(Vector3Test, AddVector3)
{
    ASSERT_EQ(SRMath::vec3Add(Vector_Sample_Full_1, Vector_Sample_Full_2).x, 7);
    ASSERT_EQ(SRMath::vec3Add(Vector_Sample_Full_1, Vector_Sample_Full_2).y, 9);
    ASSERT_EQ(SRMath::vec3Add(Vector_Sample_Full_1, Vector_Sample_Full_2).z, 11);

    ASSERT_EQ(SRMath::vec3Add(Vector_Sample_Full_1, 4.0).x, 6);
    ASSERT_EQ(SRMath::vec3Add(Vector_Sample_Full_1, 4.0).y, 7);
    ASSERT_EQ(SRMath::vec3Add(Vector_Sample_Full_1, 4.0).z, 8);

}

TEST_F(Vector3Test, SubstractVector3)
{
    ASSERT_EQ(SRMath::vec3Substract(Vector_Sample_Full_1, Vector_Sample_Full_2).x, -3);
    ASSERT_EQ(SRMath::vec3Substract(Vector_Sample_Full_1, Vector_Sample_Full_2).y, -3);
    ASSERT_EQ(SRMath::vec3Substract(Vector_Sample_Full_1, Vector_Sample_Full_2).z, -3);

    ASSERT_EQ(SRMath::vec3Substract(Vector_Sample_Full_1, 4.0).x, -2);
    ASSERT_EQ(SRMath::vec3Substract(Vector_Sample_Full_1, 4.0).y, -1);
    ASSERT_EQ(SRMath::vec3Substract(Vector_Sample_Full_1, 4.0).z, 0);
}

TEST_F(Vector3Test, DotProductVector3)
{
    ASSERT_EQ(SRMath::vec3DotProduct(Vector_Sample_Full_1, Vector_Sample_Full_2), 56);
}
/*
TEST_F(Vector3Test, CrossProductVector3)
{
    ASSERT_FALSE(true);
}
*/

TEST_F(Vector3Test, MagnitureVector3)
{
    EXPECT_NEAR (SRMath::vec3Magnitude(Vector_Sample_Full_1), std::sqrt(29), 0.001);
}


TEST_F(Vector3Test, AngleVector3)
{
    EXPECT_NEAR(SRMath::vec3Angle(Vector_Sample_Full_1, Vector_Sample_Full_2), 0.13,0.001);
}

TEST_F(Vector3Test, CompareVector3)
{
    ASSERT_FALSE(SRMath::vec3Compare(Vector_Sample_Full_1, Vector_Sample_Full_2));
    ASSERT_TRUE(SRMath::vec3Compare(Vector_Sample_Full_1, Vector_Sample_Full_1));
}

TEST_F(Vector3Test, DistanceVector3)
{
    EXPECT_NEAR(SRMath::vec3Distance(Vector_Sample_Full_1, Vector_Sample_Full_2), sqrt(27), 0.001);
}

