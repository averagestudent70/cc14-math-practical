/*
    Solve the following initial value problem by Euler's method to find the values of y
    for x = 0.1 (0.1) 0.5 correct to 3D.
    dy/dx = (1+ x^3y^3 + x^2y^2)^(2/3) / (1 + x^2 + y^2)^(1/3) with y(0.0) = 1.1 + R/100,
    R is the last digit of your university roll number.

    Output:
    Solving differential equation by Euler's method
    Enter values for x:
    Initial value: 0.0
    Final value: 0.5
    Step length: 0.1

    Enter value of y(0.0): 1.14

    Solution of the differential equation correct to 3D: 
    y(0.0) = 1.140
    y(0.1) = 1.216
    y(0.2) = 1.290
    y(0.3) = 1.366
    y(0.4) = 1.446
    y(0.5) = 1.536
*/
#include <stdio.h>
#include <math.h>
#define R 4

double f(double x, double y)
{
    double num = pow(1 + pow(x*y,3) + pow(x*y,2), 2/3.0);
    double denom = pow(1 + x*x + y*y, 1/3.0);
    return num / denom;
}

int main()
{
    double x0 = 0.0, y0 = 1.1 + R/100.0;
    double xn = 0.5, h = 0.1;

    printf("Solving differential equation by Euler's method\n");
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

    printf("Solution of the differential equation correct to 3D: \n");
    double x_i = x0, y_i = y0;
    // typecasting to int doesn't work for xn = 1.1, x0 = 1.0, h = 0.1; n = (int)1.99999
    int n = round((xn - x0) / h);

    printf("y(%0.1f) = %0.3f\n", x0, y0);
    for (int i = 1; i <= n; ++i)
    {
        x_i = x0 + (i-1)*h;
        y_i = y_i + h*f(x_i, y_i);
        printf("y(%0.1f) = %0.3f\n", x_i+h, y_i);
    }

    return 0;

}