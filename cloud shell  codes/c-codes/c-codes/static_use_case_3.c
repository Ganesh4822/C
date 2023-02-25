#include<stdio.h>
#include<stdlib.h>

void static_use_case(void);

int main(void)
{
	int i =0;
	for(i=0;i<5;i++)
	{
		static_use_case();
	}	
}

void static_use_case(){
	static int n = 0;
	int m = 0;
	for(int k = 0; k<10;k++){
		m++;
		n++;
	}

	printf("values before exiting the function : m : %d, n: %d\n",m,n);

}
