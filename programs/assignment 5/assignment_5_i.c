/*
    Compute the values of f(x) at x = 1.20 + (R+1)/200 and at
    x = 1.43 + (R-10)/400 by Lagrange's interpolation formula from
    the following table
    x       f(x)
    1.12    0.307961
    1.16    0.311448
    1.20    0.321976
    1.26    0.334217
    1.32    0.342368
    1.37    0.357905
    1.43    0.370674
    1.49    0.381982
    where R is the last digit of your university roll number.

    Output:
    Interpolation using Lagrange's fourmula
    Enter the number of points: 8


    Enter the points:
    1 x: 1.12
      y: 0.307961
    2 x: 1.16
      y: 0.311448
    3 x: 1.20
      y: 0.321976
    4 x: 1.26
      y: 0.334217
    5 x: 1.32
      y: 0.342368
    6 x: 1.37
      y: 0.357905
    7 x: 1.43
      y: 0.370674
    8 x: 1.49
      y: 0.381982

    Enter the value for which interpolation is required: 1.2249999
    The functional value at x = 1.225000 is 0.328428

    Output 2:
    Interpolation using Lagrange's fourmula
    Enter the number of points: 8
    
    Enter the points:
    1 x: 1.12
      y: 0.307961
    2 x: 1.16
      y: 0.311448
    3 x: 1.20
      y: 0.321976
    4 x: 1.26
      y: 0.334217
    5 x: 1.32
      y: 0.342368
    6 x: 1.37
      y: 0.357905
    7 x: 1.43
      y: 0.370674
    8 x: 1.49
      y: 0.381982

    Enter the value for which interpolation is required: 1.415
    The functional value at x = 1.415000 is 0.370010
*/

#include <stdio.h>
#include <stdlib.h>

#define N 10

int main()
{
    double x[N] = {0}, y[N] = {0};
    double x_inter = 0, y_inter = 0; 
    int n = 8;

    printf("Interpolation using Lagrange's fourmula\n");
    printf("Enter the number of points: ");
    scanf("%d", &n);
    if (n > N)
    {
        printf("Too many points\n");
        exit(EXIT_FAILURE);
    }
    printf("\n");
    
    printf("\nEnter the points:\n");
    for(int i = 0; i < n; i++)
    {
        printf("%d x: ", i+1);
        scanf("%lf", &x[i]);
        printf("  y: ");
        scanf("%lf", &y[i]);        
    }

    printf("\nEnter the value for which interpolation is required: ");
    scanf("%lf", &x_inter);

    for (int i = 0; i < n; i++)
    {
        double prod = 1;
        for (int j = 0; j < n; j++)
        {
            if (i != j)
            {
                if (x[i] == x[j])
                {
                    printf("The values of x_%d and x_%d cannot be same!\n", 
                            i+1, j+1);
                    exit(EXIT_FAILURE);
                }
                prod *= (x_inter - x[j]) / (x[i] - x[j]);
            }
        }  
        y_inter += prod * y[i];
    }

    printf("The functional value at x = %f is %f\n", x_inter, y_inter);

    return 0;
}