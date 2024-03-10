/* 
	Write a C program to enter 10 integers into an array 
	and sort them in ascending order.

	Output:
	Input 10 integers: 12 -13 56 0 1 -34 0 8 9 11
	The integers in ascending order are:
	-34  -13  0  0  1  8  9  11  12  56 
*/

#include <stdio.h>

int main()
{
	int a[10], N = 10;
	int i, j, temp;

	printf("Input %d integers: ", N);
	for (i = 0; i < N ; i++)
		scanf("%d", &a[i]);

	for (i = 0; i < N-1; i++)
	{
		for (j = i+1; j < N; j++)
		{
			if (a[i] > a[j])
			{
				temp = a[i];
				a[i] = a[j];
				a[j] = temp;
			}
		}
	}

	printf("The integers in ascending order are:\n");
	for (i = 0; i < N; i++)
		printf("%d  ", a[i]);
	printf("\n");

	return 0;
}