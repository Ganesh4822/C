#include<stdio.h>
#include<stdlib.h>

typedef int (*fptr)(int, int);
int add(int , int);
int sub(int , int);

int main(void)
{
	fptr ptr;
	ptr = add;
	printf("addition is %d\n",ptr(10,5));
	ptr = sub;
	printf("substraction is %d", ptr(10,5));
	return 0;
}

int add(int a, int b)
{
	return (a+b);
}

int sub(int a, int b)
{
	return (a-b);
}
