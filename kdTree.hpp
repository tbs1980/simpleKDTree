#ifndef SIMPLEKDTREE_KDTREE_HPP
#define SIMPLEKDTREE_KDTREE_HPP


template<class pointType>
class kdTree
{
public:

    typedef std::vector<pointType> pointsArrayType;
    typedef node<pointType> nodeType;

    kdTree()
    {}

    kdTree(pointsArrayType const& points)
    {
        buildTree(points);
    }

    void buildTree(pointsArrayType const& points)
    {
        mPoints = points;
        mPointIndeces.resize( mPoints.size() );
        std::iota( std::begin(mPointIndeces), std::end(mPointIndeces), 0);

        //mRoot = buildSubtree(size_t(0), std::begin(mPointIndeces),
        //    std::end(mPointIndeces));
    }

    std::unique_ptr< nodeType >&& buildSubtree(size_t splitDimension,
        std::vector<size_t>::iterator begin,
        std::vector<size_t>::iterator end)
    {
        auto rangeSize = std::distance(begin, end);

        if(rangeSize == 0)
        {
            return std::move( std::unique_ptr< nodeType >(nullptr) );
        }

        // otherwise proceed as normal
        std::sort(begin, end,
            [this,splitDimension]( size_t a, size_t b)
            {
                return ( mPoints[a].getDimension(splitDimension)
                    < mPoints[b].getDimension(splitDimension) );
            }
        );

        auto median = begin + rangeSize/2;

        while(median != begin
            && ( mPoints[*(median)].getDimension(splitDimension)
                == mPoints[*(median - 1)].getDimension(splitDimension) ) )
        {
            --median;
            // put all the nodes with equal coord value in the right subtree
        }

        auto ret = std::unique_ptr< nodeType >( new nodeType(splitDimension,*median) );

        ret->addLeftChild( buildSubtree( (splitDimension +1)%mPoints.numDims(),begin, median)  );
        ret->addRightChild( buildSubtree( (splitDimension +1)%mPoints.numDims(),median + 1, end) );

        return std::move(ret);
    }

private:
    std::unique_ptr< nodeType > mRoot;
    pointsArrayType mPoints;
    std::vector<size_t> mPointIndeces;
};


#endif //SIMPLEKDTREE_KDTREE_HPP
