/*
    x^5 + 0.7*x^4 - 7.77*x^3 + 22.041*x^2 - 17.6824*x - 276.46048 = 0
    
    (c) Find a pair of complex roots of the above equation, one of
    them has the initial value 1.4299 + 3.1520 i

    Output:
    Root finding by Newton-Raphson Method
    Enter initial approximation of the root
    Enter the real part: 1.4299
    Enter the imaginary part: 2.1520

    z            f(z)
    1.429900 + i*2.152000    -225.021076 + i*-62.451576
    0.728407 + i*2.939392    -52.493383 + i*243.583173
    1.111315 + i*2.682717    -61.025890 + i*27.969082
    1.213853 + i*2.807117    4.713991 + i*-6.243556
    1.200148 + i*2.799944    -0.014576 + i*-0.077478
    1.200000 + i*2.800000    -0.000008 + i*0.000002
    1.200000 + i*2.800000    -0.000000 + i*-0.000000

    The roots of the equation upto 5D are (1.20000 + i*2.80000) and (1.20000 - i*2.80000)

*/

#include <stdio.h>
#include <math.h>
#include <complex.h>

double complex f(double complex z)
{
    return cpow(z,5) + 0.7*cpow(z,4) - 7.77*cpow(z,3) + 22.041*cpow(z,2) 
            - 17.6824*z - 276.46048;
}

double complex df(double complex z)
{
    return 5*cpow(z,4) + 4*0.7*cpow(z,3) - 3*7.77*cpow(z,2) + 2*22.041*z 
            - 17.6824;
}

int main()
{
    double x = 0, y = 0;
    double complex z;
    double error = 0.0000001;

    printf("Root finding by Newton-Raphson Method\n");
    printf("Enter initial approximation of the root\n");
    printf("Enter the real part: ");
    scanf("%lf", &x);
    printf("Enter the imaginary part: ");
    scanf("%lf", &y);

    z = x + I*y;

    printf("\nz \t\t\t f(z)\n");
    printf("%f + i*%f \t %f + i*%f\n", creal(z), cimag(z), creal(f(z)), cimag(f(z)));

    while (cabs(f(z)) >= error) 
    {
        z = z - f(z)/df(z);
        printf("%f + i*%f \t %f + i*%f\n", creal(z), cimag(z), creal(f(z)), cimag(f(z)));
    }

    printf("\n");
    printf("The roots of the equation upto 5D are (%.5f + i*%.5f) and (%.5f - i*%.5f)\n", 
        creal(z), cimag(z), creal(z), cimag(z));

    return 0;
}