#include <TXLib.h>
#include <stdio.h>
#include <math.h>
#include "Solving.h"
#include "Tests.h"

#define DEBUG

int main (void)
{
    double a = 0;
    double b = 0;
    double c = 0;

    double x1 = 0;
    double x2 = 0;

    int nRoots = -1;
    InputData (&a, &b, &c);
    nRoots = SolveSquare (a, b, c, &x1, &x2);
    PrintRoots (nRoots, x1, x2);


    #ifdef DEBUG
    CheckAllTests();
    #endif
}






