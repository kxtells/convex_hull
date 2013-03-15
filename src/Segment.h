#ifndef SEGMENT_H
#define SEGMENT_H

#include <iostream>
#include "Point.h"

class Segment{
    public:
        Point p1;
        Point p2;
        double i,j,k;

        friend std::ostream& operator<<(std::ostream&,const Segment&);
        Segment() {};
        Segment(const Point eb,const Point ee){
            p1 = eb; 
            p2 = ee;
            i  = ee.x - eb.x;
            j  = ee.y - eb.y;
            k  = 0;
        };

        double distance() const;
        double magnitude() const;
};

#endif
