/*
    x^5 + 0.7*x^4 - 7.77*x^3 + 22.041*x^2 - 17.6824*x - 276.46048 = 0
    
    (c) Find a pair of complex roots of the above equation, one of
    them has the initial value 1.4299 + 3.1520 i

    Output:

    ABANDONED
    
    
*/

#include <stdio.h>
#include <math.h>

double u(double x, double y)
{
    // return 0.7*pow(x,4) + pow(x,5) + (0.7 + 5*x)*pow(y,4) - 7.77*pow(x,3) 
    //     + 22.041*pow(x,2) - (6*0.7*pow(x,2) + 10*pow(x,3) - 3*7.77*x + 22.041)*pow(y,2) 
    //     - 17.6824*x - 276.46048;

    return pow(x,5) - 10*pow(x,3)*pow(y,2) + 5*x*pow(y,4) 
        + 0.7*(pow(x,4) - 6*pow(x,2)*pow(y,2) + pow(y,4))
        - 7.77*(pow(x,3) - 3*x*pow(y,2))
        + 22.041*(pow(x,2) - pow(y,2)) - 17.6824*x - 276.46048; 
}

double v(double x, double y)
{
    // return pow(y,5) + (-4*0.7*x - 10*pow(x,2) + 7.77)*pow(y,3) 
    //     + (4*0.7*pow(x,3) + 5*pow(x,4) - 3*7.77*pow(x,2) + 2*22.041*x - 17.6824)*y ;

    return 5*pow(x,4)*y - 10*pow(x,2)*pow(y,3) + pow(y,5)
        + 0.7*(4*pow(x,3)*y - 4*x*pow(y,3)) 
        - 7.77*(3*x*y - pow(y,3)) + 22.041*2*x*y - 17.6824*y;
}

double ux(double x, double y)
{
    // return 4*0.7*pow(x,3) + 5*pow(x,4) + 5*pow(y,4) - 3*7.77*pow(x,2) 
    //     + 2*22.041*x - (2*6*0.7*x + 3*10*pow(x,2) - 3*7.77)*pow(y,2) 
    //     - 17.6824;

    return 5*pow(x,4) - 30*pow(x,2)*pow(y,2) + 5*pow(y,4)
        + 0.7*(4*pow(x,3) - 12*x*pow(y,2)) - 7.77*3*(pow(x,2) - pow(y,2))
        + 22.041*2*x - 17.6824;
}

double vx(double x, double y)
{
//     return (-4*0.7 - 2*10*x)*pow(y,3) 
//         + (3*4*0.7*pow(x,2) + 4*5*pow(x,3) - 2*3*7.77*x + 2*22.041)*y ;

    return 20*pow(x,3)*y - 20*x*pow(y,3) + 0.7*(12*pow(x,2)*y - 4*pow(y,3))
        - 7.77*3*y + 22.04*2*y;
}

int main()
{
    double x = 0, y = 0;
    double error = 0.0000001, f_error = 0;

    printf("Enter initial approximation of the root\n");
    printf("Enter the real part: ");
    scanf("%lf", &x);
    printf("Enter the imaginary part: ");
    scanf("%lf", &y);

    printf("\nz \t\t f(z)\n");
    printf("%f + i*%f \t %f + i*%f\n", x,y, u(x,y),v(x,y));
    do 
    {
        // x = x - (u(x,y)*ux(x,y) - v(x,y)*vx(x,y)) 
        //     / (pow(ux(x,y),2) + pow(vx(x,y),2));
        // y = y + (u(x,y)*vx(x,y) - v(x,y)*ux(x,y)) 
        //     / (pow(ux(x,y),2) + pow(vx(x,y),2));

        x = x - (u(x,y)*)

        printf("%f + i*%f \t %f + i*%f\n", x,y, u(x,y),v(x,y));

    } while (fabs(x) >= error || fabs(y) >= error);

    printf("\n");
    printf("The roots of the equation upto 5D are (%.5f + i*%.5f) and (%.5f - i*%.5f)\n", 
        x,y, x,y);

    return 0;
}