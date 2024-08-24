#include <TXLib.h>
#include <stdio.h>
#include <math.h>

int CheckTest(struct CheckData test);
void AllTests();

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
