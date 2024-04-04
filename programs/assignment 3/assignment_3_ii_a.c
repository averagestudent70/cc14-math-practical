/*
    x^5 + 0.7*x^4 - 7.77*x^3 + 22.041*x^2 - 17.6824*x - 276.46048 = 0
    
    (a) Find a root of the above equation which lies in [2.5, 3.5].

    Output:
    Root finding by Newton-Raphson Method
    Enter initial approximation of the root: 2.7

    x        f(x)
    2.700000     -135.771040
    3.238257     66.620656
    3.111487     5.094133
    3.100086     0.037737
    3.100000     0.000002
    3.100000     0.000000

    The root of the equation correct upto 6D is 3.100000
*/

#include <stdio.h>
#include <math.h>

double f(double x)
{
    return pow(x,5) + 0.7*pow(x,4) - 7.77*pow(x,3) + 22.041*pow(x,2) 
            - 17.6824*x - 276.46048;
}

double df(double x)
{
    return 5*pow(x,4) + 4*0.7*pow(x,3) - 3*7.77*pow(x,2) + 2*22.041*x 
            - 17.6824;
}

int main()
{
    double x = 0, error = 0.0000001;

    printf("Root finding by Newton-Raphson Method\n");
    printf("Enter initial approximation of the root: ");
    scanf("%lf", &x);

    printf("\nx \t\t f(x)\n");
    printf("%f \t %f\n", x, f(x));

    while (fabs(f(x)) >= error) 
    {
        x = x - f(x)/df(x);
        printf("%f \t %f\n", x, f(x));
    }

    printf("\n");
    printf("The root of the equation correct upto 6D is %.6f\n", x);

    return 0;
}