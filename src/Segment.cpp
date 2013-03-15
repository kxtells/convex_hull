#include "Segment.h"
#include <cmath>

using std::ostream;
using std::endl;
using std::pow;
using std::sqrt;

ostream& operator<<(ostream& os,const Segment& p){
    os << p.i << "i " << p.j << "j";
    return os;
}

double Segment::distance() const{
    return sqrt(pow(i,2) + pow(j,2));
}

double Segment::magnitude() const{
    return (*this).distance();
}
