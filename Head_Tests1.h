
#ifndef TESTS1_H
#define TEST1_H
#include <stdio.h>
#include "Head_Solving1.h"

void RunTest (const struct CheckData test);

void CheckAllTests();

struct CheckData
{
    double a, b, c;
    double x1Expected, x2Expected;
    int nRootsExpected, nTest;
};

#endif
    double a, b, c;
    double x1Expected, x2Expected;
    int nRootsExpected, nTest;
};
