#include <iostream>
#include <vector>
#include "Point.h"
#include "Segment.h"

#include "geom.h"


using std::cout;        using std::cin;
using std::endl;        using std::vector;

void fill_vector_in(vector<Point>& pvec){
    if(cin){
        pvec.clear();
        Point pin;
        
        while(pin.readin(cin)){
            pvec.push_back(pin);
        }
    }
}

void print_vector(const vector<Point>& pvec){
    for(vector<Point>::const_iterator it = pvec.begin();
        it < pvec.end();
        ++it){
        cout << *it << " ";
    }
    cout << endl;
}

void print_vector_gnuplot(const vector<Point>& pvec){
    for(vector<Point>::const_iterator it = pvec.begin();
        it < pvec.end();
        ++it){
        cout << it->x << " " << it->y << endl;
    }
    cout << endl;
}

int main(){
    vector<Point> pvec,edges;
    fill_vector_in(pvec);
    edges = chull(pvec);
    print_vector_gnuplot(edges);
   
    ////right triangle (angle turning left)
    //Point p1 = Point(10,10);
    //Point p2 = Point(20,10);
    //Point p3 = Point(20,20);

    ////right triangle (angle turning right)
    //Point rp1 = Point(10,10);
    //Point rp2 = Point(20,-5);
    //Point rp3 = Point(25,-10);

    //Segment s1 = Segment(p1,p2);

    //cout << p1 << endl;
    //cout << s1 << endl;

    //cout << angle(rp1,rp2,rp3) << endl;
    //cout << angle(rp1,rp2,rp3) * 180 / PI << endl;
    return 0;
}
