#include <TXLib.h>
#include <stdio.h>
#include <math.h>

const float E = 0.001;
const int NO_ROOTS = 0;
const int ONE_ROOT = 1;
const int TWO_ROOTS = 2;
const int INFINITY_ROOTS = 3;

int Compare_Num(float num1, float num2)
{
    if (abs(num1 - num2) < E)
    {
        return 1;                //дискриминант < 0, нет корней
    }
    else
    {
        return 0;
    }

}


int SolveSquare (float a, float b, float c, float *adrs_x1, float *adrs_x2)  //функция счёта корней
{
    float discr;
    discr = b*b - 4*a*c;
    if (Compare_Num(a, 0))
    {
        if (Compare_Num(b, 0))
        {
            if (Compare_Num(c, 0))
            {
                return INFINITY_ROOTS;         //a = b = c = 0, любой корень
            }
            else
            {
                return NO_ROOTS;         //a = 0, b = 0, c != 0, нет корней
            }
        }
        else
        {
            *adrs_x1 = - c / b;
            return ONE_ROOT;          //a = 0, b != 0,  один корень
        }

    }
    else
    {
        if (Compare_Num(discr, 0))
        {
            *adrs_x1 = - b / (2*a);
            return ONE_ROOT;
        }
        else if (discr < 0)
        {
            return NO_ROOTS;              //дискриминант < 0, нет корней
        }
        else
        {
            *adrs_x1 = (- b + sqrt(discr)) / (2*a);
            *adrs_x2 = (-b - sqrt(discr)) / (2*a);
            return TWO_ROOTS;             //a != 0  два корня
        }
    }
}


void printRoots(int nRoots, float x1, float x2)
{
    switch(nRoots)                     /*перебор вариантов переменной nRoots*/
    {
        case NO_ROOTS: printf ("No solutions \n");
                break;
        case ONE_ROOT: printf ("One solution %g \n", x1);
                break;
        case TWO_ROOTS: printf ("Two solutions %g %g \n", x1, x2);
                break;
        case INFINITY_ROOTS: printf ("Any solution \n");
                break;
        default:    printf ("main(): ERROR: nRoots = %d \n", nRoots);
                    break;
    }
}


//Начало тестирования

int CheckTest(int nTest, float a, float b, float c, float x1Expected, float x2Expected, int nRootsExpected)
{
    float x1 = 0, x2 = 0;
    int nRoots = SolveSquare (a, b, c, &x1, &x2);
    if (nRoots != nRootsExpected || not(Compare_Num(x1, x1Expected)) || not(Compare_Num(x2, x2Expected))
    {
        printf ("Error Test %d, a = %g, b = %g, c = %g, x1 = %g, x2 = %g, nRoot = %d \n"
                "Expected: x1 = %g, x2 = %g, nRoots = %d \n",
                nTest, a, b, c, x1, x2, nRoots,
                x1Expected, x2Expected, nRootsExpected);
    }
    else
    {
        printf("All good \n");
    }
}

//Конец тестирования

int main(void)
{
    float a, b, c, x1, x2;
    int nRoots;
    scanf ("%g %g %g", &a, &b, &c) ;
    x1 = x2 = 0;
    nRoots = SolveSquare (a, b, c, &x1, &x2);
    printRoots (nRoots, x1, x2);
    CheckTest(0, 1.0, 2.0, 1.0, -1.0, 0.0, ONE_ROOT);
    CheckTest(1, 1.0, 2.0, 3.0, 0.0, 0.0, NO_ROOTS);
    CheckTest(2, 0.0, 2.0, 1.0, -0.5, 0.0, ONE_ROOT);
    CheckTest(3, 1.0, 3.0, 2.0, -1.0, -2.0, TWO_ROOTS);
    CheckTest(4, 0.0, 0.0, 0.0, 0.0, 0.0, INFINITY_ROOTS);
    CheckTest(5, 0.0, 0.0, 5.0, 0.0, 0.0, NO_ROOTS);
    float a1 = 0;
    a1 = a1 * 4;
    printf ("%g", a1);
}
