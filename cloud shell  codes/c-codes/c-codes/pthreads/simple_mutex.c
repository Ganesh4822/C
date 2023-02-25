#include<stdio.h>
#include<pthread.h>

void do_one_thing(int*);
void do_another_thing(int*);
void do_wrap_up(int, int);

int r1 = 0, r2 =0 , r3 =0;

pthread_mutex_t r3_mutex = PTHREAD_MUTEX_INITIALIZER;

int main(int argc, char** argv)
{
    pthread
}
