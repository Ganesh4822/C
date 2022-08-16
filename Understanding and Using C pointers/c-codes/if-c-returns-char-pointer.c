#include<stdio.h>

char* number_to_key(int number)
{
	if(number == 1)
		return "abc";
	else if(number == 2)
		return "def";

}

int main(void)
{
	char* s;
	s = number_to_key(2);
	printf("%s\n", s);
}
