#include <iostream>

#include "point.h"

std::istream& operator>> (std::istream& is, point& p){
    is >> p.x >>p.y;
    return is;
}

std::ostream& operator<< (std::ostream& os, const point& p){
    os << p.x << " " << p.y;
    return os;
}

point operator+(point x1,point x2){
    point x3;
    x3.x=x1.x+x2.x;
    x3.y=x1.y+x2.y;
    return x3;
}
point& operator/= (point& x1, int number){
    x1.x=x1.x/number;
    x1.y=x1.y/number;
    return x1;
}