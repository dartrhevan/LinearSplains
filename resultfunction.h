#ifndef RESULTFUNCTION_H
#define RESULTFUNCTION_H

#include "point.h"
#include "elementaryfunction.h"
#include <vector>
#include <algorithm>

class ResultFunction
{

    std::vector<ElementaryFunction> splains;
    double operator()(double x) const;
public:
    ResultFunction();
    void addSplain(const ElementaryFunction& splain);
};

#endif // RESULTFUNCTION_H
