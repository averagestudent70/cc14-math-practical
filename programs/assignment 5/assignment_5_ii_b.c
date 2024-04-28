/*
    Compute the values of f(x) at x = 1.40 + (R+1)/100 from the following 
    table using Newton's backward interpolation formula.
    x       f(x)
    0.20    1.2922071606
    0.35    1.3397750591
    0.50    1.3890939964
    0.65    1.4402284308
    0.80    1.4932451930
    0.95    1.5482135742
    1.10    1.6052054161
    1.25    1.6642952050
    1.40    1.7255601691
    1.55    1.7890803797
    where R is the last digit of your university roll number.

    Output:
    Interpolation using Newton's Backward Interpolation fourmula
    Enter the number of points: 10

    The x points must be equispaced
    Enter the points:
    1 x: 0.20
      y: 1.2922071606
    2 x: 0.35
      y: 1.3397750591
    3 x: 0.50
      y: 1.3890939964
    4 x: 0.65
      y: 1.4402284308
    5 x: 0.80
      y: 1.4932451930
    6 x: 0.95
      y: 1.5482135742
    7 x: 1.10
      y: 1.6052054161
    8 x: 1.25
      y: 1.6642952050
    9 x: 1.40
      y: 1.7255601691
    10 x: 1.55
      y: 1.7890803797

    Enter the value for which interpolation is required: 1.45

    The difference table is:
    1.2922071606	0.0475678985	0.0017510388	0.0000644583	0.0000023724	0.0000000881	0.0000000019	0.0000000022	-0.0000000031	0.0000000047	
    1.3397750591	0.0493189373	0.0018154971	0.0000668307	0.0000024605	0.0000000900	0.0000000041	-0.0000000009	0.0000000016	
    1.3890939964	0.0511344344	0.0018823278	0.0000692912	0.0000025505	0.0000000941	0.0000000032	0.0000000007	
    1.4402284308	0.0530167622	0.0019516190	0.0000718417	0.0000026446	0.0000000973	0.0000000039	
    1.4932451930	0.0549683812	0.0020234607	0.0000744863	0.0000027419	0.0000001012	
    1.5482135742	0.0569918419	0.0020979470	0.0000772282	0.0000028431	
    1.6052054161	0.0590897889	0.0021751752	0.0000800713	
    1.6642952050	0.0612649641	0.0022552465	
    1.7255601691	0.0635202106	
    1.7890803797	

    Enter the column number in which noise level appears
    (Press 0 if no noise is present)
    8
    The functional value at x = 1.450000 is 1.7464789517
*/

#include <stdio.h>
#include <stdlib.h>

#define N 10

int main()
{
    double x[N] = {0}, y[N][N] = {0};
    double x_inter = 0, y_inter = 0, u = 0, h = 0, prod = 1; 
    int n = 10, noise = 10, row;

    printf("Interpolation using Newton's Backward Interpolation fourmula\n");
    printf("Enter the number of points: ");
    scanf("%d", &n);
    if (n > N)
    {
        printf("Too many points\n");
        exit(EXIT_FAILURE);
    }
    printf("\n");
    
    printf("The x points must be equispaced\n");
    printf("Enter the points:\n");
    for(int i = 0; i < n; i++)
    {
        printf("%d x: ", i+1);
        scanf("%lf", &x[i]);
        printf("  y: ");
        scanf("%lf", &y[i][0]);        
    }

    printf("\nEnter the value for which interpolation is required: ");
    scanf("%lf", &x_inter);
    printf("\n");

    // difference table
    for (int j = 1; j < n; j++)
    {
        for (int i = 0; i < n-j; i++)
            y[i][j] = y[i+1][j-1] - y[i][j-1];
    }

    printf("The difference table is:\n");
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n-i; j++)
            printf("%.10f\t", y[i][j]);
        printf("\n");
    }

    printf("\nEnter the column number in which noise level appears\n");
    printf("(Press 0 if no noise is present)\n");
    scanf("%d", &noise);

    if (noise < 0 || noise > n)
    {
        printf("Invalid input!\n");
        exit(EXIT_FAILURE);
    }

    if (noise == 0)
        noise = n+1;

    h = x[1] - x[0];
    u = (x_inter - x[n-1]) / h;
    y_inter = y[n-1][0];

    row = n-2;
    for (int j = 1; j < noise-1; j++)
    {
        prod *= (u + (j-1)) / j;
        y_inter += prod * y[row][j];
        row--;
    }

    printf("The functional value at x = %f is %.10f\n", x_inter, y_inter);

    return 0;
}