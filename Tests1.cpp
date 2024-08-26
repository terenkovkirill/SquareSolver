#include <TXLib.h>
#include <stdio.h>
#include <math.h>
#include "Head_Tests1.h"
#include "Head_Solving1.h"

void RunTest (const struct CheckData *adrs_test)   //функция тестирования
{
    double x1 = 0, x2 = 0;
    // test->a = 10;
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
    const int nTests = 6;
    FILE *test_file
    test_file = fopen("TestNumbers.txt", "r")

    FILE *fp;
    FILE *fopen ("TestNumbers", "r")

    int n = 0;
    while (n == 7)
    {
        struct CheckData test;
        int n = fscanf(test_file, "%lg %lg %lg %lg %lg %d %d \n", &test.a, &test.b, &test.c, &test.c, &test.x1Expected, &test.x2Expected, &test.nRootsExpected, &test.nTest);
        RunTest (&test);
    }

}



/*void CheckAllTests()         //функция с тестами
{
    const int nTests = 6;
    struct CheckData test[nTests] = {{.a = 1.0, .b = 2.0, .c = 1.0, .x1Expected = -1.0, .x2Expected =  0.0, .nRootsExpected = ONE_ROOT,       .nTest = 1},
                                     {.a = 1.0, .b = 2.0, .c = 3.0, .x1Expected =  0.0, .x2Expected =  0.0, .nRootsExpected = NO_ROOTS,       .nTest = 2},
                                     {.a = 0.0, .b = 2.0, .c = 1.0, .x1Expected = -0.5, .x2Expected =  0.0, .nRootsExpected = ONE_ROOT,       .nTest = 3},
                                     {.a = 1.0, .b = 3.0, .c = 2.0, .x1Expected = -1.0, .x2Expected = -2.0, .nRootsExpected = TWO_ROOTS,      .nTest = 4},
                                     {.a = 0.0, .b = 0.0, .c = 0.0, .x1Expected =  0.0, .x2Expected =  0.0, .nRootsExpected = INFINITY_ROOTS, .nTest = 5},
                                     {.a = 0.0, .b = 0.0, .c = 5.0, .x1Expected =  0.0, .x2Expected =  0.0, .nRootsExpected = NO_ROOTS,       .nTest = 6}};*/
