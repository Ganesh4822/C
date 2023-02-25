#include<stdio.h>
#include<stdlib.h>

int main(void)
{
	int num = 188888;
	int* p;
	p = &num;
	short *ps = (short*)p;
	printf("%llu , %llu , %d, %hd\n",p, ps, num , *ps );
}
