/*
	Write a C-program to calculate the sum correct up to 
	4 decimal places of 1/1 + 1/2 + 1/3 + ... + 1/(10+R)
	where R is the last digit of your university roll number.

	Output:
	Input the value of R: 4
	The sum of the series correct upto 4D is 3.2516
*/

#include <stdio.h>

int main()
{
	int i, R = 0, N;
	double sum = 0.0;

	printf("Input the value of R: ");
	scanf("%d", &R);

	N = 10 + R;

	for (i = 0; i < N; i++)
		sum = sum + 1.0/(i+1);
	printf("The sum of the series correct upto 4D is %.4f\n", sum);

	return 0;
}