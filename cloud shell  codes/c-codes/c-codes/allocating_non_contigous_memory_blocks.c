#include<stdio.h>
#include<stdlib.h>

int free_region(int ***ppp, int rows);
int main(void)
{
	int row =2;
	int column = 5;
	int i,j ;
	int **pp = (int**)malloc(row*sizeof(int*));
	for(i = 0; i< row ;i++)
	{
		pp[i] = (int* )malloc(column * sizeof(int));
	}

	printf(" pp[0] = %p, pp[1] = %p \n", *pp,*(pp + 1));
	for(i = 0; i<row ;i++)
	{
		for(j = 0; j < column; j++)
		{
		printf("*pp[%d][%d] = %p \n", i,j, *(pp + i) +  j);
		}
	}
	free(*pp);
	free(*(pp + 1));
	//free(pp);
	//int ***ppp = &pp;
	//printf("**ppp + 0 = %p, **ppp + 1 = %p\n", **(ppp),**ppp[1]);
	free_region(&pp,2);
	
	//printf("**ppp + 0 = %p, **ppp + 1 = %p\n", *(ppp + 0),*(ppp)+ 1);
	//printf("&pp = %p",&pp);
}
//Not working
int free_region(int ***ppp,int row)
{
	int i;
	for(i = 0; i< row ;i++)
	{
	//	free(**(ppp) + i);
		//**(ppp) + i = NULL;
	}

	free(*ppp);
	*ppp = NULL;
	return 0;

}
