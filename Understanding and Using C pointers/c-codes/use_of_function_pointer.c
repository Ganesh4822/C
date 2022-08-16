#include<stdio.h>
#include<stdlib.h>
int square(int n);
int main(void)
{
	int (*fptr)(int);
	fptr = square;
	printf("sqaure is %d\n",fptr(5));
}

int square(int n)
{
	return n*n;
}
