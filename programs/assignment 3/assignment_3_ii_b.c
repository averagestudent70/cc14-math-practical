/*
    x^5 + 0.7*x^4 - 7.77*x^3 + 22.041*x^2 - 17.6824*x - 276.46048 = 0
    
    (b) Find a double root of the above equation which lies in [-3.5, -2.5].

    Output:
    Root finding by Newton-Raphson Method
    Enter initial approximation of the root: -3.4
    Enter the multiplicity of the root: 2

    x        f(x)
    -3.400000    -16.965000
    -3.119800    -0.064618
    -3.100095    -0.000001
    -3.100000    0.000000

    The root of the equation upto 5D is -3.10000 with multiplicity 2

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
    int m = 2;
    double x = 0, error = 0.0000001;

    printf("Root finding by Newton-Raphson Method\n");
    printf("Enter initial approximation of the root: ");
    scanf("%lf", &x);
    printf("Enter the multiplicity of the root: ");
    scanf("%d", &m);

    printf("\nx \t\t f(x)\n");
    printf("%f \t %f\n", x, f(x));    

    while (fabs(f(x)) >= error) 
    {
        x = x - m * f(x)/df(x);
        printf("%f \t %f\n", x, f(x));
    }

    printf("\n");
    printf("The root of the equation upto 5D is %.5f with multiplicity %d\n", 
        x, m);

    return 0;
}