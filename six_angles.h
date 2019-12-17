#ifndef D_SIX_ANGLES_H_
#define D_SIX_ANGLES_H_

#include <iostream>
#include "figure.h"


struct six_angles : figure{

    six_angles(std::istream &is);

    point center() const override;
    void print(std::ostream &os) const override;
    void help_print(std::ostream &os) const override;
    double square() const override;
private:
    point one,two,three,four,five,six;
};

#endif