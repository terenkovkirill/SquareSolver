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

int CheckTest(CheckData test);
int CompareNum(double num1, double num2);
int SolveSquare (double a, double b, double c, double *adrs_x1, double *adrs_x2);
void printRoots(int nRoots, double x1, double x2);
void AllTests();
void InputData (double *a, double *b, double *c);

int main(void)
{
    double a, b, c, x1, x2;
    a = b = c = 0;
    int nRoots;
    InputData (&a, &b, &c);
    // TODO: �������� ���������� ������� ��� ����� �����
    x1 = x2 = 0;
    nRoots = SolveSquare (a, b, c, &x1, &x2);
    printRoots (nRoots, x1, x2);
    AllTests();
}


void InputData (double *adrs_a, double *adrs_b, double *adrs_c)
{
    printf ("����������, ������� 3 ����� \n");
    int x = scanf ("%lg %lg %lg", adrs_a, adrs_b, adrs_c);
    if (x != 3)
    {
        printf ("�� ����� ������������ ����� \n");
    }
}

int CompareNum(double num1, double num2)
{
    return (fabs(num1 - num2) < Eps);
}


int SolveSquare (double a, double b, double c, double *adrs_x1, double *adrs_x2)
{
    // TODO: �������� �������� ����� assert ��� ����������
    double discr;
    discr = b*b - 4*a*c;
    assert (adrs_x1 != NULL);
    assert (adrs_x2 != NULL);
    assert (adrs_x1 != adrs_x2);
    if (CompareNum(a, 0))
    {
        if (CompareNum(b, 0))
        {
        // TODO: ��������� ��� ����� ��������� ��������
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


void printRoots(int nRoots, double x1, double x2)
{
    switch(nRoots)
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


//������ ������������

int CheckTest(struct CheckData test)   //������� ������������
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


//����� ������������


//������� enum


/*
1 ������� ���������� ������� �����
2 ����� ���, ��������, ��� ���������� ����� ���������
3 ������� �������� ����� assert, ��������� NULL
4 ������ ������ ������ ��������� ��� ������� � ����������
5 ������� ��� ������������ enum
6 ������� ���� if �� ��������� ��������
7
*/

