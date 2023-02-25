#include<stdio.h>
#include<stdlib.h>

int main(void)
{
	int num = 12345678;
	char* pc = (char*)&num;
	int i =0;
	for(i = 0 ; i<4 ; i++)
	{
		printf("%p : %d \n ", pc, (unsigned int)*pc++);
	}
}
