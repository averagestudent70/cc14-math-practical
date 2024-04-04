/*
    Find a real root of the following equation correct to 5D by bisection
    method e^{-ax} - 10*a*loge(x) - 0.8 = 0
    where a = (R/10) + 0.2 and R is the last digit of your university 
    roll number.

    Output:
    Root finding by Bisection Method
    Input the root containing interval
    The lower bound: 0
    The upper bound: 2

    a                b               x               f(x)
    0.000000         2.000000        1.000000        -0.251188
    0.000000         1.000000        0.500000        4.099701
    0.500000         1.000000        0.750000        1.563721
    0.750000         1.000000        0.875000        0.592744
    0.875000         1.000000        0.937500        0.157014
    0.937500         1.000000        0.968750        -0.050309
    0.937500         0.968750        0.953125        0.052521
    0.953125         0.968750        0.960938        0.000902
    0.960938         0.968750        0.964844        -0.024754
    0.960938         0.964844        0.962891        -0.011939
    0.960938         0.962891        0.961914        -0.005522
    0.960938         0.961914        0.961426        -0.002311
    0.960938         0.961426        0.961182        -0.000705
    0.960938         0.961182        0.961060        0.000098
    0.961060         0.961182        0.961121        -0.000303
    0.961060         0.961121        0.961090        -0.000102
    0.961060         0.961090        0.961075        -0.000002
    
    The root in the interval (0.000000,2.000000) correct to 5D is 0.96107

*/

#include <stdio.h>
#include <math.h>

#define R 4

double f(double x)
{
    double a = (R / 10.0) + 0.2;
    return exp(-a*x) - 10*a*log(x) - 0.8;
}

int main()
{
    double a0 = 0, b0 = 1, a, b, x, error = 0.00001;

    printf("Root finding by Bisection Method\n");

    printf("Input the root containing interval\n");
    printf("The lower bound: ");
    scanf("%lf", &a0);
    printf("The upper bound: ");
    scanf("%lf", &b0);
    printf("\n");

    if (f(a0) * f(b0) > 0)
    {
        printf("The interval (%f, %f) contains no root.\n", a0, b0);
        return 0;
    }

    a = a0;
    b = b0;

    printf("a \t\t b \t\t x \t\t f(x)\n");
    do 
    {
        x = (a + b) / 2;
        printf("%f \t %f \t %f \t %f\n", a, b, x, f(x));

        if (f(a) * f(x) > 0)
            a = x;
        else
            b = x;
    } while (fabs(f(x)) >= error);

    printf("\nThe root in the interval (%f,%f) correct to 5D is %.5f\n", a0, b0, x);

    return 0;
}