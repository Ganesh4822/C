#include<stdio.h>
#include<ctype.h>

double atof(char* s)
{
	int i,sign;
	double val,power;
	i =0;
	for(i = 0; isspace(s[i]); i++)
		;
	sign  = (s[i] == '-')? -1 : 1;
	if(s[i] == '+' || s[i] == '-')
		++i;
	for(val = 0.0 ; isdigit(s[i]); i++)
		val = val * 10 + s[i] - '0';
	if(s[i] == '.')
		++i;
	for(power = 1.0; isdigit(s[i]); i++)
	{
		val = 10 * val + s[i] - '0';
		power = power * 10;
	}
	return sign * val /power;
	

}

int main()
{
	char* number = "153.546";
	printf("number is %f",atof(number) );
}

