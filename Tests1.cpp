#include <TXLib.h>
#include <stdio.h>
#include <math.h>
#include "Head_Tests1.h"
#include "Head_Solving1.h"

void RunTest (const struct CheckData *adrs_test)   //функция тестирования
{
    double x1 = 0, x2 = 0;
    int nRoots = SolveSquare ((adrs_test->a, adrs_test->b, adrs_test->c, &x1, &x2);
    if (nRoots != adrs_test->nRootsExpected || !(CompareNum(x1, adrs_test->x1Expected)) || !(CompareNum(x2, adrs_test->x2Expected)))
    {
        printf ("Error Test %d, a = %g, b = %g, c = %g, x1 = %g, x2 = %g, nRoot = %d \n"
                "Expected: x1 = %g, x2 = %g, nRoots = %d \n",
                adrs_test->nTest, adrs_test->a, adrs_test->b, adrs_test->c, x1, x2, nRoots,
                adrs_test->x1Expected, adrs_test->x2Expected, adrs_test->nRootsExpected);
    }
    else
    {
        printf("All good \n");
    }
}

void CheckAllTests()         //функция с тестами
{
    FILE *test_file
    test_file = fopen("TestNumbers.txt", "r")

    //FILE *test_file;
    //FILE *fopen ("TestNumbers", "r")

    int n = 0;
    struct CheckData test;
    int n = fscanf(test_file, "%lg %lg %lg %lg %lg %d %d \n", &test.a, &test.b, &test.c, &test.c, &test.x1Expected, &test.x2Expected, &test.nRootsExpected, &test.nTest);

    while (n == 7)
    {
        struct CheckData test;
        int n = fscanf (test_file, "%lg %lg %lg %lg %lg %d %d \n", &test.a, &test.b, &test.c, &test.c, &test.x1Expected, &test.x2Expected, &test.nRootsExpected, &test.nTest);
        RunTest (&test);
    }

}
