#include<stdio.h>
#include<stdlib.h>


int main(void)
{
	int* arr[5];
	int arrr[5];
	int i;
	//method 1
	//for(i = 0; i<5 ;i++)
	//{
	//	arr[i] = (int*)malloc(sizeof(int));
	//	*arr[i] = i;
	//}
	//method 2
	for(i = 0; i<5; i++)
	{
		*(arr + i) = (int*)malloc(sizeof(int));
		**(arr+ i ) = i;
	}

	for( i =0; i<5 ; i++)
	{
		printf("arr[%d] = %d\n",i,*arr[i]);
	}
	printf("arr[3][0] = %d\n",arr[3][0]);
	//printf("arr[3][1] = %d\n", arr[3][1]);  illegal
	for( i = 0;i<5 ;i++)
	{
		free(arr[i]);
		arr[i] = NULL;
	}
	for(i = 0; i<5 ;i++)
	{
		arrr[i] = i;
	}
	//invalid as array pointer or multidimentional  array or vector is not used.
	printf("arrr[3][0] = %d\n",arrr[3][0]);
}
