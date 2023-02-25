#include<stdio.h>
#include<stdlib.h>
void Test1();
void swap(int a, int b);
void swap_by_pointer(int * p, int* q);

int main()
{
    Test1();
}

void Test1()
{
    int x= 10; //1000 - 1003
    int y = 20; // 1004 - 1007
    
    printf("address of x : %p, y : %p\n", &x,&y);
    printf("before swapping x : %d , y : %d\n", x,y);
    swap_by_pointer(&x,&y);//swap(10,20);
    printf("After swapping x : %d , y : %d\n", x,y);
}

void swap(int a,int b)
{
    //a - 3000-3003 - 10
    //b - 3004 - 3007 - 20
    int temp; // 3008 - 3011
    printf("address of a : %p, b : %p\n", &a,&b);
    printf("Before swapping :: swap() , a :: %d , b :: %d\n", a,b);
    temp = a;
    a = b;
    b = temp;
    printf("after swapping :: swap() , a :: %d , b :: %d\n", a,b);

}

void swap_by_pointer(int * p, int* q)
{
    printf("address of p : %p, q: %p\n", p,q);
    int *a;
    
    // int n = 10;  //[10]100-103
    // a = &n;
    // //a = 100;
    // int b = *a;//4 byte read
    // int c = 17;
    // *a = c;//4 byte write from 
    
    int temp = *p;//dereferences address stored in p assign it to temp
    *p = *q;
    *q = temp;
    
}
//main() - > Test1() ->swap()->test1()->main()
//test1() - x , y
 
 /*

 int A[5];

 A = {100,200,300,400,500};

 A = 1000 -1003 = 100
 1004 - 1007 = 200
 1008  - 1011 - 300

int * p;
p = A;

 
A[1] ; 200;
 
 printf("%p",A);
 */

 int* p;

p  = malloc(sizeof(int));
