#ifndef RESULTFUNCTION_H
#define RESULTFUNCTION_H

#include "point.h"
#include "elementaryfunction.h"
#include <vector>
#include <string>
#include <algorithm>
#include <sstream>
#include <iomanip>

class ResultFunction
{

    std::vector<ElementaryFunction> splains;
public:
    ResultFunction();
    double operator()(double x) const;
    ResultFunction& operator= (ResultFunction&&) noexcept = default;
    ResultFunction(ResultFunction&&) noexcept = default;
    ResultFunction& operator= (const ResultFunction&) noexcept = default;
    ResultFunction(const ResultFunction&) noexcept = default;
    void addSplain(const ElementaryFunction& splain);
    std::string toString() const;
    size_t splainsCount() const {
        return splains.size();
    }
};

#endif // RESULTFUNCTION_H
