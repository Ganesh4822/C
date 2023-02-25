#include<stdio.h>
#include<stdlib.h>
typedef struct X struct_x;
struct X{
	int a;
	int b;
	int c;
};


int main(void){

struct_x* x = NULL;
x = (struct_x*)malloc(sizeof(struct_x));
x->a=10;
x->b=9;
x->c=8;
int* p =(int*)x+1;
//printf("%d\n",*x.a);

//int *p = (int*)((int*)x+1);
printf("%d-%d-%d\n",x->a,*p,x->b);
}
