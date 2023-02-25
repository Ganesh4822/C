#include<stdio.h>
#include<stdlib.h>

void print_array(int (*arr)[5],int rows);
//1st parameter = pointer to an array of integeer of size 5
//int *arr[5] will not poduce the correct results as * arr[5]
//is array of 5 pointers to integer;
void print_3D_araay(int (*arr)[2][5],int rows);
int main()
{
	int arr[2][5] = {{1,2,3,4,5},{6,7,8,9,10}};
	print_array(&arr[0],2);
}

void print_array(int (*arr)[5],int rows)
{
	int i,j;
	for( i = 0; i< rows; i++)
	{
		for( j = 0;j<5;j++)
		{
			printf("&arr[%d][%d] = %p, arr[%d][%d] = %d\n",i,j,&arr[i][j],i,j,arr[i][j]);
		}
	}
}
