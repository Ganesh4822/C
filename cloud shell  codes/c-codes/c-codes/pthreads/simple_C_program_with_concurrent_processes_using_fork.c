#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>
#include<sys/signal.h>
#include<sys/ipc.h>
#include<sys/shm.h>
#include<sys/wait.h>

void do_one_thing(int*);
void do_another_thing(int*);
void do_wrap_up(int , int);

int shared_mem_id;
int* shared_mem_ptr;
int* r1p;
int* r2p;


int main(void)
{
    pid_t pid1,pid2;
    int status;

    /*Initialize shared memory segment*/
    shared_mem_id = shmget(IPC_PRIVATE, 2*sizeof(int), 0660);
    shared_mem_ptr = (int*)shmat(shared_mem_id, (void*)0, 0);
    r1p = shared_mem_ptr;
    r2p = (shared_mem_ptr +1);

    *r1p = 0 ;
    *r2p = 0 ;

    if((pid1 = fork()) == 0)
    {
        do_one_thing(r1p);
        exit(0);
    }

    if((pid2 = fork()) == 0)
    {
        do_another_thing(r2p);
        exit(0);
    }

    waitpid(pid1,&status,0);
    waitpid(pid2,&status,0);

    do_wrap_up(*r1p, *r2p);
    return 0;

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