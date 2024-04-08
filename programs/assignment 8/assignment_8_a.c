/*
    Fit a curve of the form y = a + b*x to the following data using Least Square
    method correct upto 4D

    x   2.5     3.5     4.5     5.5     6.5     7.5     8.5     9.5
    y   1.19+k  1.41+k  1.44+k  1.49+k  1.50+k  1.58+k  1.61+k  1.70+k

    where k = (1.5+R)/20, R is the last digit of your university roll number.

    Output:
    Curve Fitting using Least Square
    Enter degree of fitting polynomial: 1
    Enter number of points: 8

    Enter 8 values of x: 2.5  3.5  4.5  5.5  6.5  7.5  8.5  9.5
    Enter 8 values of y: 1.465  1.685  1.715  1.765  1.775  1.855  1.885  1.975
    The polynomial is: 1.4079  + 0.0595*x^1
*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define N 15
#define M 10

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

    printf("Curve Fitting using Least Square\n");
    printf("Enter degree of fitting polynomial: ");
    scanf("%d", &m);
    if (m > M)
    {
        printf("Degree of polynomial too high.\n");
        exit(EXIT_FAILURE);
    }

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
                a[i][j] = a[i][j] + pow(x[k], i+j);
        }

        for (int i = 0; i < num_eqn; i++)
            a[i][num_eqn] = a[i][num_eqn] + pow(x[k], i)*y[k];
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
            printf(" %c %.4f*x^%d", (coeff[i]<0 ? '-':'+'), fabs(coeff[i]), i);
    }
    printf("\n");

    return 0;
}

