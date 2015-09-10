#include <simpleKDTree>
#include "gtest/gtest.h"

TEST(point, DefaultConstructor)
{
    typedef double realScalarType;
    typedef point<realScalarType> pointType;

    const pointType pnt;

    // check default dimensionality = 1
    EXPECT_EQ(size_t(1), pnt.numDims());

    // check default value of the corrdinate(0) = 0
    ASSERT_LT( std::abs( realScalarType(0)-pnt.getDimension(0) ),
        std::numeric_limits<realScalarType>::epsilon() );
}
