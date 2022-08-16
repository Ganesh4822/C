#include<stdio.h>

int main(void)
{
	int arr[5] = {1,2,4,5,6};
	int *p ,*p1;
	p = arr;
	p1 = &arr[];

	printf(" address = %p\n ", p);
	printf("address = %p\n", p1);
}
