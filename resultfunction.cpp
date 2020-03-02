#include "resultfunction.h"

double ResultFunction::operator()(double x) const
{
    assert(x >= splains[0].getBegin() && x <= splains[splains.size() - 1].getEnd());
    auto splain = std::find_if(splains.begin(), splains.end(),
        [x](const ElementaryFunction& f){ return f.getBegin() >= x && f.getEnd() <= x; });
    return (*splain)(x);
}

ResultFunction::ResultFunction()
{

}

void ResultFunction::addSplain(const ElementaryFunction &splain)
{
    splains.push_back(splain);
}
