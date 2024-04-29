/*
    Compute the values of f(x) at x = 1.40 + (R+1)/100 from the following 
    table using Newton's backward interpolation formula.
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

    Output:
    Interpolation using Newton's Backward Interpolation fourmula
    Enter the number of points: 10

    The x points must be equispaced
    Enter the points:
    1 x: 0.20
      y: 1.2922071606
    2 x: 0.35
      y: 1.3397750591
    3 x: 0.50
      y: 1.3890939964
    4 x: 0.65
      y: 1.4402284308
    5 x: 0.80
      y: 1.4932451930
    6 x: 0.95
      y: 1.5482135742
    7 x: 1.10
      y: 1.6052054161
    8 x: 1.25
      y: 1.6642952050
    9 x: 1.40
      y: 1.7255601691
    10 x: 1.55
      y: 1.7890803797

    Enter the value for which interpolation is required: 1.45
    The functional value at x = 1.450000 is 1.7464789516
*/

#include <stdio.h>
#include <stdlib.h>

#define N 10

int main()
{
    double x[N] = {0}, y[N][N] = {0};
    double x_inter = 0, y_inter = 0, u = 0, h = 0, prod = 1; 
    int n = 10;

    printf("Interpolation using Newton's Backward Interpolation fourmula\n");
    printf("Enter the number of points: ");
    scanf("%d", &n);
    if (n > N)
    {
        printf("Too many points\n");
        exit(EXIT_FAILURE);
    }
    printf("\n");
    
    printf("The x points must be equispaced\n");
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

    // difference table
    for (int j = 1; j < n; j++)
    {
        for (int i = 0; i < n-j; i++)
            y[i][j] = y[i+1][j-1] - y[i][j-1];
    }

    h = x[1] - x[0];
    u = (x_inter - x[n-1]) / h;
    y_inter = y[n-1][0];

    for (int j = 1, i = n-2; j < n; j++, i--)
    {
        prod *= (u + (j-1)) / j;
        y_inter += prod * y[i][j];
    }

    printf("The functional value at x = %f is %.10f\n", x_inter, y_inter);

    return 0;
}