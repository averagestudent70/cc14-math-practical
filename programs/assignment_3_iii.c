/*
	Find a positive root of the following equation correct upto 6D by secant method
		x^2 * tanh x - e^{(1+R/20) sin x} - 3 = 0
	where R is the last digit of your university roll number.

	Output:
	Input two initial approximations of the root: 1 5

	x 		 f(x)
	1.696634 	 -3.005450
	2.099890 	 -1.091674
	2.329919 	 0.261049
	2.285527 	 -0.011541
	2.287407 	 -0.000102
	2.287424 	 0.000000

	The root correct to 6D is 2.287424
*/

#include <stdio.h>
#include <math.h>

#define R 4

double f(double x)
{
	return pow(x,2) * tanh(x) - exp((1+R/20)*sin(x)) - 3;
}

int main()
{
    double x0 = 0, x1 = 1, x, error = 0.0000001;

    printf("Input two initial approximations of the root: ");
    scanf("%lf%lf", &x0, &x1);
    printf("\n");

    printf("x \t\t f(x)\n");
    do 
    {
        x = x1 - f(x1)*(x1-x0) / (f(x1)-f(x0));
        printf("%f \t %f\n", x, f(x));

        x0 = x1;
        x1 = x;
    } while (fabs(f(x)) >= error);

    printf("\nThe root correct to 6D is %.6f\n", x);

    return 0;
}