/*
    Solve the following system of linear equations by Gauss Seidel method correct to 4D. 
    AX = B where X = [x1 x2 x3 x4]T and B = [2.48+d 12.44 -10.36 12.78]T

    A = 7.21 + d	2.34		1.42	    -0.81
        2.52		8.56 + d 	-2.22       -0.12
        1.14        0.35        8.88 + d    2.98
        0.23        -2.38       0.59        6.14 + d 
    
    where d = 1.1 + R/4 and R is the last digit of your university roll number.

    Output:
	Solution of system of linear equations by Gauss Siedel Method
	Enter the number of equations present: 4
	Enter the number of unknowns: 4

	The system must be diagonally dominant.
    Enter the coefficients of the system:
    9.31  2.34  1.42  -0.81
    2.52  10.66 -2.22 -0.12
    1.14  0.35  10.98 2.98
    0.23  -2.38 0.59  8.24

    Enter the right-hand side of the system: 4.58 12.44 -10.36 12.78

    Enter initial approximation of the roots:
    Root 1: 0
    Root 2: 0
    Root 3: 0
    Root 4: 0

    The solution for the given system correct to 4D is:
    Root 1: 0.7115
    Root 2: 0.6988
    Root 3: -1.5399
    Root 4: 1.8432

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
				if (j < i)
                    x1[i] = x1[i] - a[i][j]*x1[j];
                else if (j > i)
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

	printf("The solution for the given system correct to 4D is:\n");
	for (int i = 0; i < n_var; i++)
		printf("Root %d: %.4f\n", i+1, x0[i]);
    printf("\n");

	return 0;
}