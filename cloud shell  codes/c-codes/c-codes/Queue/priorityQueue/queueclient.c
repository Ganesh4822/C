#include <stdio.h> 
#include <stdlib.h> 
#include <assert.h> 
#include "priorityQueue.h"


int main(void)
{
    prio_queue_t* p_prio_queue = NULL; 
    name_t arr[] = {"Ganesh","asdasd", "dsada", "asdasd","sdasd","sdas", "asdasd", "sasd", "asasd"}; 
    int i; 
    name_t data; 
    status_t ret; 

    p_prio_queue = create_queue(); 
    for(i = 0; i < sizeof(arr)/sizeof(arr[0]); ++i)
        assert(enqueue(p_prio_queue, arr[i],i) == SUCCESS); 

    while(is_empty_queue(p_prio_queue) != TRUE)
    {
        data = ""; 
        min_dequeue(p_prio_queue, &data); 
        printf("data = %s\n", data); 
    }

    ret = destroy_pqueue(&p_prio_queue); 
    assert(ret == 1 && p_prio_queue == NULL); 
    
    return (0); 
}
