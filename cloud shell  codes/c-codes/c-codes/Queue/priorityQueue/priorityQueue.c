#include "priorityQueue.h"
#include<string.h>

//List Routines
list_t* create_list()
{
    list_t* new_list = get_node(NULL,-1);
    return new_list;
}  

void generic_insert(node_t* p_beg, node_t* p_mid, node_t* p_end)
{
    p_beg->next = p_mid;
    p_end->prev = p_mid;
    p_mid->next = p_end;
    p_mid->prev = p_beg;

}

void generic_delete(node_t* p_delete_node)
{
    p_delete_node->prev->next = p_delete_node->next;
    p_delete_node->next->prev = p_delete_node->prev;
    free(p_delete_node);
} 

node_t* get_node(name_t data,priority_t pt)
{
    node_t* p = NULL;
    p = (node_t*)xcalloc(1, sizeof(node_t));
    p->priority = pt;
    p->name = data;
    return p;
} 

void* xcalloc(size_t nr_elements, size_t size_per_element)
{
    void* p = calloc(nr_elements,size_per_element);
    return p;
}

//Priority Queue Routines
prio_queue_t* create_queue()
{
    prio_queue_t* new_queue = get_node(NULL, -1);
    new_queue->next = new_queue;
    new_queue->prev = new_queue;
    return new_queue;
}

status_t enqueue(prio_queue_t* pqueue, name_t data , priority_t p)
{
    node_t* p_run = 0;
    p_run = pqueue->next;
    while(p_run->priority < p && p_run != pqueue)
    {
        p_run = p_run->next;
    }
    generic_insert(p_run->prev,get_node(data,p), p_run);
    return (SUCCESS);
}

status_t max_dequeue(prio_queue_t* pqueue, name_t* get_data)
{
    strcpy(*get_data, pqueue->prev->name);

    generic_delete(pqueue->prev);
    return SUCCESS;
}

status_t min_dequeue(prio_queue_t* pqueue, name_t* get_data)
{
    strcpy(*get_data,pqueue->next->name);
    generic_delete(pqueue->next);
    return(SUCCESS);
}

status_t is_empty_queue(prio_queue_t* pqueue)
{
    return(pqueue->next == pqueue ? QUEUE_EMPTY : FALSE);
         
}

status_t destroy_pqueue(prio_queue_t** pqueue)
{
    prio_queue_t* pqueue_run = *pqueue;
    prio_queue_t* p_run = NULL;
    prio_queue_t* p_run_next = NULL;
    for(p_run = pqueue_run->next ; p_run != pqueue_run; p_run = p_run_next)
    {
        p_run_next = p_run->next;
        free(p_run);
    }
    free(pqueue_run);
    *pqueue = NULL;
    return SUCCESS;
}

void show(prio_queue_t* p_list, const char* msg)
{
    node_t* p_run = NULL; 

    if(msg)
        puts(msg); 

    printf("[START]<->"); 
    for(p_run = p_list->next; p_run != p_list; p_run = p_run->next)
        printf("[%s],[%d]<->", p_run->name,p_run->priority); 
    puts("[END]"); 
}