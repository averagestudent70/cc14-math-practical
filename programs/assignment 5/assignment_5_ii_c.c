/*
    Compute the values of f(x) at x = 0.42 + (R+1)/1000 using the 
    Divided Difference interpolation formula from the following table.
    x       h(x)
    0.12    0.29751
    0.16    0.31145
    0.22    0.31848
    0.29    0.32960
    0.34    0.33774
    0.42    0.34904
    0.49    0.35729
    0.53    0.36976
    where R is the last digit of your university roll number.

    Output:
    Interpolation using Divided Diference Interpolation fourmula
    Enter the number of points: 8

    Enter the points:
    1 x: 0.12
      y: 0.29751
    2 x: 0.16
      y: 0.31145
    3 x: 0.22
      y: 0.31848
    4 x: 0.29
      y: 0.32960
    5 x: 0.34
      y: 0.33774
    6 x: 0.42
      y: 0.34904
    7 x: 0.49
      y: 0.35729
    8 x: 0.53   
      y: 0.36976

    Enter the value for which interpolation is required: 0.425
    The functional value at x = 0.425000 is 0.349649
*/

#include <stdio.h>
#include <stdlib.h>

#define N 10

int main()
{
    double x[N] = {0}, y[N][N] = {0};
    double x_inter = 0, y_inter = 0, prod = 1; 
    int n = 10;

    printf("Interpolation using Divided Difference Interpolation fourmula\n");
    printf("Enter the number of points: ");
    scanf("%d", &n);
    if (n > N)
    {
        printf("Too many points\n");
        exit(EXIT_FAILURE);
    }
    printf("\n");
    
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

    // divided difference table
    for (int j = 1; j < n; j++)
    {
        for (int i = 0; i < n-j; i++)
            y[i][j] = (y[i+1][j-1] - y[i][j-1]) / (x[i+j] - x[i]);
    }

    y_inter = y[0][0];

    for (int j = 1; j < n; j++)
    {
        prod *= x_inter - x[j-1];
        y_inter += prod * y[0][j];
    }

    printf("The functional value at x = %f is %f\n", x_inter, y_inter);

    return 0;
}
