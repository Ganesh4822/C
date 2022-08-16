#include<stdio.h>
#include<stdlib.h>
#include<assert.h>

typedef struct A struct_a;
typedef struct B struct_b;

struct A{
int a;
int b;
int c;

};

struct B{
	int d;
	struct_a* as;

};

int main(){
struct_b* ba= NULL;
ba = (struct_b*)malloc(sizeof(struct_b));
assert(ba);
ba->d = 10;
ba->as = (struct_a*)malloc(sizeof(struct_a));
ba->as->a=9;
ba->as->b=8;
ba->as->c=7;

printf("%d-%d-%d-%d\n",ba->d,ba->as->a,ba->as->b,ba->as->c);


}



