#ifndef _PRIORITY_QUEUE
#define _PRIORITY_QUEUE

#include<stdio.h>
#include<stdlib.h>
#include<assert.h>

#define SUCCESS                 1 
#define TRUE                    1 
#define FALSE                   0
#define LIST_DATA_NOT_FOUND     2 
#define LIST_EMPTY              3 
#define QUEUE_EMPTY             LIST_EMPTY 

typedef char* name_t; 
typedef int status_t; 
typedef int priority_t;

typedef struct node node_t; 
typedef node_t list_t; 
typedef list_t prio_queue_t; 

struct node
{
    priority_t priority;
    name_t name;
    struct node* next;
    struct node* prev;
};


//List Specific routines
// list_t* create_list(); 
// status_t insert_beg(list_t* p_list, name_t new_data); 
// status_t insert_end(list_t* p_list, name_t new_data); 
// status_t remove_beg(list_t* p_list, name_t* p_beg_data); 
// status_t remove_end(list_t* p_list, name_t* p_end_data); 
// status_t is_list_empty(list_t* p_list); 
// status_t destroy_list(list_t** pp_list); 

void generic_insert(node_t* p_beg, node_t* p_mid, node_t* p_end); 
void generic_delete(node_t* p_delete_node); 
node_t* get_node(name_t name, priority_t pt); 
void* xcalloc(size_t nr_elements, size_t size_per_element);

//Priority Queue Routines
prio_queue_t* create_queue();

void show(prio_queue_t* p_list, const char* msg);
status_t search_element_in_queue(prio_queue_t* pqueue,priority_t p,node_t** p_node);
status_t enqueue(prio_queue_t* pqueue, name_t data , priority_t p);
status_t max_dequeue(prio_queue_t* pqueue, name_t* get_data);
status_t min_dequeue(prio_queue_t* pqueue, name_t* get_data);
status_t is_empty_queue(prio_queue_t* pqueue);
status_t destroy_pqueue(prio_queue_t** pqueue);
#endif