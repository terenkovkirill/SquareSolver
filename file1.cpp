#include <TXLib.h>
#include <stdio.h>
#include <math.h>

const float Eps = 0.0001;
const int NO_ROOTS = 0;
const int ONE_ROOT = 1;
const int TWO_ROOTS = 2;
const int INFINITY_ROOTS = 3;

struct CheckData
{
    double a, b, c;
    double x1Expected, x2Expected;
    int nRootsExpected, nTest;
};


int CheckTest(CheckData test);
int CompareNum(double num1, double num2);
int SolveSquare (double a, double b, double c, double *adrsx1, double *adrsx2);
void printRoots(int nRoots, double x1, double x2);


int CompareNum(double num1, double num2)
{
    return (fabs(num1 - num2) < Eps);
}


int SolveSquare (double a, double b, double c, double *adrsx1, double *adrsx2)  //функция счёта корней
{
    // TODO: написать проверки через assert для указателей
    double discr;
    discr = b*b - 4*a*c;
    if (CompareNum(a, 0))
    {
        if (CompareNum(b, 0))
        {
        // TODO: прочитать что такое тернарный оператор
            if (CompareNum(c, 0))
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
            *adrsx1 = - c / b;
            return ONE_ROOT;          //a = 0, b != 0,  один корень
        }

    }
    else
    {
        if (CompareNum(discr, 0))
        {
            *adrsx1 = - b / (2*a);
            return ONE_ROOT;
        }
        else if (discr < 0)
        {
            return NO_ROOTS;              //дискриминант < 0, нет корней
        }
        else
        {
            *adrsx1 = (- b + sqrt(discr)) / (2*a);
            *adrsx2 = (-b - sqrt(discr)) / (2*a);
            return TWO_ROOTS;             //a != 0  два корня
        }
    }
}


void printRoots(int nRoots, double x1, double x2)
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

int CheckTest(CheckData test)   //функция тестирования
{
    double x1 = 0, x2 = 0;
    int nRoots = SolveSquare (test.a, test.b, test.c, &x1, &x2);
    if (nRoots != test.nRootsExpected || !(CompareNum(x1, test.x1Expected)) || !(CompareNum(x2, test.x2Expected)))
    {
        printf ("Error Test %d, a = %g, b = %g, c = %g, x1 = %g, x2 = %g, nRoot = %d \n"
                "Expected: x1 = %g, x2 = %g, nRoots = %d \n",
                test.nTest, test.a, test.b, test.c, x1, x2, nRoots,
                test.x1Expected, test.x2Expected, test.nRootsExpected);
    }
    else
    {
        printf("All good \n");
    }
}

void AllTests()
{
    struct CheckData test1 = {.a = 1.0, .b = 2.0, .c = 1.0, .x1Expected = -1.0, .x2Expected = 0.0, .nRootsExpected = ONE_ROOT, .nTest = 1};
    struct CheckData test2 = {.a = 1.0, .b = 2.0, .c = 3.0, .x1Expected = 0.0, .x2Expected = 0.0, .nRootsExpected = NO_ROOTS, .nTest = 2};
    struct CheckData test3 = {.a = 0.0, .b = 2.0, .c = 1.0, .x1Expected = -0.5, .x2Expected = 0.0, .nRootsExpected = ONE_ROOT, .nTest = 3};
    struct CheckData test4 = {.a = 1.0, .b = 3.0, .c = 2.0, .x1Expected = -1.0, .x2Expected = -2.0, .nRootsExpected = TWO_ROOTS, .nTest = 4};
    struct CheckData test5 = {.a = 0.0, .b = 0.0, .c = 0.0, .x1Expected = 0.0, .x2Expected = 0.0, .nRootsExpected = INFINITY_ROOTS, .nTest = 5};
    struct CheckData test6 = {.a = 0.0, .b = 0.0, .c = 5.0, .x1Expected = 0.0, .x2Expected = 0.0, .nRootsExpected = NO_ROOTS, .nTest = 6};
    CheckTest(test1);
    CheckTest(test2);
    CheckTest(test3);
    CheckTest(test4);
    CheckTest(test5);
    CheckTest(test6);
}


//Конец тестирования

int main(void)
{
    double a, b, c, x1, x2;
    int nRoots;
    // TODO: написать безопасную функцию для ввода чисел
    int x = scanf ("%lg %lg %lg", &a, &b, &c) ;
    x1 = x2 = 0;
    nRoots = SolveSquare (a, b, c, &x1, &x2);
    printRoots (nRoots, x1, x2);
    AllTests();
}

//нужно объявить переменные вначале
// TODO: выбрать один способ написания имен функций и переменных
//функция enum
