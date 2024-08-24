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
int CleanAndCheckBuffer();

int main(void)
{
    double a = 0, b = 0, c = 0, x1 = 0, x2 = 0;
    int nRoots;
    InputData (&a, &b, &c);
    nRoots = SolveSquare (a, b, c, &x1, &x2);
    PrintRoots (nRoots, x1, x2);
    AllTests();
}


//Всё ли из struct закинул в функции ?



/*
1 Написал безопасную функцию ввода
3 Написал проверки через assert, используя NULL
4 Выбрал единый способ написания имён функций и переменных
5 Написал тип перечисления enum
6 Заменил один if на тернарный оператор
7 Сделал массив
8 Всё ли я закинул в
*/
