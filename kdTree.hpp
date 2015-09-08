#ifndef SIMPLEKDTREE_KDTREE_HPP
#define SIMPLEKDTREE_KDTREE_HPP

#include <cstddef>
#include <memory>
#include <numeric>

template<class pointType>
class node
{
public:
    typedef node<pointType> childType;

    node(size_t const splitDimension, size_t const treeIndex)
    :mSplitDimension(splitDimension),mTreeIndex(treeIndex)
    ,mLeftChild(std::unique_ptr< childType >(nullptr))
    ,mRightChild(std::unique_ptr< childType >(nullptr))
    {

    }

    std::unique_ptr<childType> leftChild()
    {
        return mLeftChild;
    }

    std::unique_ptr<childType> rightChild()
    {
        return mLeftChild;
    }

private:
    size_t mSplitDimension;
    size_t mTreeIndex;
    std::unique_ptr<childType> mLeftChild;
    std::unique_ptr<childType> mRightChild;
};

#endif //SIMPLEKDTREE_KDTREE_HPP
