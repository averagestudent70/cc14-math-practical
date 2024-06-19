/*
    Compute the dominant eigenvalue of the following matrix correct to 6D by power method:

    A = 8.71+C  -1.15   1.55    -3.08
        -1.15   15.16+C -3.14   2.11
        1.55    -3.14   8.72+C  -1.18
        -3.08   2.11    -1.18   9.25+C

    where C = 1 + R/10; R is the last digit of your university roll number.

    Ouput:
    Calculating the dominant eigenvalue using power method
    Enter the order of the matrix: 4

    Enter the matrix row wise:
    10.11	-1.15	1.55	-3.08
    -1.15	16.56	-3.14	2.11
    1.55	-3.14	10.12	-1.18
    -3.08	2.11	-1.18	10.65

    Enter the intial approximation of the dominant eigenvector: 1 1 1 1

    The dominant eigenvalue is 19.296029
*/

#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <stdbool.h>
#define N 10

/*
    Computes the maximum of the absolute values of the `n` entries in `x`.
*/
double abs_max(double x[], int n)
{
    double l = fabs(x[0]);
    for (int i = 0; i < n; i++)
        if (l < fabs(x[i]))
            l = fabs(x[i]);

    return l;
}

/*
    Returns the dominant eigenvalue of the matrix `a(n*n)`
    Pass the initial approximation of eigenvector in `x`
    Put `x_i=1, i=1...n` for the approximation eigenvector
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
	double a[N][N] = {0}, x[N] = {1};

    printf("Calculating the dominant eigenvalue using power method\n");
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

	printf("\nEnter the intial approximation of the dominant eigenvector: ");    
	for (int i = 0; i < n; i++)
		scanf("%lf", &x[i]);
    printf("\n");
   
    printf("The dominant eigenvalue is %f\n", dom_eigenvalue(a, x, n));

    return 0;
}