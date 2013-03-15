#ifndef POINT_H
#define POINT_H

#include <iostream>

class Point{
    public:
        double x;
        double y;

        friend std::ostream& operator<<(std::ostream&,const Point&);
        Point() {};
        Point(const int px,const int py){x = px; y = py;};

        std::istream& readin(std::istream&);
};

#endif
