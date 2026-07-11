#include <gtest/gtest.h>
#include "math-core.hpp"

TEST(Vec3Construction, DefaultConstructorCreatesZeroVector)
{
    const Vec3 vector{};

    EXPECT_DOUBLE_EQ(vector.x, 0.0);
    EXPECT_DOUBLE_EQ(vector.y, 0.0);
    EXPECT_DOUBLE_EQ(vector.z, 0.0);
}
