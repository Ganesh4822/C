#include<stdio.h>

int main(void)
{
	int a[5] = {1,2,3,5,6};
	printf("a[1] is also equal to : %d",*(a+1));
}
