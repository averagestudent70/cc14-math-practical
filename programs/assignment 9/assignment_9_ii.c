/*
    Solve the following initial value problem by Modified Euler's method to find the values of y
    for x = 0.1 (0.1) 0.5 correct to 5D.
    dy/dx = (1+ xy + x^2y^2 + x^3y^3)^(3/2) / (1 + xy + x^2y^2)^(1/2) with y(0.0) = 1.1 + R/10,
    R is the last digit of your university roll number.

    Output:
    Solving differential equation by Modified Euler's method
    Enter values for x:
    Initial value: 0.0
    Final value: 0.5
    Step length: 0.1

    Enter value of y(0.0): 1.5

    Solution of the differential equation correct to 5D: 
    y(0.0) = 1.50000
    y(0.1) = 1.60966
    y(0.2) = 1.74609
    y(0.3) = 1.93371
    y(0.4) = 2.23640
    y(0.5) = 2.93189
*/
#include <stdio.h>
#include <math.h>
#define R 4

double f(double x, double y)
{
    double num = pow(1 + x*y + pow(x*y,2) + pow(x*y,3), 3/2.0);
    double denom = pow(1 + x*y + pow(x*y,2), 1/2.0);
    return num / denom;
}

int main()
{
    double x0 = 0.0, y0 = 1.1 + R/10.0;
    double xn = 0.5, h = 0.1, error = 1E-7;

    printf("Solving differential equation by Modified Euler's method\n");
    printf("Enter values for x:\n");
    printf("Initial value: ");
    scanf("%lf", &x0);
    printf("Final value: ");
    scanf("%lf", &xn);
    printf("Step length: ");
    scanf("%lf", &h);

    printf("\nEnter value of y(%.1f): ", x0);
    scanf("%lf", &y0);
    printf("\n");

    printf("Solution of the differential equation correct to 5D: \n");
    double x_i = x0, y_i = y0;
    int n = round((xn - x0) / h);

    printf("y(%0.1f) = %0.5f\n", x0, y0);
    for (int i = 1; i <= n; ++i)
    {
        x_i = x0 + (i-1)*h;
        double y_prev, y = y_i + h*f(x_i, y_i);
        do 
        {
            y_prev = y;
            y = y_i + h/2 * (f(x_i, y_i) + f(x_i+h, y));
        } while (fabs(y - y_prev) >= error);

        y_i = y;
        printf("y(%0.1f) = %0.5f\n", x_i+h, y_i);
    }

    return 0;
}