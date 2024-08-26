#include <TXLib.h>
#include <stdio.h>
#include <math.h>
#include "Head_Solving1.h"
#include "Head_Tests1.h"


int main (void)
{
    double a = 0, b = 0, c = 0, x1 = 0, x2 = 0;
    int nRoots = -1;
    InputData (&a, &b, &c);
    nRoots = SolveSquare (a, b, c, &x1, &x2);
    PrintRoots (nRoots, x1, x2);
    CheckAllTests();
}


