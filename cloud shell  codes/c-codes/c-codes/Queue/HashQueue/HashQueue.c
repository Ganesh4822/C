
#include<stdlib.h>
#include<stdio.h>
#include "HashQueue.h"


// typedef struct process thread;
// typedef int PID;
// struct process
// {
//     PID p_id;
//     struct process* next;
//     struct process* prev;
//     struct process* next_process;
//     struct processs* prev_process;
// };

hashq_t* createHqueue(int bucket_size)
{
    hashq_t* new_queue =NULL;
    if(0 == bucket_size)
        return (NULL); 
    new_queue = (hashq_t*)xcalloc(1, sizeof(hashq_t));
    new_queue->bucket_size = bucket_size;
    int i;
    new_queue->pp_list_arr = (list_t**)xcalloc(bucket_size,sizeof(list_t*));
    for(i = 0;i<bucket_size ; i++)
    {
        new_queue->pp_list_arr[i] = create_list();
    }

    return(new_queue);
}

status_t add_key(hashq_t* p_hqueue, key_t key)
{   status_t status;
    status = insert_end(p_hqueue->pp_list_arr[hash_it(key, p_hqueue->bucket_size)], key);
    if(SUCCESS != status )
    {
        fprintf(stderr, "Unexpected error\n"); 
        exit(EXIT_FAILURE); 
    }
    return(SUCCESS);
}

status_t remove_key(hashq_t* p_hqueue, key_t key)
{
    status_t status;
    node_t* p_node = search_node(p_hqueue->pp_list_arr[hash_it(key, p_hqueue->bucket_size)],key);
    if(p_node == NULL)
        return(BAD_KEY);
    generic_delete(p_node);
    return(SUCCESS);
}

status_t search_key(hashq_t* p_hqueue, key_t key)
{
    return(search_data(p_hqueue->pp_list_arr[hash_it(key,p_hqueue->bucket_size)],key));
}

status_t destroy(hashq_t** pp_hqueue)
{
    hashq_t* p_hash = *pp_hqueue;
    status_t status;
    int i;
    for(i = 0 ; i < p_hash->bucket_size ; i++)
    {
        status = destroy_list(p_hash->pp_list_arr[i]);
        if(SUCCESS != status)
        {
            fprintf(stderr, "Unexpected error\n"); 
            exit(EXIT_FAILURE); 
        }
    }
    free(p_hash->pp_list_arr);
    free(p_hash);
    *pp_hqueue = NULL;
    return (SUCCESS);
}

void hashstat(hashq_t* p_hqueue)
{
    int i; 
    printf("Bucket Size = %d\n", p_hqueue->bucket_size); 
    for(i = 0; i < p_hqueue->bucket_size; ++i)
        printf("MODULO(%d):%d\n", i, get_list_length(p_hqueue->pp_list_arr[i]));
}

list_t* create_list(void){
    list_t* p_list = NULL; 

    p_list = get_node(0); 
    p_list->prev = p_list; 
    p_list->next = p_list; 

    return (p_list); 
}
 
status_t insert_end(list_t* p_list, key_t key)
{
    generic_insert(p_list->prev, get_node(key), p_list);
    return (SUCCESS);
} 

status_t remove_data(list_t* p_list, key_t key)
{
    node_t* p_delete = NULL; 

    p_delete = search_node(p_list, key); 
    if(NULL == p_delete)
        return (LIST_DATA_NOT_FOUND); 
    generic_delete(p_delete); 
    
    return (SUCCESS); 
}

status_t search_data(list_t* p_list, key_t key)
{
     node_t* p_search_node = NULL; 

    p_search_node = search_node(p_list, key); 
    return (p_search_node != NULL); 
} 

len_t get_list_length(list_t* p_list)
{
    len_t len; 
    list_t* p_run = NULL; 

    len = 0; 
    for(p_run = p_list->next; p_run != p_list; p_run = p_run->next)
        ++len; 

    return (len); 
}

status_t destroy_list(list_t* p_list)
{
     node_t* p_run = NULL; 
    node_t* p_run_next = NULL; 

    for(p_run = p_list->next; p_run != p_list; p_run = p_run_next)
    {
        p_run_next = p_run->next; 
        free(p_run); 
    }

    free(p_list); 

    return (SUCCESS);
}


void generic_insert(node_t* p_beg, node_t* p_mid, node_t* p_end)
{
    p_mid->next = p_end; 
    p_mid->prev = p_beg; 
    p_beg->next = p_mid; 
    p_end->prev = p_mid; 
}

void generic_delete(node_t* p_delete)
{
    
    p_delete->prev->next = p_delete->next; 
    p_delete->next->prev = p_delete->prev; 
    free(p_delete); 
} 

node_t* search_node(list_t* p_list, key_t key)
{
    node_t* p_run = NULL; 

    for(p_run = p_list->next; p_run != p_list; p_run = p_run->next)
        if(p_run->key == key)
            return (p_run); 

    return (NULL);
}

node_t* get_node(key_t key)
{
    node_t* new_node = NULL;
    new_node = (node_t*)xcalloc(1,sizeof(node_t));
    new_node->key = key;
    new_node->next = NULL;
    new_node->prev = NULL;
    return(new_node);
}

void* xcalloc(int nr_elements, int size_per_element)
{
    void* p = calloc(nr_elements,size_per_element);
    if(p == NULL)
    {
        fprintf(stderr, "calloc:out of memory\n"); 
        exit(EXIT_FAILURE);
    }
    return p;
}

int hash_it(key_t key, int bucket_size)
{
    return (key % bucket_size); 
}