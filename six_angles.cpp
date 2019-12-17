#include <iostream>

#include "six_angles.h"

six_angles::six_angles(std::istream &is){
    is >> one >> two >> three >> four >> five >>six;
}

point six_angles::center() const {
    point p;
    p=one+two+three+four+five+six;
    p/=6;
    return p;
}

void six_angles::print(std::ostream &os) const {
    os << one << " " << two << " " << three << " " << four << " " << five << " " << six <<"\n";
}
void six_angles::help_print(std::ostream &os) const {
    os <<"2 " << one << " " << two << " " << three << " " << four << " " << five << " " << six <<"\n";
}

double six_angles::square() const {
    double s=0;
    s=(one.x*two.y+two.x*three.y+three.x*four.y+four.x*five.y+five.x*six.y+six.x*one.y-two.x*one.y-
       three.x*two.y-four.x*three.y-five.x*four.y-six.x*five.y-one.x*six.y)/2;
    if(s<0){
        return -s;
    }else {
        return s;
    }
}