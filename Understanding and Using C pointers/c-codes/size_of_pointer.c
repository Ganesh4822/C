#include<stdio.h>

struct Human{
	int height;
	int weight;
	char* names;
};
int main(void)
{
	printf("%d\n",sizeof(char*));
	printf("%d\n",sizeof(int*));
	printf("%d\n",sizeof(struct Human*));
}
