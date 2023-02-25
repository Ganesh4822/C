#include<stdio.h>
#include<stdlib.h>

int main()
{
	int arr[2][5] = {{1,2,3,4,5},{6,7,8,9,10}};
	int i,j;
	for(i = 0; i < 2 ;i++)
	{
		for(j = 0; j< 5 ;j++)
		{
			printf("&arr[%d][%d] = %p, arr[%d][%d] = %d\n",i,j,&arr[i][j],i,j,arr[i][j]);
		}
	}

	printf("Sizeof(matrix[0])= %d\n",sizeof(arr[0]));
}
