/*
    Compute the value of the following integral correct to 5D by Weddle's rule using 13 ordinates.
    int_10 deg ^40_deg (q + x*cos(q*x)^2)/(sqrt(x + sin(q*x))) dx
    where q = (6+R)/60 and R is the last digit of your university roll number.

    Output:
    Integration by Weddle's Rule
    Enter the number of ordinates (including end-points): 13 
    The integration correct upto 5D is 0.44192
*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define PI 3.141592653589793
#define MAX_LEN 200
#define R 4

double f(double x)
{   
    double q = (6 + R)/60.0;
    return (q + x * pow(cos(q*x), 2)) / (sqrt(x + sin(q*x)));
}

double to_radians(double angle)
{
    return angle * PI / 180.0;
}

int main()
{
    int num_ordinates = 13;
    double x[MAX_LEN] = {0}, y[MAX_LEN] = {0}, sum = 0, h = 0;

    printf("Integration by Weddle's Rule\n");
    printf("Enter the number of ordinates (including end-points): ");
    scanf("%d", &num_ordinates);
    if (num_ordinates > MAX_LEN)
    {
        printf("Too many points.\n");
        exit(EXIT_FAILURE);
    }

    h = (to_radians(40) - to_radians(10)) / (num_ordinates - 1);
    x[0] = to_radians(10);
    y[0] = f(x[0]);
    for (int i = 1; i < num_ordinates; i++)
    {
        x[i] = x[0] + i*h;
        y[i] = f(x[i]);
    }

    for (int i = 0; i < num_ordinates-2; i += 6)
        sum += y[i] + 5*y[i+1] + y[i+2] + 6*y[i+3] + y[i+4] + 5*y[i+5] + y[i+6];

    sum *= 3*h/10;

    printf("The integration correct upto 5D is %.5f\n", sum);

    return 0;
}