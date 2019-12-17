#include <iostream>

#include "five_angles.h"

five_angles::five_angles(std::istream &is){
    is >> one >> two >> three >> four >> five;
}

point five_angles::center() const {
    point p;
    p=one+two+three+four+five;
    p/=5;
    return p;
}

void five_angles::print(std::ostream &os) const {
    os << one << " " << two << " " << three << " " << four << " " << five <<"\n";
}
void five_angles::help_print(std::ostream &os) const {
    os << "1 " << one << " " << two << " " << three << " " << four << " " << five <<"\n";
}

double five_angles::square() const {
    double s=0;
    s=(one.x*two.y+two.x*three.y+three.x*four.y+four.x*five.y+five.x*one.y-two.x*one.y-
            three.x*two.y-four.x*three.y-five.x*four.y-one.x*five.y)/2;
    if(s<0){
        return -s;
    }else {
        return s;
    }
}