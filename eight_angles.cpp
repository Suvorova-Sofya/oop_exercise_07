#include <iostream>

#include "eight_angles.h"

eight_angles::eight_angles(std::istream &is){
    is >> one >> two >> three >> four >> five >>six >>seven >>eight;
}

point eight_angles::center() const {
    point p;
    p=one+two+three+four+five+six+seven+eight;
    p/=8;
    return p;
}

void eight_angles::print(std::ostream &os) const {
    os << one << " " << two << " " << three << " " << four << " " << five << " " << six << " " << seven
    << " " << eight<<"\n";
}
void eight_angles::help_print(std::ostream &os) const {
    os <<"3 " << one << " " << two << " " << three << " " << four << " " << five << " " << six << " " << seven
       << " " << eight<<"\n";
}

double eight_angles::square() const {
    double s=0;
    s=(one.x*two.y+two.x*three.y+three.x*four.y+four.x*five.y+five.x*six.y+six.x*seven.y+seven.x*eight.y+
            eight.x*one.y-two.x*one.y-three.x*two.y-four.x*three.y-five.x*four.y-six.x*five.y-seven.x*six.y
            -eight.x*seven.y-one.x*eight.y)/2;
    if(s<0){
        return -s;
    }else {
        return s;
    }
}