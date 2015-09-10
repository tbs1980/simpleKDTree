#ifndef SIMPLEKDTREE_NODE_HPP
#define SIMPLEKDTREE_NODE_HPP

template<class pointType>
class node
{
public:
    typedef node<pointType> childType;

    node(size_t const splitDimension, size_t const treeIndex)
    :mSplitDimension(splitDimension),mTreeIndex(treeIndex)
    ,mLeftChild( std::unique_ptr<childType>(nullptr) ),mRightChild( std::unique_ptr<childType>(nullptr) )
    ,mHasLeftChild(false),mHasRightChild(false)
    {

    }

    std::unique_ptr<childType>&& leftChild()
    {
        return std::move(mLeftChild);
    }

    std::unique_ptr<childType>&& rightChild()
    {
        return std::move(mLeftChild);
    }

    void addLeftChild(std::unique_ptr<childType> && child)
    {
        mLeftChild = std::move(child);
    }

    void addRightChild(std::unique_ptr<childType> && child)
    {
        mRightChild = std::move(child);
    }

    size_t splitDimension() const
    {
        return mSplitDimension;
    }

    size_t treeIndex() const
    {
        return mTreeIndex;
    }

    bool hasLeftChild() const
    {
        return mHasLeftChild;
    }

    bool hasRightChild() const
    {
        return mHasRightChild;
    }

private:
    size_t mSplitDimension;
    size_t mTreeIndex;
    std::unique_ptr<childType> mLeftChild;
    std::unique_ptr<childType> mRightChild;
    bool mHasLeftChild;
    bool mHasRightChild;
};

#endif //SIMPLEKDTREE_NODE_HPP
