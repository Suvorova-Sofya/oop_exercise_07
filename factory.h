#ifndef D_FACTORY_H_
#define D_FACTORY_H_

#include "document.h"
#include "figure.h"
#include "five_angles.h"
#include "six_angles.h"
#include "eight_angles.h"
#include <vector>
#include <memory>
#include <iostream>

struct factory{
    void construct(std::unique_ptr<document>& vec);
};

#endif