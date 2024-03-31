/*
	Find a positive root of the following equation correct upto 5D by 
	Regula Falsi method
		d*x^2 + x*log_e (1+x) - 2 = 0
	where d = 1 + R/10 and R is the last didit of your university roll number.

	Output:
	Input the root containing interval
	The lower bound: 0
	The upper bound: 1

	a 		 b 		 x 		 f(x)
	0.000000     1.000000 	 0.955499 	 -0.081029
	0.955499 	 1.000000 	 0.976201 	 -0.000877
	0.976201 	 1.000000 	 0.976424 	 -0.000009
	0.976424 	 1.000000 	 0.976426 	 -0.000000

	The root in the interval (0.000000,1.000000) correct to 5D is 0.97643
*/

#include <stdio.h>
#include <math.h>

#define R 4

double f(double x)
{
	double d = 1 + R/10.0;
	return d*pow(x,2) + x*log(1+x) - 2;
}

int main()
{
    double a0 = 0, b0 = 1, a, b, x, error = 0.0000001;

  	printf("Input the root containing interval\n");
    printf("The lower bound: ");
    scanf("%lf", &a0);
    printf("The upper bound: ");
    scanf("%lf", &b0);
    printf("\n");

    a = a0;
    b = b0;
    printf("a \t\t b \t\t x \t\t f(x)\n");
    do 
    {
        x = b - f(b) * (b-a) / (f(b) - f(a));
        printf("%f \t %f \t %f \t %f\n", a, b, x, f(x));

        if (f(a) * f(x) > 0)
            a = x;
        else
            b = x;
    } while (fabs(f(x)) >= error);

    printf("\nThe root in the interval (%f,%f) correct to 5D is %.5f\n", a0, b0, x);

    return 0;
}