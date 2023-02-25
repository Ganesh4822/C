#include<stdio.h>
#include<stdlib.h>

#define SUCCESS 1
int safe_free(void **pp);
int main(void)
{
	int *ptr;
	ptr = (int*)malloc(sizeof(int));
	*ptr = 1000;
	printf("*ptr = %d, ptr = %p\n",*ptr,ptr);
	safe_free((void*)&ptr);
	printf(" ptr = %p\n",ptr);
	safe_free((void*)&ptr);
	printf(" ptr = %p\n",ptr);
	return 0;
}

int safe_free(void **pp)
{
	if(*pp != NULL && pp != NULL)
	{
		free(*pp);
		*pp = NULL;
	}
	return (SUCCESS);
}


