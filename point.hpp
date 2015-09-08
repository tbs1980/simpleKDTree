#ifndef SIMPLEKDTREE_POINT_HPP
#define SIMPLEKDTREE_POINT_HPP

#include <vector>

template<typename realScalarType>
class point
{
public:
    point()
    :mCoordinates(1,realScalarType(0.)),mNumDims(1)
    {

    }
    
    explicit point(std::vector<realScalarType> const& coordinates)
    :mCoordinates(coordinates),mNumDims(coordinates.size())
    {
        assert(mNumDims>0);
    }

    size_t numDims(void) const
    {
        return mNumDims;
    }

    realScalarType getDimension(size_t i)
    {
        return mCoordinates[i];
    }

private:
    std::vector<realScalarType> mCoordinates;
    size_t mNumDims;
};

#endif //SIMPLEKDTREE_POINT_HPP
