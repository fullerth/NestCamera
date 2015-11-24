#include "testfoo.h"

TEST(FactorialTest, Negative)
{
    EXPECT_EQ(1, Factorial(-5));

}
