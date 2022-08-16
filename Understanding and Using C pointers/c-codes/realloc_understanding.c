#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void release_mem(char** p);
int main(void)
{
	char* buffer = malloc(10);
	printf("buffer = %p\n", buffer);
	//buffer = "My name";
	//Error : invalid pointer()
	strcpy(buffer, "ganesh");
	printf("string is %s,\n",buffer);
	char* buffer2 = realloc(buffer, 100);
	printf("strin is  = %s\n", buffer2);
	printf("buffer2 = %p\n", buffer2);
	printf("buffer = %p\n", buffer);
	printf("buffer = %s\n", buffer);
	//release_mem(&buffer);
	if(buffer  == "")
	{
		printf("Hii");
	}
}

void release_mem(char** p)
{
	free(*p);
	*p = NULL;

}
