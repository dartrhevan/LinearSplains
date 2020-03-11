#include "elementaryfunction.h"

double ElementaryFunction::getN() const
{
    return n;
}

double ElementaryFunction::getK() const
{
    return k;
}

double ElementaryFunction::getEnd() const
{
    return end;
}

double ElementaryFunction::getBegin() const
{
    return begin;
}

double ElementaryFunction::operator()(double x) const
{
    assert(x >= begin && x <= end);
    return x * k + n;
}

ElementaryFunction::ElementaryFunction(double begin, double end, double k, double n)
    : begin(begin), end(end), k(k), n(n)
{}

ElementaryFunction::ElementaryFunction(Point begin, Point end) : begin(begin.getX()), end(end.getX())
{
    k = (end.getY() - begin.getY()) / (end.getX() - begin.getX());
    n = (begin.getY() * end.getX() - end.getY() * begin.getX()) / (end.getX() - begin.getX());
}
