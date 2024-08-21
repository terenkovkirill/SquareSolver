#include <TXLib.h>
#include <stdio.h>
#include <math.h>

int main()
{
    float a, b, c, x1, x2, discr, E;
    int nRoots;
    scanf ("%g %g %g", &a, &b, &c) ;
    discr = b*b - 4*a*c;
    E = 0.001;
    x1 = x2 = 0;
    nRoots = SolveSquare (a, b, c, discr, &x1, &x2);
    switch()
    {
        case 0: printf ("No solutions \n");
                break;
        case 1: printf ("%g \n", x1);
                break;
        case 2: printf ("%g %g \n", x1, x2);
                break;
        case 3: printf ("Any solution \n");
                break;
        default:    printf ("main(): ERROR: nRoots = %d \n", nRoots);
                    break;
    }
}


int SolveSquare(a, b, c, discr, *x1, *x2)  //функция счёта корней
float a, b, c, discr;
int *x1, *x2;
{
    if (abs(discr) < E)
    {
        return 0;                //дискриминант < 0, нет корней
    }
    else
    {
        if (abs(a) - 0 < E)
        {
            if (abs(b) - 0 < E)
            {
                if (abs(c) - 0 < E)
                {
                    return 3;         //a = b = c = 0, любой корень
                }
                else
                {
                    return 0;         //a = 0, b = 0, c != 0, нет корней
                }
            }
            else
            {
                *x1 = - c / b
                return 1;          //a = 0, b != 0,  один корень
            }

        }
        else
        {
            *x1 = (- b + sqrt(discr)) / (2*a);
            *x2 = (-b - sqrt(discr)) / (2*a);
            return 2;             //a != 0  два корня
        }
    }
}


