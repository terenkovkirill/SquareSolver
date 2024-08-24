#include <TXLib.h>
#include <stdio.h>
#include <math.h>


const float Eps = 0.0001;
enum direct {NO_ROOTS = 0, ONE_ROOT = 1, TWO_ROOTS = 2, INFINITY_ROOTS = 3};

struct CheckData
{
    double a, b, c;
    double x1Expected, x2Expected;
    int nRootsExpected, nTest;
};

int CleanAndCheckBuffer();
int CheckTest(CheckData test);
int CompareNum(double num1, double num2);
int SolveSquare (double a, double b, double c, double *adrs_x1, double *adrs_x2);
void PrintRoots(int nRoots, double x1, double x2);
void AllTests();
void InputData (double *a, double *b, double *c);
int getchar(void);

int main(void)
{
    double a = 0, b = 0, c = 0, x1 = 0, x2 = 0;
    int nRoots;
    InputData (&a, &b, &c);
    nRoots = SolveSquare (a, b, c, &x1, &x2);
    PrintRoots (nRoots, x1, x2);
    AllTests();
}


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
    while (((x == 3) * (CleanAndCheckBuffer())) == 0)
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
    double discr;
    discr = b*b - 4*a*c;
    assert (adrs_x1 != NULL);
    assert (adrs_x2 != NULL);
    assert (adrs_x1 != adrs_x2);
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


int CheckTest(struct CheckData test)   //функция тестирования
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
    const int nTests = 6;
    struct CheckData test[nTests] = {{.a = 1.0, .b = 2.0, .c = 1.0, .x1Expected = -1.0, .x2Expected = 0.0, .nRootsExpected = ONE_ROOT, .nTest = 1},
                                     {.a = 1.0, .b = 2.0, .c = 3.0, .x1Expected = 0.0, .x2Expected = 0.0, .nRootsExpected = NO_ROOTS, .nTest = 2},
                                     {.a = 0.0, .b = 2.0, .c = 1.0, .x1Expected = -0.5, .x2Expected = 0.0, .nRootsExpected = ONE_ROOT, .nTest = 3},
                                     {.a = 1.0, .b = 3.0, .c = 2.0, .x1Expected = -1.0, .x2Expected = -2.0, .nRootsExpected = TWO_ROOTS, .nTest = 4},
                                     {.a = 0.0, .b = 0.0, .c = 0.0, .x1Expected = 0.0, .x2Expected = 0.0, .nRootsExpected = INFINITY_ROOTS, .nTest = 5},
                                     {.a = 0.0, .b = 0.0, .c = 5.0, .x1Expected = 0.0, .x2Expected = 0.0, .nRootsExpected = NO_ROOTS, .nTest = 6}};
    for (int i = 0; i < nTests; i++)
    {
        CheckTest(test[i]);
    }
}
//Всё ли из struct закинул в функции ?


//Первый собственный коммит с консоли, если повезёт


/*
1 Написал безопасную функцию ввода
3 Написал проверки через assert, используя NULL
4 Выбрал единый способ написания имён функций и переменных
5 Написал тип перечисления enum
6 Заменил один if на тернарный оператор
7 Сделал массив
8 Всё ли я закинул в
*/
