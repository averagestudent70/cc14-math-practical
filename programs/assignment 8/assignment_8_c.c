/*
    Fit a curve of the form y = a + b*x + c*x^2 + d*x^3 to the following data using Least Square
    method correct upto 4D

    x               3.1     4.1     5.1     6.1     7.1     8.1     9.1     10.1
    y - (R+1)/10    2.3     3.8     7.3     11.2    13.9    17.8    22.6    27.1

    where R is the last digit of your university roll number.

    Output:
    Curve Fitting using Least Square
    Enter degree of fitting polynomial: 3
    Enter number of points: 8

    Enter 8 values of x: 3.1     4.1     5.1     6.1     7.1     8.1     9.1     10.1
    Enter 8 values of y: 2.8     4.3     7.8     11.7    14.4    18.3    23.1    27.6
    The polynomial is: -1.6589  + 0.5124*x^1 + 0.2869*x^2 - 0.0051*x^3
*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define N 15
#define M 10

void to_upper_triangular(double a[][M+1+1], int num_eq, int num_var)
{
    for (int k = 0; k < num_eq; k++)
    {
        for (int i = k+1; i < num_eq; i++)
        {
            // a[k][k] is never zero, as the system is strictly diagonal dominant ??
            double m = a[i][k]/a[k][k];
            for (int j = k; j < num_var+1; j++)
                a[i][j] = a[i][j] - m * a[k][j];
        }
    }
}

/*
    a must be augmented upper triangular matrix.
    exit(EXIT_FAILURE) if a[i][i] == 0
*/
void back_substitute(double a[][M+1+1], double x[], int num_eq, int num_var)
{
    for (int i = num_eq-1; i >= 0; i--)
    {
        double root = a[i][num_var];
        for (int j = i+1; j < num_var; j++)
            root = root - a[i][j]*x[j];
        
        if (a[i][i] == 0)
        {
            printf("Cannot divide by zero as A[%d][%d] is very close to 0\n", i, i);
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
    to_upper_triangular(a, num_eqn, num_eqn);
    back_substitute(a, coeff, num_eqn, num_eqn);

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

