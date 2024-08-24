#include <TXLib.h>
#include <stdio.h>
#include <math.h>

/*#ifndef SOLVING_H
#define SOLVING_H


#endif // SOLVING_H */

int CleanAndCheckBuffer();
void InputData (double *adrs_a, double *adrs_b, double *adrs_c);
int CompareNum(double num1, double num2);
int SolveSquare (double a, double b, double c, double *adrs_x1, double *adrs_x2);
void PrintRoots(int nRoots, double x1, double x2);



int CleanAndCheckBuffer()
{
    int el = getchar();
    while (el != '\n')
    {
        if (isspace(el) == 0)   //isspace() = 0 при считывании непробельного символа
        {
            while (el != '\n')
            {
                el = getchar();
            }
            return 0;
        }
        el = getchar();
    }
    return 1;

}


void InputData (double *adrs_a, double *adrs_b, double *adrs_c)
{
    assert (adrs_a != NULL);
    assert (adrs_b != NULL);
    assert (adrs_c != NULL);
    assert (adrs_a != adrs_b);
    assert (adrs_a != adrs_c);
    assert (adrs_b != adrs_c);
    printf ("Please, print 3 numbers \n");
    int x = scanf ("%lg %lg %lg", adrs_a, adrs_b, adrs_c);

    while ((x == 3) * CleanAndCheckBuffer() != 1)
    {
        printf ("Please, print 3 numbers again \n");
        x = scanf ("%lg %lg %lg", adrs_a, adrs_b, adrs_c);
    }
}


int CompareNum(double num1, double num2)
{
    return (fabs(num1 - num2) < Eps);
}


int SolveSquare (double a, double b, double c, double *adrs_x1, double *adrs_x2)
{
    assert (adrs_x1 != NULL);
    assert (adrs_x2 != NULL);
    assert (adrs_x1 != adrs_x2);
    double discr;
    discr = b*b - 4*a*c;
    if (CompareNum(a, 0))
    {
        if (CompareNum(b, 0))
        {
        // TODO: прочитать что такое тернарный оператор
            return CompareNum(c, 0) ? INFINITY_ROOTS : NO_ROOTS;
        }
        else
        {
            *adrs_x1 = - c / b;
            return ONE_ROOT;
        }

    }
    else
    {
        if (CompareNum(discr, 0))
        {
            *adrs_x1 = - b / (2*a);
            return ONE_ROOT;
        }
        else if (discr < 0)
        {
            return NO_ROOTS;
        }
        else
        {
            *adrs_x1 = (- b + sqrt(discr)) / (2*a);
            *adrs_x2 = (-b - sqrt(discr)) / (2*a);
            return TWO_ROOTS;
        }
    }
}


void PrintRoots(int nRoots, double x1, double x2)
{
    switch(nRoots)
    {
        case NO_ROOTS:  printf ("No solutions \n");
                        break;
        case ONE_ROOT:  printf ("One solution %g \n", x1);
                        break;
        case TWO_ROOTS: printf ("Two solutions %g %g \n", x1, x2);
                        break;
        case INFINITY_ROOTS:    printf ("Any solution \n");
                                break;
        default:    printf ("main(): ERROR: nRoots = %d \n", nRoots);
                    break;
    }
}
