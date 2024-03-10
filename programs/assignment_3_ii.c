/*
    x^5 + 0.7 * x^4 - 7.77 * x^3 + 22.041 * x^2 - 17.6824*x - 276.46048 = 0
    
    (a) Find a root of the above equation which lies in [2.5, 3.5].
    (b) Find a double root of the above equation which lies in [-3.5, -2.5].
    (c) Find a pair of complex roots of the above equation, one of them has the 
    initial value of 1.4299 + 3.1520i.


    Output:
    Choose 1 for single root.
    Choose 2 for double root.
    Choose 3 for complex roots.
    Enter your choice: 1

    Enter initial approximation of the root: 3

    x                f(x)
    3.000000         -41.228680
    3.106984         3.087858
    3.100032         0.013987
    3.100000         0.000000
    The root of the equation is 3.100000


    

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
    double a0 = 0, b0 = 1, a, b, error = 0.0000001;
    int choice = 1;

    double x = 0, x1 = 0;

    printf("Choose 1 for single root.\n");
    printf("Choose 2 for double root.\n");
    printf("Choose 3 for complex roots.\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);
    printf("\n");

    switch(choice)
    {
        case 1:
            printf("Enter initial approximation of the root: ");
            scanf("%lf", &x);

            printf("\nx \t\t f(x)\n");
            do 
            {
                printf("%f \t %f\n", x, f(x));
                x1 = x - f(x)/df(x);
                x = x1; 

            } while (fabs(f(x)) >= error);

            printf("The root of the equation is %f\n", x);
            break;

        case 2:
        case 3:
        default:
    }

    // printf("Input the root containing interval\n");
    // printf("The lower bound: ");
    // scanf("%lf", &a0);
    // printf("The upper bound: ");
    // scanf("%lf", &b0);
    // printf("\n");

    // a = a0;
    // b = b0;

    // printf("a \t\t b \t\t x \t\t f(x)\n");
    // do 
    // {
    //     x = (a + b) / 2;
    //     printf("%f \t %f \t %f \t %f\n", a, b, x, f(x));

    //     if (f(a) * f(x) > 0)
    //         a = x;
    //     else
    //         b = x;
    // } while (fabs(f(x)) >= error);

    // printf("\nThe root in the interval (%f,%f) correct to 5D is %.5f\n", a0, b0, x);

    return 0;
}