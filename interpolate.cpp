#include "interpolate.h"



ResultFunction interpolate(const std::vector<Point>& points)
{
    ResultFunction res;
    for(int i = 1; i < points.size(); ++i)
        res.addSplain(ElementaryFunction(points[i - 1], points[i]));
    return res;
}
