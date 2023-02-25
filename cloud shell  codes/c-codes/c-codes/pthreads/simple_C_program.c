#include<stdio.h>
void do_one_thing(int*);
void do_another_thing(int*);
void do_wrap_up(int, int);

int r1 =0 , r2 = 0;

int main()
{
    do_one_thing(&r1);
    do_another_thing(&r2);
    do_wrap_up(r1, r2);
}

void do_one_thing(int* pnum_times)
{
    int i,j,x;
    x = 0;
    for(i = 0 ; i<4; i++)
    {
        printf("Doing one thing\n");
        for(j = 0 ; j<10000 ; j++)
            x = x +1;
        (*pnum_times)++;
    }
}

void do_another_thing(int* pnum_times)
{
    int i,j,x;
    x =0;
    for(i = 0 ; i<4; i++)
    {
        printf("Doing another thing\n");
        for(j = 0 ; j<10000 ; j++)
            x = x +1;
        (*pnum_times)++;
    }
}

void do_wrap_up(int one_times, int another_times)
{
    int total = 0;
    total = one_times + another_times;
    printf("wrap up one times = %d, another_times= %d, total = %d\n",one_times,another_times,total);
}