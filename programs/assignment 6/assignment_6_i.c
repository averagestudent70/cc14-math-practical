/*
    Evaluate the following integral by Trapezoidal rule correct upto 5D using 13 ordinates.
    int_0^45deg [12.3*sin(c*x) + 3.2*cos(cx)]^1/2 dx
    where C = (2+R)/10, R is the last digit of your university roll number.

    Output:
    Integration by Trapezoidal Rule
    Enter the number of ordinates (including end-points): 13
    The integration correct upto 5D is 1.89533
*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define PI 3.141592653589793
#define MAX_LEN 2000
#define R 4

double f(double x)
{   
    double c = (2 + R)/10.0;
    return sqrt(12.3 * sin(c*x) + 3.2 * cos(c*x));
}

double to_radians(double angle)
{
    return angle * PI / 180.0;
}

int main()
{
    int num_ordinates = 13;
    double x[MAX_LEN] = {0}, y[MAX_LEN] = {0}, sum = 0, h = 0;

    printf("Integration by Trapezoidal Rule\n");
    printf("Enter the number of ordinates (including end-points): ");
    scanf("%d", &num_ordinates);
    if (num_ordinates > MAX_LEN)
    {
        printf("Too many points.\n");
        exit(EXIT_FAILURE);
    }

    h = (to_radians(45) - to_radians(0)) / (num_ordinates - 1);
    x[0] = 0;
    y[0] = f(x[0]);
    for (int i = 1; i < num_ordinates; i++)
    {
        x[i] = x[0] + i*h;
        y[i] = f(x[i]);
    }

    for (int i = 0; i < num_ordinates-1; i++)
        sum += y[i] + y[i+1];

    sum *= h/2;

    printf("The integration correct upto 5D is %.5f\n", sum);

    return 0;
}