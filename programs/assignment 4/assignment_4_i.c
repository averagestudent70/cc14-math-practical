/*
    Find the solution of the following system of linear equations by LU
    decomposition method correct upto 4D.
    
    (1.1161+d)*x + 0.1254*y + 0.1397*z + 0.1490*t = 1.5471
    0.1582*x + (1.1675+d)*y + 0.1768*z + 0.1871*t = 1.6471
    0.1968*x + 0.2071*y + (1.2168+d)*z + 0.2271*t = 1.7471
    0.2368*x + 0.2471*y + 0.2568*z + (1.2671+d)*t = 1.8471

    where d=R/10 and R is the last digit of your university roll number.

	Output:
	Enter the number of equations present: 4

	The diagonal elements must be numerically largest
	Enter the coefficients of the system:
	1.5161  0.1254  0.1397  0.1490
	0.1582  1.5675  0.1768  0.1871
	0.1968  0.2071  1.6168  0.2271
	0.2368  0.2471  0.2568  1.6671

	Enter the right-hand side of the system: 1.5471 1.6471 1.7471 1.8471

	The lower triangular matrix is:
	1.516100	0.000000	0.000000	0.000000	
	0.158200	1.554415	0.000000	0.000000	
	0.196800	0.190822	1.578751	0.000000	
	0.236800	0.227514	0.211236	1.593738	

	The upper triangular matrix is:
	1.000000	0.082712	0.092144	0.098278	
	0.000000	1.000000	0.104363	0.110365	
	0.000000	0.000000	1.000000	0.118257	
	0.000000	0.000000	0.000000	1.000000	

	The solution for the given system correct to 6D is:
	Root 1: 0.781478
	Root 2: 0.871437
	Root 3: 0.874727
	Root 4: 0.878007
*/

#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#define N 10

/*
	Decomposes matrix a into lower and upper triangular matrix l and u respectively.
	The diagonal elements of matrix u are 1.
	exit(EXIT_FAILURE) if l[i][i] is zero.
*/
void lu_decompose(double a[][N], double l[][N], double u[][N], int n)
{
	for (int i = 0; i < n; i++)
		u[i][i] = 1;

	for (int i = 0; i < n; i++)
	{
		// compute ith row of l
		for (int j = 0; j <= i; j++)
		{
			double sum = 0;
			for (int k = 0; k < i; k++)
				sum += l[i][k] * u[k][j];

			l[i][j] = a[i][j] - sum;
		}

		// compute ith row of u
		for (int j = i+1; j < n; j++)
		{
			double sum = 0;
			for (int k = 0; k < i; k++)
				sum += l[i][k] * u[k][j];
			
			if (l[i][i] == 0) 
			{
				printf("l[%d][%d] is zero. Cannot divide by zero\n", i, i);
				exit(EXIT_FAILURE);
			}
			u[i][j] = (a[i][j] - sum) / l[i][i];
		}
	}
}

/*
    a must be a lower triangular matrix.
    exit(EXIT_FAILURE) if a[i][i] == 0
*/
void forward_substitute(double a[][N], double b[], double x[], int n)
{
    for (int i = 0; i < n; i++)
    {
        double root = b[i];
        for (int j = 0; j < i; j++)
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
    a must be an upper triangular matrix.
    exit(EXIT_FAILURE) if a[i][i] == 0
*/
void back_substitute(double a[][N], double b[], double x[], int n)
{
    for (int i = n-1; i >= 0; i--)
    {
        double root = b[i];
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
	double a[N][N] = {0}, b[N] = {0};
    double l[N][N] = {0}, u[N][N] = {0};
	double x[N] = {0}, z[N] = {0};

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

    lu_decompose(a, l, u, n);

    printf("The lower triangular matrix is:\n");
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
            printf("%.6f\t", l[i][j]);
        printf("\n");
    }
    printf("\n");

	printf("The upper triangular matrix is:\n");
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
            printf("%.6f\t", u[i][j]);
        printf("\n");
    }
    printf("\n");

	forward_substitute(l, b, z, n);
    back_substitute(u, z, x, n);

	printf("The solution for the given system correct to 6D is:\n");
	for (int i = 0; i < n; i++)
		printf("Root %d: %.6f\n", i+1, x[i]);
	printf("\n");

}
