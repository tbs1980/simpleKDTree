#include <simpleKDTree>
#include "gtest/gtest.h"

#include <random>

TEST(node, DefaultConstructor)
{
    typedef double realScalarType;
    typedef point<realScalarType> pointType;
    typedef node<pointType> nodeType;

    nodeType nd(size_t(0),size_t(0));

    EXPECT_EQ(size_t(0),nd.splitDimension());
    EXPECT_EQ(size_t(0),nd.treeIndex());
    EXPECT_EQ(nullptr,nd.leftChild());
    EXPECT_EQ(nullptr,nd.rightChild());
    EXPECT_EQ(false,nd.hasLeftChild());
    EXPECT_EQ(false,nd.hasRightChild());
}


TEST(node, addChild)
{
    typedef double realScalarType;
    typedef point<realScalarType> pointType;
    typedef node<pointType> nodeType;
    typedef nodeType::childType childType;

    nodeType nd(size_t(0),size_t(0));

    nd.addLeftChild(std::unique_ptr<childType>(new childType(size_t(1),size_t(2))));

    EXPECT_EQ(size_t(1),nd.leftChild()->splitDimension());
    EXPECT_EQ(size_t(2),nd.leftChild()->treeIndex());
}

TEST(kdtree, DefaultConstructor)
{
    typedef double realScalarType;
    typedef point<realScalarType> pointType;
    typedef kdTree<pointType> kdTreeType;

    std::default_random_engine generator;

    std::normal_distribution<double> distribution(0.,1.0);

    const size_t numDims = 1;
    const size_t numPoints = 10;

    std::vector<pointType> pts(numPoints);


    for(size_t i=0;i<numPoints;++i)
    {
        std::vector<double> pv(numDims);
        for(size_t j=0;j<numDims;++j)
        {
            pv[j] = distribution(generator);
        }

        pointType pt(pv);

        pts[i] = pt;
    }

    kdTreeType kdtr(pts);
}


/*
TEST(kdTree,Constructor)
{
    typedef double realScalarType;
    typedef point<realScalarType> pointType;

}
*/
