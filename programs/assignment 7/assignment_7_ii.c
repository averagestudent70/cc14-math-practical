/*
    Evaluate the least (in magnitude) eigenvalue of the following matrix
    correct upto 4D by power method:

    A = 6.37-p  1.99    1.04    -2.55
        1.99    14.43-p 0.86    -2.00
        1.04    0.86    8.95-p  1.82
        -2.55   -2.00   1.82    4.29-p

    where p = 4.5 + 3R/20; R is the last digit of your university roll number.

    Output:
    Calculating the least eigenvalue using power method
    Enter the order of the matrix: 4

    Enter the matrix row wise:
    1.27	1.99	1.04	-2.55
    1.99	9.33	0.86	-2.00
    1.04	0.86	3.85	1.82
    -2.55	-2.00	1.82	-0.81

    Enter the intial approximation of the least eigenvector: 1 1 1 1

    The least eigenvalue is 1.9122
*/

#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <stdbool.h>
#define N 10

double abs_max(double x[], int n)
{
    double l = fabs(x[0]);
    for (int i = 0; i < n; i++)
        if (l < fabs(x[i]))
            l = fabs(x[i]);

    return l;
}

/*
    Converts a n*n matrix into an upper triangular matrix
    The matrix a must be an augmented matrix
    exit(EXIT_FAILURE) if the diagonal elements are zero.
*/
void to_upper_triangular(double a[][N+1], int n)
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
void back_substitute(double a[][N+1], double x[], int n)
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

/*
    Computes the inverse of a(n*n) by Gaussian elimination 
    and stores it in b
    exit(EXIT_FAILURE) if the diagonal elements are zero.
*/
void inverse_matrix(double a[][N], double b[][N], int n)
{
    double x[N];

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
            x[j] = 0;
        x[i] = 1;

        // forming augmented matrix a1 = [a|x]
        double a1[N][N+1];
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                a1[i][j] = a[i][j];

        for (int i = 0; i < n; i++)
            a1[i][n] = x[i];

        to_upper_triangular(a1, n);
        back_substitute(a1, x, n);

        for (int k = 0; k < n; k++)
            b[k][i] = x[k];
    }
}

/*
    Returns the dominant eigenvalue of the matrix a(n*n)
    with initial approximation of eigenvector in x
    Put i=1..n(x_i=1) for the approximation eigenvector
*/
double dom_eigenvalue(double a[][N], double x[], int n)
{
    double x1[N], l, error = 1E-10;
    bool accurate;

    do
    {
        accurate = true;
        // a*x = x1
        for (int i = 0; i < n; i++)
        {
            x1[i] = 0;
            for (int j = 0; j < n; j++)
                x1[i] += a[i][j] * x[j];
        }

        l = abs_max(x1, n);

        for (int j = 0; j < n; j++)
            x1[j] = x1[j]/l;

        for (int j = 0; j < n; j++)
        {
            // keeps accurate to true only if all x[j]'s are close to x1[j]
            if (fabs(x1[j] - x[j]) > error)
                accurate = false;
            x[j] = x1[j];
        }

    } while (!accurate);

    return l;
}

int main()
{
    int n = 4;
	double a[N][N] = {0}, b[N][N], x[N] = {1};

    printf("Calculating the least eigenvalue using power method\n");
	printf("Enter the order of the matrix: ");
	scanf("%d", &n);
	printf("\n");

	if (n > N)
	{
		printf("The order is too large\n");
		exit(EXIT_FAILURE);
	}

	printf("Enter the matrix row wise:\n");
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			scanf("%lf", &a[i][j]);

	printf("\nEnter the intial approximation of the least eigenvector: ");    
	for (int i = 0; i < n; i++)
		scanf("%lf", &x[i]);
    printf("\n");

    inverse_matrix(a, b, n);
    
    printf("The least eigenvalue is %.4f\n", 1/dom_eigenvalue(b, x, n));

    return 0;
}