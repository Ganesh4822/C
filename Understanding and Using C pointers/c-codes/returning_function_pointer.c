#include<stdio.h>
#include<stdlib.h>


typedef int (*fptroperation)(int, int);
int add(int a, int b);
int sub(int, int);
int mul(int,int);
int divi(int ,int);
fptroperation select1(char opcode);
int evaluate(char opcode, int n1, int n2);

int main(void)
{
	printf(" evaluation = %d\n", evaluate('+',5,6));
	printf(" evaluation = %d\n", evaluate('-',5,6));
	printf(" evaluation = %d\n", evaluate('*',5,6));
	printf(" evaluation = %d\n", evaluate('/',5,6));
}

int add(int a, int b)
{
	return (a+b);
}

int sub(int a, int b)
{
	return (a-b);
}

int mul(int a, int b)
{
	return (a*b);
}

int divi(int a, int b )
{
	if(b != 0)
		return (a/b);
	return 0;
}

fptroperation select1(char opcode)
{
	switch(opcode)
	{
		case '+':
			return add;
		case '-':
			return sub;
		case '*':
			return mul;
		case '/':
			return divi;
		default:
			return add;
	}

}


int evaluate(char opcode, int n1 ,int n2)
{	fptroperation ptr = select1(opcode);
	return ptr(n1,n2);
}
