/*
    Compute the values of f(x) at x = 0.20 + (R+1)/200 from the following 
    table using Newton's forward interpolation formula.
    x       f(x)
    0.20    1.2922071606
    0.35    1.3397750591
    0.50    1.3890939964
    0.65    1.4402284308
    0.80    1.4932451930
    0.95    1.5482135742
    1.10    1.6052054161
    1.25    1.6642952050
    1.40    1.7255601691
    1.55    1.7890803797
    where R is the last digit of your university roll number.
*/

#include <stdio.h>
#include <stdlib.h>

#define N 5

int main()
{
    double x[N] = {0}, y[N][N] = {0};
    double x_inter = 0, y_inter = 0, u = 0, h = 0, prod = 1; 
    int n = 8;

    printf("Interpolation using Newton's Forward Interpolation fourmula\n");
    printf("Enter the number of points: ");
    scanf("%d", &n);
    if (n > N)
    {
        printf("Too many points\n");
        exit(EXIT_FAILURE);
    }
    printf("\n");
    
    printf("\nThe x points must be equispaced\n");
    printf("Enter the points:\n");
    for(int i = 0; i < n; i++)
    {
        printf("%d x: ", i+1);
        scanf("%lf", &x[i]);
        printf("  y: ");
        scanf("%lf", &y[i][0]);        
    }

    printf("\nEnter the value for which interpolation is required: ");
    scanf("%lf", &x_inter);
    printf("\n");

    // difference table
    for (int j = 1; j < n; j++)
    {
        for (int i = 0; i < n-j; i++)
            y[i][j] = y[i+1][j-1] - y[i][j-1];
    }

    printf("The difference table is:\n");
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n-i; j++)
            printf("%f\t", y[i][j]);
        printf("\n");
    }

    h = x[1] - x[0];
    u = (x_inter - x[0]) / h;
    prod = 1;
    y_inter = y[0][0];
    for (int j = 1; j < n; j++)
    {
        prod *= (u - j-1) / j;
        y_inter += prod * y[0][j];
    }

    printf("The functional value at x = %f is %f\n", x_inter, y_inter);

    return 0;
}