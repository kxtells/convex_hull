#ifndef GEOM_H
#define GEOM_H

#include <vector>
#include <algorithm>
#include "Point.h"
#include "Segment.h"

#define PI 3.14159265

std::vector<Point> chull(const std::vector<Point>&);


bool iscw(const Segment&, const Segment&);
bool iscw(const Point&, const Point&, const Point&);
bool iscw(const std::vector<Point>&);

double angle(const Point&, const Point&, const Point&);
double angle(const std::vector<Point>&);

double rad2deg(const double);

bool point_order_x(const Point&, const Point&);

double scalar_product(Segment&, Segment&);


#endif
