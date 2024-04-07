/*
	Solve the following system of linear equations by Gauss Jacobi method correct to 6D. 
	AX = b 					
	A = 4.10 + p    1.28        1.34        -1.70
		2.20		5.44 + p    1.31        0.84 
		2.24        -0.75       4.26 + p    1.15 
		2.12        1.84        -2.55       6.14 + p 
	b = [-1.65 3.21 -8.44 31.17]T and 
	X = [x1 x2 x3 x4]T. 
	Here p = 1.5 + R/2 and R is the last digit of your university roll number.

	Output:
	Solution of system of linear equations by Gauss Jacobi Method
	Enter the number of equations present: 4

	The system must be diagonally dominant.
	Enter the coefficients of the system:
	7.60  1.28  1.34  -1.70
	2.20  8.94  1.31  0.84
	2.24  -0.75 5.96  7.76
	2.12  1.84  -2.55 9.64

	Enter the right-hand side of the system: -1.65 3.21 -8.44 31.17     

	Enter initial approximation of the roots:
	Root 1: 0
	Root 2: 0
	Root 3: 0
	Root 4: 0

	The solution for the given system correct to 6D is:
	Root 1: 0.821157
	Root 2: 0.579464
	Root 3: -4.078072
	Root 4: 1.863470
*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>
#define N 10

int main()
{
	int n = 4;
	double a[N][N] = {0}, b[N] = {0};
	double x0[N] = {0}, x1[N] = {0};
	double error = 0.0000001;
	bool flag = false;

	printf("Solution of system of linear equations by Gauss Jacobi Method\n");
	printf("Enter the number of equations present: ");
	scanf("%d", &n);
	printf("\n");

	if (n > N)
	{
		printf("Too many equations\n");
		exit(EXIT_FAILURE);
	}

	printf("The system must be diagonally dominant.\n");
	printf("Enter the coefficients of the system:\n");
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			scanf("%lf", &a[i][j]);

	printf("\nEnter the right-hand side of the system: ");    
	for (int i = 0; i < n; i++)
		scanf("%lf", &b[i]);

	printf("\nEnter initial approximation of the roots:\n");
	for (int i = 0; i < n; i++)
	{
		printf("Root %d: ", i+1);
		scanf("%lf", &x0[i]);
	}
	printf("\n");

	while (flag == false)
	{
		for (int i = 0; i < n; i++)
		{
			x1[i] = b[i];
			for (int j = 0; j < n; j++)
			{
				if (i != j)
					x1[i] = x1[i] - a[i][j]*x0[j];
			}
			
			if (a[i][i] == 0)
			{
				printf("The coefficient matrix must be diagonally dominant\n");
				printf("A[%d][%d] is zero\n", i, i);
				exit(EXIT_FAILURE);
			}
			x1[i] /= a[i][i];
		}

		for (int i = 0; i < n; i++)
		{
			if (fabs(x1[i]-x0[i]) < error)
				flag = true;
			x0[i] = x1[i];
		}
	}

	printf("The solution for the given system correct to 6D is:\n");
	for (int i = 0; i < n; i++)
		printf("Root %d: %.6f\n", i+1, x0[i]);
	printf("\n");

	return 0;
}