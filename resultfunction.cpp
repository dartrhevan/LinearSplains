#include "resultfunction.h"

double ResultFunction::operator()(double x) const
{
    assert(x >= splains[0].getBegin() && x <= splains[splains.size() - 1].getEnd());
    auto splain = std::find_if(splains.begin(), splains.end(),
        [x](const ElementaryFunction& f){
        return f.getBegin() <= x && f.getEnd() >= x; });
    return (*splain)(x);
}
/*
ResultFunction &ResultFunction::operator=(ResultFunction &&o) noexcept
{
    splains = std::move(o.splains);
    return *this;
}

ResultFunction::ResultFunction(ResultFunction &&o) noexcept : splains(std::move(o.splains))
{

}
*/
ResultFunction::ResultFunction()
{

}

void ResultFunction::addSplain(const ElementaryFunction &splain)
{
    splains.push_back(splain);
}

std::string ResultFunction::toString() const
{
    std::ostringstream res;
    for(auto spl : splains)
        res << spl.getK() << std::setprecision(5) << " * x + " << spl.getN() << std::setprecision(5)
            << " при " << spl.getBegin() << std::setprecision(5) << " <= x <= " << spl.getEnd() << std::setprecision(5) << std::endl;
    return res.str();
}
