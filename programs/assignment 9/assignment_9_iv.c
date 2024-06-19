/*
    Use Picard's method and find three approximation values of y 
    for x = 0.1 (0.1) 1.0
    dy/dx = 1 + xy, y(0.0) = 1

    Output:
    Solving differential equation by Picard's method
    Enter values for x:
    Initial value: 0.1
    Final value: 1.0
    Step length: 0.1

    Enter initial value of y: 1

    Solution of the differential equation: 
    x = 0.100000
    First approximation value of  y(0.1) = 1.105000
    Second approximation value of y(0.1) = 1.105346
    Third approximation value of  y(0.1) = 1.105347

    x = 0.200000
    First approximation value of  y(0.2) = 1.220000
    Second approximation value of y(0.2) = 1.222867
    Third approximation value of  y(0.2) = 1.222889

    x = 0.300000
    First approximation value of  y(0.3) = 1.345000
    Second approximation value of y(0.3) = 1.355013
    Third approximation value of  y(0.3) = 1.355190

    x = 0.400000
    First approximation value of  y(0.4) = 1.480000
    Second approximation value of y(0.4) = 1.504533
    Third approximation value of  y(0.4) = 1.505301

    x = 0.500000
    First approximation value of  y(0.5) = 1.625000
    Second approximation value of y(0.5) = 1.674479
    Third approximation value of  y(0.5) = 1.676888

    x = 0.600000
    First approximation value of  y(0.6) = 1.780000
    Second approximation value of y(0.6) = 1.868200
    Third approximation value of  y(0.6) = 1.874356

    x = 0.700000
    First approximation value of  y(0.7) = 1.945000
    Second approximation value of y(0.7) = 2.089346
    Third approximation value of  y(0.7) = 2.103002

    x = 0.800000
    First approximation value of  y(0.8) = 2.120000
    Second approximation value of y(0.8) = 2.341867
    Third approximation value of  y(0.8) = 2.369173

    x = 0.900000
    First approximation value of  y(0.9) = 2.305000
    Second approximation value of y(0.9) = 2.630013
    Third approximation value of  y(0.9) = 2.680450

    x = 1.000000
    First approximation value of  y(1.0) = 2.500000
    Second approximation value of y(1.0) = 2.958333
    Third approximation value of  y(1.0) = 3.045833
*/
#include <stdio.h>
#include <math.h>
#define R 4

double f1(double x) {
    return x + pow(x,2)/2;
}

double f2(double x) {
    return x + pow(x,2)/2 + pow(x,3)/3 + pow(x,4)/8;
}

double f3(double x) {
    return x + pow(x,2)/2 + pow(x,3)/3 + pow(x,4)/8 
            + pow(x,5)/15 + pow(x,6)/48;
}

int main()
{
    double x0 = 0.1, y_initial = 1.0;
    double xn = 1.0, h = 0.1;

    printf("Solving differential equation by Picard's method\n");
    printf("Enter values for x:\n");
    printf("Initial value: ");
    scanf("%lf", &x0);
    printf("Final value: ");
    scanf("%lf", &xn);
    printf("Step length: ");
    scanf("%lf", &h);

    printf("\nEnter initial value of y: ");
    scanf("%lf", &y_initial);
    printf("\n");

    printf("Solution of the differential equation: \n");
    // typecasting to int doesn't work for xn = 1.1, x0 = 1.0, h = 0.1; n = (int)1.99999
    int n = round((xn - x0) / h);
    for (int i = 0; i <= n; ++i)
    {
        double x_i = x0 + i*h;
        printf("x = %f\n", x_i);
        printf("First approximation value of  y(%.1f) = %f\n", x_i, y_initial + f1(x_i));
        printf("Second approximation value of y(%.1f) = %f\n", x_i, y_initial + f2(x_i));
        printf("Third approximation value of  y(%.1f) = %f\n", x_i, y_initial + f3(x_i));
        printf("\n");
    }
    return 0;
}