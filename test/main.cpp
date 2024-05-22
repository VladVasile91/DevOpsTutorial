#include "gmock/gmock.h"
#include "gtest/gtest.h"
#include <Rectangle.hpp>

TEST(testRectangle, testRectanglePerimeter)
{
    const size_t expectedPerimeter = 30U;
    const Rectangle r1(5U, 10U);
    EXPECT_EQ(r1.calculatePermieter(), expectedPerimeter);
}

TEST(testRectangle, testRectangleArea)
{
    const size_t expectedArea = 40U;
    const Rectangle r1(5U, 10U);
    EXPECT_EQ(r1.calculateArea(), expectedArea);
}

int main(int argc, char** argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
