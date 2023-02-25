#include<stdio.h>

int main(void)
{
	int n;
	n = 0;
	int *p = (int*)n;
	printf("before : %p\n",p);
	*p = 10;
	printf("value  : %d at %llu\n",*p,p);
	//p = (int*)tmp;
	//printf("after : %llu\n", p);

}
