#include "geom.h"
#include "Segment.h"
#include <stdexcept>
#include <cmath>
#include <algorithm>

using std::vector;
using std::domain_error;
using std::acos;
using std::pow;
using std::sort;
using std::copy;
using std::back_inserter;

#include <iostream>
using std::cout;

bool point_order_x(const Point& p1, const Point& p2){
    if (p1.x < p2.x)
        return true;
    else if (p1.x == p2.x)
        return p1.y < p2.y;
    else
        return false;
}

vector<Point> chull(const vector<Point>& pst){
    vector<Point> points(pst);
    vector<Point> lupper,llower,edges;
    typedef vector<Point>::size_type vcs;

    sort(points.begin(),points.end(),point_order_x);
    vector<Point>::const_iterator it;

    //Constructing the upper hull. The point with lowest x will be part of
    //the hull
    lupper.push_back(points[0]);
    lupper.push_back(points[1]);

    //Loop the rest of the points to obtain the upper hull
    for(it=points.begin()+2;it!=points.end();++it){
        lupper.push_back(*it);

        //while size>2 and not a right turn
        while ((lupper.size() > 2) && !iscw(lupper))
            lupper.erase(lupper.end() - 2);
    }

    //Constructing the lower hull.
    it = points.end()-1;
    llower.push_back(*it);
    llower.push_back(*(it-1));

    for(it=points.end()-3;it>=points.begin();--it){
        llower.push_back(*it);

        //while size>2 and not a right turn
        while ((llower.size() > 2) && !iscw(llower))
            llower.erase(llower.end() - 2);

    }

    //First llower is already in lupper
    copy(lupper.begin(),lupper.end(),back_inserter(edges));
    copy(llower.begin()+1,llower.end(),back_inserter(edges)); 
    return edges;
}

double scalar_product(Segment& s1, Segment& s2){
    return (s1.i * s2.i) + (s1.j * s2.j);
}

/** Vector Angle
 *
 * cos <a> = (a * b) / (|a|*|b|)
 */ 
double angle(const Point& p1, const Point& p2, const Point& p3){
    Segment s1 = Segment(p2,p1);
    Segment s2 = Segment(p2,p3);

    return acos(scalar_product(s1,s2) / (s2.magnitude() * s1.magnitude()));
}

double angle(const std::vector<Point>& pg){
    if(pg.size() < 3)
        throw domain_error("Can't compute angle with less than 3 points");
    else{
        vector<Point>::size_type i = pg.size()-1;
        return angle(pg[i-2],pg[i-1],pg[i]);
    }
}


bool iscw(const Segment& s1, const Segment& s2){
    return ((s1.i * s2.j - s1.j * s2.i)) < 0;
}

bool iscw(const Point& p1, const Point& p2, const Point& p3){
    Segment s1 = Segment(p1,p2);
    Segment s2 = Segment(p2,p3);
    return iscw(s1,s2);
}

bool iscw(const std::vector<Point>& pg){
    if(pg.size() < 3)
        throw domain_error("Can't compute iscw with less than 3 points");
    else{
        vector<Point>::size_type i = pg.size()-1;
        return iscw(pg[i-2],pg[i-1],pg[i]);
    }
}

double rad2deg(const double rad){
    return rad * 180 / PI;
}

