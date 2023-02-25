#include<stdio.h>
#include<stdlib.h>
int safe_free(void ***ppp,int rows);
int main(void)
{
	int rows =2;
	int columns = 5;
	int i;
	int **matrix = (int**)malloc(rows*sizeof(int*));
	*matrix = (int*)malloc(rows*columns * sizeof(int));
	for(i = 1;i<rows;i++)
	{
		*(matrix+i) = *matrix + (i * columns);
	}
	for(i = 0; i< rows ; i++)
	{
		printf("matrix + %d = %llu\n", i,*( matrix + i));
	}
	printf("*matrix = %p\n", *matrix);
	safe_free((void*)&matrix, 2 );
	
	// for(i = 0; i< rows ; i++)
	// {
	// 	printf("matrix + %d = %llu\n", i,*( matrix + i));
	// }
	return 0;

}

int safe_free(void*** ppp, int rows)
{	
    if(ppp != NULL && *ppp != NULL && **ppp != NULL)
    {
    free(**ppp);
   // printf("Int ** =  %llu",**(ppp));
   /*for(int i =0 ; i < rows ;i++)
    {
      **((int*)ppp + i)  = NULL;
    }*/
    free(*ppp);
    *ppp = NULL;
    printf("Pointer freed successfully\n");
    }
    return (0);
}
