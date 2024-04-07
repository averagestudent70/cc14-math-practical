/*
    Compute the following integral by 6 point Gauss quadrature rule.
    int_1.1 ^3.3 (e^(0.03 * sin(x)) / (x^2 + 0.0009)) dx

    Output:
    Integration by 6 point Gauss Quadrature Rule
    Enter limits of integration
    Lower limit: 1.1
    Upper limit: 3.3
    Enter the number of points: 6

    Give the non-negative value of u[0]:  0.2386191861
    Give the corresponding value of w[0]: 0.4679139346

    Give the non-negative value of u[1]:  0.6612093865
    Give the corresponding value of w[1]: 0.3607615730

    Give the non-negative value of u[2]:  0.9324695142
    Give the corresponding value of w[2]: 0.1713244924

    The integration value is 0.620976
*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define MAX_LEN 10

double f(double x)
{   
    return exp(0.03 * sin(x)) / (pow(x,2) + 0.0009);
}

int main()
{
    int n = 6, m = 0, i;
    double u[MAX_LEN] = {0}, w[MAX_LEN] = {0};
    double I = 0, a = 1.1, b = 3.3;

    printf("Integration by 6 point Gauss Quadrature Rule\n");
    printf("Enter limits of integration\n");
    printf("Lower limit: ");
    scanf("%lf", &a);
    printf("Upper limit: ");
    scanf("%lf", &b);
    printf("Enter the number of points: ");
    scanf("%d", &n);
    printf("\n");

    m = (n%2 == 0) ? n/2 : (n+1)/2;
    if (m > MAX_LEN)
    {
        printf("Too many points.\n");
        exit(EXIT_FAILURE);
    }

    for (i = 0; i < m; i++)
    {
        printf("Give the non-negative value of u[%d]:  ", i);
        scanf("%lf", &u[i]);
        printf("Give the corresponding value of w[%d]: ", i);
        scanf("%lf", &w[i]);
        printf("\n");
    }

    if (n % 2 == 0)
    {
        I = 0;
        i = 0;
    }
    else
    {
        I = w[0] * f((u[0]*(b - a) + (a + b)) / 2);
        i = 1;
    }

    for ( ; i < m; i++)
        I = I + w[i] * (f((u[i]*(b - a) + (a + b)) / 2) + f((-u[i]*(b - a) + (a + b)) / 2));

    I = (b - a) * I / 2;
    printf("The integration value is %f\n", I);
     
    return 0;
}