#include<stdio.h>

void shell_sort(int* arr, int n);
int main()
{
	int arr[8] = {6,3,54,23,56,2323,67,1};
	int *pv;
	pv = arr;
	shell_sort(pv,8);
	int i;
	for( i = 0; i < 8; i++)
	{	
		printf("%d\t",arr[i]);

	}
}

void shell_sort(int*  arr, int n)
{
	int gap,i,j,temp;
	for(gap = n/2 ; gap > 0 ; gap /= 2)
	{
		for(int i = gap ; i < n  ; i++)
		{
			for(j = i -gap ; j >= 0 && arr[j] > arr[j+gap]; j = j - gap)
			{
				temp = arr[j];
				arr[j] = arr[j + gap];
				arr[j + gap ] = temp;
			}
		}
	}
}
