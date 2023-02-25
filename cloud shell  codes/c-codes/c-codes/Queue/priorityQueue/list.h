#ifndef _DOUBLY_CIRCULAR_LINKED_LIST
#define _DOUBLY_CIRCULAR_LINKED_LIST

#include <stdio.h>
#include<stdlib.h>

#define SUCCESS 1
#define TRUE 1
#define FALSE 0
#define LIST_DATA_NOT_FOUND 2
#define LIST_EMPTY 3

typedef int data_t;
typedef int status_t;
typedef int length_t;
typedef int Bool;

typedef struct node node_t;
typedef struct node list_t;

struct node
{
    data_t data;
    struct node* next;
    struct node* prev;
};

//Interface routines

list_t* create_list();

status_t insert_start(list_t* p_list, data_t data);
status_t insert_end(list_t* p_list, data_t data);
status_t insert_after(list_t* p_list,data_t s_data, data_t data);
status_t insert_before(list_t* p_list, data_t s_data, data_t data);

status_t get_start(list_t* p_list, data_t* get_data);
status_t get_end(list_t* p_list, data_t* get_data);
status_t pop_start(list_t* p_list, data_t* get_data);
status_t pop_end(list_t* p_list, data_t* get_data);

status_t remove_start(list_t* p_list);
status_t remove_end(list_t* p_list);
status_t remove_data(list_t* p_list, data_t r_data);

length_t get_length(list_t* p_list);
Bool is_empty(list_t* p_list);
Bool is_member(list_t* p_list, data_t s_data);
void show(list_t* p_list, const char* msg);

list_t* concat(list_t* p_list1, list_t* p_list2);
list_t* get_reversed_list(list_t* p_list_1);
list_t* merge(list_t* p_list1, list_t* p_list2);

status_t append_list(list_t* list1 , list_t* list2);
status_t reverse_list(list_t* p_list);

status_t destroy_list(list_t** destroy_list);

static void generic_insert(node_t* p_beg, node_t* p_mid, node_t* p_end); 
static void generic_delete(node_t* p_delete_node); 
static node_t* search_node(list_t* p_list, data_t s_data); 
static node_t* get_node(data_t new_data); 
static void* xcalloc(size_t nr_elements, size_t size_per_element); 

#endif