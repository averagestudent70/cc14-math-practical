/*
    Evaluate the following integral by Simpson's rule correct upto 5D using 13 ordinates.
    int_15 deg ^60 deg [1.5 + (R+1)/20 * sin(x)^3]^3/2 dx
    where R is the last digit of your university roll number.

    Output:
    Integration by Simpson's Rule
    Enter the number of ordinates (including end-points): 13
    The integration correct upto 5D is 1.53960
*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define PI 3.141592653589793
#define MAX_LEN 200
#define R 4

double f(double x)
{   
    return pow(1.5 + (R+1)/20.0 * pow(sin(x), 3), 3/2.0);
}

double to_radians(double angle)
{
    return angle * PI / 180.0;
}

int main()
{
    int num_ordinates = 13;
    double x[MAX_LEN] = {0}, y[MAX_LEN] = {0}, sum = 0, h = 0;

    printf("Integration by Simpson's Rule\n");
    printf("Enter the number of ordinates (including end-points): ");
    scanf("%d", &num_ordinates);
    if (num_ordinates > MAX_LEN)
    {
        printf("Too many points.\n");
        exit(EXIT_FAILURE);
    }

    h = (to_radians(60) - to_radians(15)) / (num_ordinates - 1);
    x[0] = to_radians(15);
    y[0] = f(x[0]);
    for (int i = 1; i < num_ordinates; i++)
    {
        x[i] = x[0] + i*h;
        y[i] = f(x[i]);
    }

    for (int i = 0; i < num_ordinates-2; i += 2)
        sum += y[i] + 4*y[i+1] + y[i+2];

    sum *= h/3;

    printf("The integration correct upto 5D is %.5f\n", sum);

    return 0;
}