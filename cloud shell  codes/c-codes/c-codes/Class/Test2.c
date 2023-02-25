#include<stdio.h>

int n = 100;//Data section
//char a[10] = "Ganesh";
int sum;
int main()
{
    //Data section
    int  i = 0;
    //RO

    for(i = 0 ; i  < n ; i++)
    {
        sum = sum + i;
    }

    printf("Sum is %d",sum);
  

    //a = "Ingale";
}
//bss
//static data
//global uninitiaized 

//RO global string