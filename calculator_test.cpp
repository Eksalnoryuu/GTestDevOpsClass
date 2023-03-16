#include <gtest/gtest.h>
#include "calculator.h"
TEST(calculator,Test)
{ 
    int sum = 0;
    int A = 5;
    int B = 5;
    int TestValue = 10;
    sum = Add(A,B);

    GTEST_ASSERT_EQ(sum,TestValue);
}
int main(int argc, char* argv[])
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}