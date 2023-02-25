#include<stdio.h>
#include<stdlib.h>

int main(void)
{
	char* names[] = {"Ganesh","nikita","pallavi"};
	printf("%c\n",*(*(names+1)+2));
}

