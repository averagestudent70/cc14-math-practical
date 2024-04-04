/*
    Solve the following system of linear equations by Gauss elimination method correct to 6D. 
    AX = B where X = [x1 x2 x3 x4]T and B = [3.49 1.90 -4.00 2.55]T
    A = 5.37 + b    1.99        1.04        -2.02
        1.64        4.43 + b    2.29        0.82
        2.90        0.86        5.95 + b    0.96 
        0.70        -2.00       1.82        4.29 + b 
        
    where b = 3.2 + R/10 and R is the last digit of your university roll number.

    Incomplete
    Output:

    Enter the number of equations present: 4
    Enter the number of unknowns: 4

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

void to_upper_triangular(double a[][N+1], int num_eq, int num_var)
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
void back_substitute(double a[][N+1], double x[], int num_eq, int num_var)
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

/*
    Returns true if a[][] * root[] = b[] for rows num_eq_begin to num_eqn_end (exclusive).
*/
bool is_consistent(double a[][N+1], double b[], double root[], 
                    int num_eq_begin, int num_eq_end, int num_var)
{
    for (int i = num_eq_begin; i < num_eq_end; i++)
    {
        double lhs = 0;
        for (int j = 0; j < num_var; j++)
            lhs = lhs + a[i][j]*root[j];

        if (lhs != b[i])
            return false;
    }
    return true;
}

int main()
{
	int num_eq = 4, num_var = 4; 	// num_equations, num_unknowns
	double a[N][N+1] = {0}, b[N] = {0}, x[N] = {0};

	printf("Enter the number of equations present: ");
	scanf("%d", &num_eq);
	printf("Enter the number of unknowns: ");
	scanf("%d", &num_var);
	printf("\n");

	if (num_eq > N || num_var > N)
	{
		printf("Too many variables or unknowns.\n");
		exit(EXIT_FAILURE);
	}

	// printf("The system must be diagonally dominant.\n");
	printf("Enter the coefficients of the system:\n");
	for (int i = 0; i < num_eq; i++)
		for (int j = 0; j < num_var; j++)
			scanf("%lf", &a[i][j]);

	printf("\nEnter the right-hand side of the system: ");    
	for (int i = 0; i < num_eq; i++)
		scanf("%lf", &b[i]);
    printf("\n");

    // augmented matrix
    for (int i = 0; i < num_eq; i++)
        a[i][num_var] = b[i];

    // excluding the consistency equations
    int n_eq;
    if (num_eq > num_var)
        n_eq = num_var;
    else
        n_eq = num_eq;

    // upper triangular matrix
    to_upper_triangular(a, n_eq, num_var);

    printf("The augmented upper triangular matrix is:\n");
    for (int i = 0; i < num_eq; i++)
    {
        for (int j = 0; j <= num_var; j++)
            printf("%.6f\t", a[i][j]);
        printf("\n");
    }
    printf("\n");

    // back substitution
    back_substitute(a, x, n_eq, num_var);

    // consistency check
    if (num_eq > num_var)
    {
        if (!is_consistent(a, b, x, n_eq, num_eq-1 +1, num_var))
        {
            printf("The equations are not consistent.\n");
            return -1;
        }
    }

	printf("The solution for the given system correct to 6D is:\n");
	for (int i = 0; i < num_var; i++)
    {
        if (i > num_eq)   
            printf("(Independent) ");
		printf("Root %d: %.6f\n", i+1, x[i]);
    }
	printf("\n");

    return 0;
}