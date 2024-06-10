#include <iostream>
#include "gtest/gtest.h"

int add(int a, int b)
{
    return a + b;
}

class GlobalTest
{
    ~GlobalTest() = default;
    void SetUp() {};
    void TearDown() {};
};

TEST(GlobalTest, AddTest)
{
    int ret = add(1, 2);
    ASSERT_EQ(ret, 3);
}

#if GTEST_ENABLED

int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    int ret = RUN_ALL_TESTS();
    return ret;
}

#else
int main()
{
    std::cout<< 123 << std::endl;
    return 0;
}

#endif