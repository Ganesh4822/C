#include<stdio.h>

int main(void)
{
	int *p;
	int ti =100;
	*p = ti;
	void *v;
	v  = p;
	printf("%d\n", ti);
	printf("%d\n", *p);
	printf("%d\n", int*(v));

}
