#ifndef INTERPOLATE_H
#define INTERPOLATE_H

#include "resultfunction.h"
#include "elementaryfunction.h"
#include <set>
#include <algorithm>
#include "point.h"

template<class Iter>
ResultFunction interpolate(const Iter& begin, const Iter& end)
{
    //std::sort(points.begin(), points.end());
    ResultFunction res;
    for(auto i = begin; i != end;)
    {
        auto lastPoint = *i;
        i++;
        if(i == end)
            break;
        res.addSplain(ElementaryFunction(lastPoint, *i));
    }
    return res;
}

#endif // INTERPOLATE_H
