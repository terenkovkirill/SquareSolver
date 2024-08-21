#include <TXLib.h>
#include <stdio.h>
#include <math.h>

const float E = 0.001;
const int NO_ROOTS = 0;
const int ONE_ROOT = 1;
const int TWO_ROOTS = 2;
const int INFINITY_ROOTS = 3;

int Compare_Zero(float number)
{
    if (abs(number) < E)
    {
        return 1;                //������������ < 0, ��� ������
    }
    else
    {
        return 0;
    }

}

int SolveSquare (float a, float b, float c, float *adrs_x1, float *adrs_x2)  //������� ����� ������
{
    float discr;
    discr = b*b - 4*a*c;
    if (Compare_Zero(discr))
    {
        *adrs_x1 = - b / (2*a);
        return ONE_ROOT;
    }
    else if (discr < 0)
    {
        return NO_ROOTS;              //������������ < 0, ��� ������
    }
    else
    {
        if (Compare_Zero(a))
        {
            if (Compare_Zero(b))
            {
                if (Compare_Zero(c))
                {
                    return INFINITY_ROOTS;         //a = b = c = 0, ����� ������
                }
                else
                {
                    return NO_ROOTS;         //a = 0, b = 0, c != 0, ��� ������
                }
            }
            else
            {
                *adrs_x1 = - c / b;
                return ONE_ROOT;          //a = 0, b != 0,  ���� ������
            }

        }
        else
        {
            *adrs_x1 = (- b + sqrt(discr)) / (2*a);
            *adrs_x2 = (-b - sqrt(discr)) / (2*a);
            return TWO_ROOTS;             //a != 0  ��� �����
        }
    }
}

void printRoots(int nRoots, float x1, float x2)
{
    switch(nRoots)                     /*������� ��������� ���������� nRoots*/
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

int main(void)
{
    float a, b, c, x1, x2;
    int nRoots;
    scanf ("%g %g %g", &a, &b, &c) ;
    x1 = x2 = 0;
    nRoots = SolveSquare (a, b, c, &x1, &x2);
    printRoots(nRoots, x1, x2);
}








int CheckTest(int nTest, float a, float b, float c, float x1Expected, float x2Expected, int nRootsExpected)
{
    float x1 = 0, x2 = 0;
    int nRoots = SolveSquare (a, b, c, &x1, &x2);
    //if (nRoots != nRootsExpected
}


