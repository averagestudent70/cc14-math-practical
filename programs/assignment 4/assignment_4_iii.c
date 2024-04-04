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
	Solution of system of linear equations by Gauss Siedel Method
	Enter the number of equations present: 4
	Enter the number of unknowns: 4

	The system must be diagonally dominant.
	Enter the coefficients of the system:
	5.80  1.28  1.34  -1.70
	2.20  7.14  1.31  0.84
	2.24  -0.75 5.96  1.15
	2.12  1.84  -2.55 7.84

	Enter the right-hand side of the system: -1.65 3.21 -8.44 31.17

	Enter initial approximation of the roots:
	Root 1: 0
	Root 2: 0
	Root 3: 0
	Root 4: 0

	The solution for the given system correct to 6D is:
	Root 1: 1.052471
	Root 2: 0.215882	
	Root 3: -2.340085
	Root 4: 2.879378
*/

#include <stdio.h>
#include <stdbool.h>
#include <math.h>
#define N 10

int main()
{
	int n_eq = 4, n_var = 4; 	// n_equations, n_unknowns
	double a[N][N] = {0}, b[N] = {0};
	double x0[N] = {0}, x1[N] = {0};
	double error = 0.0000001;
	bool flag = false;

	printf("Solution of system of linear equations by Gauss Siedel Method\n");
	printf("Enter the number of equations present: ");
	scanf("%d", &n_eq);
	printf("Enter the number of unknowns: ");
	scanf("%d", &n_var);
	printf("\n");

	if (n_eq > N || n_var > N)
	{
		printf("Too many variables or unknowns.\n");
		return -1;
	}

	printf("The system must be diagonally dominant.\n");
	printf("Enter the coefficients of the system:\n");
	for (int i = 0; i < n_eq; i++)
		for (int j = 0; j < n_var; j++)
			scanf("%lf", &a[i][j]);

	printf("\nEnter the right-hand side of the system: ");    
	for (int i = 0; i < n_eq; i++)
		scanf("%lf", &b[i]);

	printf("\nEnter initial approximation of the roots:\n");
	for (int i = 0; i < n_var; i++)
	{
		printf("Root %d: ", i+1);
		scanf("%lf", &x0[i]);
	}
	printf("\n");

	while (flag == false)
	{
		for (int i = 0; i < n_eq; i++)
		{
			x1[i] = b[i];
			for (int j = 0; j < n_var; j++)
				if (i != j)
					x1[i] = x1[i] - a[i][j]*x0[j];

			// a[i][i] is never zero, as the system is strictly diagonal dominant
			x1[i] /= a[i][i];
		}

		for (int i = 0; i < n_var; i++)
		{
			if (fabs(x1[i]-x0[i]) < error)
				flag = true;
			x0[i] = x1[i];
		}
	}

	printf("The solution for the given system correct to 6D is:\n");
	for (int i = 0; i < n_var; i++)
		printf("Root %d: %.6f\n", i+1, x0[i]);
	printf("\n");

	return 0;
}