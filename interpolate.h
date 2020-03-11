#ifndef INTERPOLATE_H
#define INTERPOLATE_H

#include "resultfunction.h"
#include "elementaryfunction.h"
#include <vector>
#include <algorithm>
#include "point.h"

ResultFunction interpolate(const std::vector<Point>& points);

#endif // INTERPOLATE_H
