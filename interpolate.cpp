/*#include "interpolate.h"

template<class Iter>
ResultFunction interpolate(const Iter& begin, const Iter& end)
{
    //std::sort(points.begin(), points.end());
    ResultFunction res;
    for(auto i = begin; i < begin != end;)
    {
        auto lastPoint = *i;
        i++;
        res.addSplain(ElementaryFunction(lastPoint, *i));
    }
    return res;
}
*/
