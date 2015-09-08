#include <point.hpp>
#include "gtest/gtest.h"

TEST(point, DefaultConstructor)
{
    typedef point<double> pointType;
    const pointType pnt;
    EXPECT_EQ(1, pnt.numDims());
}
