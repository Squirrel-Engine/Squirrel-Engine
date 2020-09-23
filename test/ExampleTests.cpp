#include <gtest/gtest.h>


#include <string>
using std::string;
const char* actualValTrue = "hello gtest";
const char* actualValFalse = "hello world";
const char* expectVal = "hello gtest";

#include <cmath>

double cubic(double d)
{
    return pow(d, 3);
}

TEST(StrCompare, CStrEqual) {
    EXPECT_STREQ(expectVal, actualValTrue);
}

TEST(StrCompare, CStrNotEqual) {
    EXPECT_STREQ(expectVal, actualValFalse);
}

TEST(StrCompare, Fatih) {
    EXPECT_STREQ("sd", "sdew");
}

TEST(testMath, myCubeTest)
{
    EXPECT_EQ(1000, cubic(10));
}