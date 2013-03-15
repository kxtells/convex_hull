#include "Point.h"

using std::ostream;
using std::istream;
using std::endl;
using std::cin;

ostream& operator<<(ostream& os,const Point& p){
    os << "(" << p.x << "," << p.y << ")";
    return os;
}

istream& Point::readin(istream& in){
    cin >> x >> y;
    return in;
}
