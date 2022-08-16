#include<stdio.h>
#include<stdlib.h>

int main(void)
{
	int *p = (int*)malloc(sizeof(int));
	*p = 5;
	printf("p = %p, *p = %d\n",p,*p);
	free(p);
	p = NULL;
	*p = 10;
	printf("p = %p, *p = %d\n",p,*p);
}
