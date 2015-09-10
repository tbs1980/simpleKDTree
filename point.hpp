#ifndef SIMPLEKDTREE_POINT_HPP
#define SIMPLEKDTREE_POINT_HPP


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

    realScalarType getDimension(size_t i) const
    {
        return mCoordinates[i];
    }

    friend std::ostream & operator << ( std::ostream & output, const point & pnt)
    {
        for(size_t i=0;i<pnt.numDims()-1;++i)
        {
            output<<pnt.mCoordinates[i]<<",";
        }
        output<<pnt.mCoordinates[pnt.numDims()-1]<<std::endl;
        return output;
    }

private:
    std::vector<realScalarType> mCoordinates;
    size_t mNumDims;
};

#endif //SIMPLEKDTREE_POINT_HPP
