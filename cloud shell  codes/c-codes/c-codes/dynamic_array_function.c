#include<stdio.h>
#include<stdlib.h>

int* fun_arr(int size, int value);
int release_memory(int **p, int size);
int main(void)
{
	int *ptr;
	int i;
	ptr = fun_arr(5,100);
	for(i = 0; i < 5 ;i++ )
		printf(" at location = %p, value  = %d\n",ptr + i,*(ptr + i));

	printf("%d", release_memory(&ptr,5));
	return 0;
}


int* fun_arr(int size,  int value)
{
	int* p = (int*)malloc(size*sizeof(int));
	int i =0 ;
	for(i = 0 ; i < size;i++)
		*(p+i) = value;
       	return p;	
}

int release_memory(int **p1,int size)
{
	int i =0;
	int* ptr = *p1;
	free(ptr);
	ptr = 0;
	*p1 = NULL;
	return 1;

}
