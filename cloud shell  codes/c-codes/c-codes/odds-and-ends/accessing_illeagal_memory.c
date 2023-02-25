#include<stdio.h>

int main()
{
	int num = 8;
	int *p = (int*)num;
	printf("%llu", *p);
}
