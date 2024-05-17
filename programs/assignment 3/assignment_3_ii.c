/*
    x^5 + 0.7*x^4 - 7.77*x^3 + 22.041*x^2 - 17.6824*x - 276.46048 = 0
    
    (a) Find a root of the above equation which lies in [2.5, 3.5].
    (b) Find a double root of the above equation which lies in [-3.5, -2.5].
    (c) Find a pair of complex roots of the above equation, one of
    them has the initial value 1.4299 + 3.1520 i

    Output:
    Root finding by Newton-Raphson Method

    1. Single root
    2. Multiple roots with known multiplicity
    3. Complex roots
    Enter your choice: 1

    Enter initial approximation of the root: 2.7

    x 		 f(x)
    2.700000 	 -135.771040
    3.238257 	 66.620656
    3.111487 	 5.094133
    3.100086 	 0.037737
    3.100000 	 0.000002
    3.100000 	 0.000000

    The root of the equation correct upto 6D is 3.100000

    Output:
    Root finding by Newton-Raphson Method

    1. Single root
    2. Multiple roots with known multiplicity
    3. Complex roots
    Enter your choice: 2

    Enter initial approximation of the root: -3.4
    Enter multiplicity of the root: 2

    x 		 f(x)
    -3.400000 	 -16.965000
    -3.119800 	 -0.064618
    -3.100095 	 -0.000001
    -3.100000 	 0.000000

    The root of the equation upto 5D is -3.10000 with multiplicity 2

    Output:
    Root finding by Newton-Raphson Method

    1. Single root
    2. Multiple roots with known multiplicity
    3. Complex roots
    Enter your choice: 3

    Enter initial approximation of the root
    Enter the real part: 1.4299
    Enter the imaginary part: 2.1520

    z 			 f(z)
    1.429900 + i*2.152000 	 -225.021076 + i*-62.451576
    0.728407 + i*2.939392 	 -52.493383 + i*243.583173
    1.111315 + i*2.682717 	 -61.025890 + i*27.969082
    1.213853 + i*2.807117 	 4.713991 + i*-6.243556
    1.200148 + i*2.799944 	 -0.014576 + i*-0.077478
    1.200000 + i*2.800000 	 -0.000008 + i*0.000002
    1.200000 + i*2.800000 	 -0.000000 + i*-0.000000

    The roots of the equation upto 5D are (1.20000 + i*2.80000) and (1.20000 - i*2.80000)
*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <complex.h>

double f(double x)
{
    return pow(x,5) + 0.7*pow(x,4) - 7.77*pow(x,3) + 22.041*pow(x,2) 
            - 17.6824*x - 276.46048;
}

double df(double x)
{
    return 5*pow(x,4) + 4*0.7*pow(x,3) - 3*7.77*pow(x,2) + 2*22.041*x 
            - 17.6824;
}

double complex fz(double complex z)
{
    return cpow(z,5) + 0.7*cpow(z,4) - 7.77*cpow(z,3) + 22.041*cpow(z,2) 
            - 17.6824*z - 276.46048;
}

double complex dfz(double complex z)
{
    return 5*cpow(z,4) + 4*0.7*cpow(z,3) - 3*7.77*cpow(z,2) + 2*22.041*z 
            - 17.6824;
}

int main()
{
    double x = 0, y = 0, error = 0.0000001;
    int choice, m = 2;
    double complex z;

    printf("Root finding by Newton-Raphson Method\n\n");
    printf("1. Single root\n");
    printf("2. Multiple roots with known multiplicity\n");
    printf("3. Complex roots\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);
    printf("\n");

    switch (choice)
    {
    case 1:
        printf("Enter initial approximation of the root: ");
        scanf("%lf", &x);

        printf("\nx \t\t f(x)\n");
        printf("%f \t %f\n", x, f(x));

        while (fabs(f(x)) >= error) 
        {
            x = x - f(x)/df(x);
            printf("%f \t %f\n", x, f(x));
        }

        printf("\n");
        printf("The root of the equation correct upto 6D is %.6f\n", x);
        break;

    case 2:
        printf("Enter initial approximation of the root: ");
        scanf("%lf", &x);
        printf("Enter multiplicity of the root: ");
        scanf("%d", &m);

        printf("\nx \t\t f(x)\n");
        printf("%f \t %f\n", x, f(x));    

        while (fabs(f(x)) >= error) 
        {
            x = x - m * f(x)/df(x);
            printf("%f \t %f\n", x, f(x));
        }

        printf("\n");
        printf("The root of the equation upto 5D is %.5f with multiplicity %d\n", 
            x, m);
        break;

    case 3:
        printf("Enter initial approximation of the root\n");
        printf("Enter the real part: ");
        scanf("%lf", &x);
        printf("Enter the imaginary part: ");
        scanf("%lf", &y);

        z = x + I*y;

        printf("\nz \t\t\t f(z)\n");
        printf("%f + i*%f \t %f + i*%f\n", creal(z), cimag(z), creal(fz(z)), cimag(fz(z)));

        while (cabs(fz(z)) >= error) 
        {
            z = z - fz(z)/dfz(z);
            printf("%f + i*%f \t %f + i*%f\n", creal(z), cimag(z), creal(fz(z)), cimag(fz(z)));
        }

        printf("\n");
        printf("The roots of the equation upto 5D are (%.5f + i*%.5f) and (%.5f - i*%.5f)\n", 
            creal(z), cimag(z), creal(z), cimag(z));
        break;
    
    default:
        printf("Invalid input. Please enter a number between 1 and 3.\n");
        exit(EXIT_FAILURE);
        break;
    }

    return 0;
}