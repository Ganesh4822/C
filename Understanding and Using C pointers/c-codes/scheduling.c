#include<stdio.h>
#include<sys/types.h>
#include<sys/times.h>


void child(int n);
void main(){

    struct tms pb1,pb2;
    int i;
    long p1,p2;

    p1 = times(&pb1);

    for(i =0; i<1;i++){
      if(fork() == 0)
	      child(i);
    }

    for(i =0 ;i<1 ; i++){
    	wait((int *)0);
    }

    p2 = times(&pb2);
    printf("user time of process is = %ld\n", pb2.tms_utime-pb1.tms_utime);
    printf("kernel time of process is = %ld\n",pb2.tms_stime - pb1.tms_stime);    
 
}

void child(int n){

	printf("this is %d th child\n,",n);

	struct tms tc1,tc2;
	long t1,t2;
	t1 = times(&tc1);

	for(int i = 0 ; i< 100000; i++)
	   printf("Hello\n");
        t2 = times(&tc2);

	printf("user time of %dth childs process= %ld\n",n,tc2.tms_utime - tc1.tms_utime);
        printf("kernel time of %dth child proces = %ld\n",n,tc2.tms_stime - tc1.tms_stime);	
}
