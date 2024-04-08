/*
    Fit a curve of the form y = a + b*x^2 to the following data using Least Square
    method correct upto 4D

    x           1.0     2.0     3.0     4.0     5.0     6.0     7.0     8.0
    y - R/10    6.25    8.98    11.63   15.83   19.30   22.53   27.81   31.27

    where R is the last digit of your university roll number.

    Output:
    Curve Fitting using Least Square to the polynomial a + b*x^2
    Enter number of points: 8

    Enter 8 values of x: 1.0     2.0     3.0     4.0     5.0     6.0     7.0     8.0
    Enter 8 values of y: 6.65    9.38    12.03   16.23   19.7    22.93   28.21   31.67
    The polynomial is: 8.3795  + 0.3910*x^2
*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define N 15
#define M 1

/*
    Converts a n*n matrix into an upper triangular matrix
    exit(EXIT_FAILURE) if the diagonal elements are zero.
*/
void to_upper_triangular(double a[][M+1+1], int n)
{
    for (int k = 0; k < n; k++)
    {
        for (int i = k+1; i < n; i++)
        {
            if (a[k][k] == 0)
            {
                printf("The diagonal elements must be numerically largest\n");
                printf("a[%d][%d] is zero\n", k, k);
                exit(EXIT_FAILURE);
            }
            double m = a[i][k]/a[k][k];
            for (int j = k; j < n+1; j++)
                a[i][j] = a[i][j] - m * a[k][j];
        }
    }
}

/*
    a must be augmented upper triangular matrix.
    exit(EXIT_FAILURE) if a[i][i] == 0
*/
void back_substitute(double a[][M+1+1], double x[], int n)
{
    for (int i = n-1; i >= 0; i--)
    {
        double root = a[i][n];
        for (int j = i+1; j < n; j++)
            root = root - a[i][j]*x[j];
        
        if (a[i][i] == 0)
        {
            printf("The diagonal elements must be numerically largest\n");
            printf("a[%d][%d] is zero\n", i, i);
            exit(EXIT_FAILURE);
        }
        x[i] = root / a[i][i];
    }
}

int main()
{
    double x[N] = {0}, y[N] = {0}, a[M+1][M+1+1] = {0}, coeff[M+1] = {0};
    int n = 8, m = 1, num_eqn;

    printf("Curve Fitting using Least Square to the polynomial a + b*x^2\n");

    printf("Enter number of points: ");
    scanf("%d", &n);
    if (n > N)
    {
        printf("Too many points.\n");
        exit(EXIT_FAILURE);
    }
    printf("\n");
    printf("Enter %d values of x: ", n);
    for (int i = 0; i < n; i++)
        scanf("%lf", &x[i]);

    printf("Enter %d values of y: ", n);
    for (int i = 0; i < n; i++)
        scanf("%lf", &y[i]);

    num_eqn = m+1;

    for (int k = 0; k < n; k++)
    {
        for (int i = 0; i < num_eqn; i++)
        {
            for (int j = 0; j < num_eqn; j++)
                a[i][j] = a[i][j] + pow(x[k], 2*(i+j));
        }

        for (int i = 0; i < num_eqn; i++)
            a[i][num_eqn] = a[i][num_eqn] + pow(x[k], 2*i)*y[k];
    }

    // finding coefficients using Gaussian elimination
    to_upper_triangular(a, num_eqn);
    back_substitute(a, coeff, num_eqn);

    printf("The polynomial is: ");
    for (int i = 0; i < m+1; i++)
    {
        if (i == 0)
            printf("%.4f ", coeff[i]);
        else
            printf(" %c %.4f*x^%d", (coeff[i]<0 ? '-':'+'), fabs(coeff[i]), 2*i);
    }
    printf("\n");

    return 0;
}

