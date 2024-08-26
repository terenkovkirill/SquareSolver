
#ifndef SOLVING1_H
#define SOLVING1_H
#include <stdio.h>

const double Eps = 0.0001;
enum Direct {
    NO_ROOTS = 0,
    ONE_ROOT = 1,
    TWO_ROOTS = 2,
    INFINITY_ROOTS = 3
};

int  CleanAndCheckBuffer();
void InputData   (double *adrs_a, double *adrs_b, double *adrs_c);
int  CompareNum  (double num1, double num2);
int  SolveSquare (double a, double b, double c, double *adrs_x1, double *adrs_x2);
void PrintRoots  (int nRoots, double x1, double x2);

#endif
