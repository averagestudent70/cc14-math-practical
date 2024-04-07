/*
    Solve the following system of linear equations by Gauss elimination method correct to 6D. 
    AX = B where X = [x1 x2 x3 x4]T and B = [3.49 1.90 -4.00 2.55]T
    A = 5.37 + b    1.99        1.04        -2.02
        1.64        4.43 + b    2.29        0.82
        2.90        0.86        5.95 + b    0.96 
        0.70        -2.00       1.82        4.29 + b 
        
    where b = 3.2 + R/10 and R is the last digit of your university roll number.
    
    Output:
    Solution of system of linear equations by Gaussian Elimination
    Enter the number of equations present: 4

    The diagonal elements must be numerically largest
    Enter the coefficients of the system:
    8.97  1.99  1.04  -2.02
    1.64  8.03  2.29  0.82
    2.90  0.86  9.55  0.96
    0.70  -2.00 1.82  7.89

    Enter the right-hand side of the system: 3.49 1.90 -4.00 2.55
    
    The augmented upper triangular matrix is:
    8.970000	1.990000	1.040000	-2.020000	3.490000	
    0.000000	7.666165	2.099855	1.189320	1.261918	
    0.000000	0.000000	9.154430	1.579458	-5.163976	
    0.000000	0.000000	0.000000	7.980138	3.946321	

    The solution for the given system correct to 6D is:
    Root 1: 0.516771
    Root 2: 0.265773
    Root 3: -0.649417
    Root 4: 0.494518
*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>
#define N 10

/*
    Converts a n*n matrix into an upper triangular matrix
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

int main()
{
	int n = 4;
	double a[N][N+1] = {0}, b[N] = {0}, x[N] = {0};

    printf("Solution of system of linear equations by Gaussian Elimination\n");
	printf("Enter the number of equations present: ");
	scanf("%d", &n);
	printf("\n");

	if (n > N)
	{
		printf("Too many equations\n");
		exit(EXIT_FAILURE);
	}

	printf("The diagonal elements must be numerically largest\n");
	printf("Enter the coefficients of the system:\n");
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			scanf("%lf", &a[i][j]);

	printf("\nEnter the right-hand side of the system: ");    
	for (int i = 0; i < n; i++)
		scanf("%lf", &b[i]);
    printf("\n");

    // augmented matrix
    for (int i = 0; i < n; i++)
        a[i][n] = b[i];

    // upper triangular matrix
    to_upper_triangular(a, n);

    printf("The augmented upper triangular matrix is:\n");
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j <= n; j++)
            printf("%.6f\t", a[i][j]);
        printf("\n");
    }
    printf("\n");

    // back substitution
    back_substitute(a, x, n);

	printf("The solution for the given system correct to 6D is:\n");
	for (int i = 0; i < n; i++)
		printf("Root %d: %.6f\n", i+1, x[i]);
	printf("\n");

    return 0;
}