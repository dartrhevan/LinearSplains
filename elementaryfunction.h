#ifndef ELEMENTARYFUNCTION_H
#define ELEMENTARYFUNCTION_H

#include <cassert>
#include "point.h"
//function of a type: y = kx + m; x = begin...end
class ElementaryFunction
{
    double begin, end, k, n;
public:
    ElementaryFunction(double begin, double end, double k, double n);
    ElementaryFunction(Point begin, Point end);
    ElementaryFunction& operator= (ElementaryFunction&&) noexcept = default;
    ElementaryFunction(ElementaryFunction&&) noexcept = default;
    ElementaryFunction& operator= (const ElementaryFunction&) noexcept = default;
    ElementaryFunction(const ElementaryFunction&) noexcept = default;
    double getN() const;
    double getK() const;
    double getEnd() const;
    double getBegin() const;
    double operator()(double x) const;
};

#endif // ELEMENTARYFUNCTION_H
