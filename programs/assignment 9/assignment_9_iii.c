/*
    Solve the following initial value problem by 4th order Runge Kutta method and tabulate
    the values of y for x = 0 (0.1) 1 correct to 5D.
    dy/dx = (1 + log_e(x^3 + y^3)) / (1.5 + 2.5x^2 + 3.5y^2) with y(0.0) = 1 + R/10,
    R is the last digit of your university roll number.

    Output:
    Solving differential equation by 4th order Runge Kutta method
    Enter values for x:
    Initial value: 0
    Final value: 1
    Step length: 0.1

    Enter value of y(0.0): 1.4

    Solution of the differential equation correct to 5D: 
    x       y
    0.0     1.40000
    0.1     1.43134
    0.2     1.46240
    0.3     1.49298
    0.4     1.52294
    0.5     1.55218
    0.6     1.58065
    0.7     1.60831
    0.8     1.63515
    0.9     1.66117
    1.0     1.68639
*/
#include <stdio.h>
#include <math.h>
#define R 4

double f(double x, double y)
{
    double num = 1 + log(pow(x,3) + pow(y,3));
    double denom = 1.5 + 2.5*pow(x,2) + 2.5*pow(y,2);
    return num / denom;
}

int main()
{
    double x0 = 0.0, y0 = 1 + R/10.0;
    double xn = 1, h = 0.1;

    printf("Solving differential equation by 4th order Runge Kutta method\n");
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
    printf("x\ty\n");
    
    double x_i = x0, y_i = y0;
    int n = round((xn - x0) / h);

    printf("%0.1f \t%0.5f\n", x0, y0);
    for (int i = 1; i <= n; ++i)
    {
        x_i = x0 + (i-1)*h;
        double k1 = h * f(x_i, y_i);
        double k2 = h * f(x_i + h/2, y_i + k1/2);
        double k3 = h * f(x_i + h/2, y_i + k2/2);
        double k4 = h * f(x_i + h, y_i + k3);
        y_i = y_i + 1/6.0 * (k1 + 2*k2 + 2*k3 + k4);
        printf("%0.1f \t%0.5f\n", x_i+h, y_i);
    }

    return 0;
}