
#ifndef TESTS1_H
#define TEST1_H
#include <stdio.h>
#include "Head_Solving1.h"
struct CheckData
{
    double a, b, c;
    double x1Expected, x2Expected;
    int nRootsExpected, nTest;
};

void RunTest (const struct CheckData test);

void CheckAllTests();


#endif
    double a, b, c;
    double x1Expected, x2Expected;
    int nRootsExpected, nTest;
};
