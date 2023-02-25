#include "singlyLinkedList.h"
#include <stdlib.h>

//generic routines
static void generic_insert(node_t* p_beg, node_t* p_mide, list_t* p_end)
{
    p_beg->next = p_mide;
    p_mide->next = p_end;
}

static void generic_delete(node_t* p_prev_node,node_t* delete_node)
{
    p_prev_node->next = delete_node->next;
    free(delete_node);
}

static node_t* search_node(list_t* p_list,data_t search_data)
{
    node_t* p_run = NULL;
    p_run = p_list->next;
    while(p_run!= NULL)
    {
        if(p_run->data == search_data)
            return p_run;
        
    }
    return p_run;
}

static void get_node_and_prev(list_t* p_list, data_t s_data, node_t** get_node, node_t** prev_node)
{
    node_t* p_node = p_list->next;
    node_t* p_prev_node = p_list;
    while(p_node != NULL)
    {
        if(p_node ->data == s_data)
        {
            *get_node = p_node;
            *prev_node = p_prev_node;
            return;
        }
        p_prev_node = p_node;
        p_node = p_node->next;
    }
    *get_node = NULL;
    *prev_node = NULL;
}

static void get_last_node(list_t* p_list, node_t** pp_last_node)
{
    node_t* p_run = p_list;
    while(p_run->next != NULL)
    {
        p_run = p_run ->next;
    }

    *pp_last_node = p_run;
}

static void get_last_node_and_prev(list_t* p_list,node_t** pp_prev_node, node_t** pp_last_node)
{
    node_t* p_run = p_list;
    node_t* p_prev_run = NULL;

    while(p_run ->next != NULL)
    {
        p_prev_run = p_run;
        p_run = p_run->next;
    }
    *pp_prev_node = p_prev_run;
    *pp_last_node = p_run;
}

static node_t* get_node(data_t new_data)
{
    node_t* new_node = (node_t*)xmalloc(sizeof(node_t));
    new_node -> data = new_data;
    new_node ->next = NULL;
    return (new_node);
}

static void* xmalloc(size_t nr_bytes)
{
    void * ptr;
    ptr = malloc(nr_bytes);
    if (ptr == NULL)
	{
		fprintf(stderr, "malloc:out of memory\n"); 
		exit(EXIT_FAILURE); 
	}
    return ptr;
}

list_t* create_list(void)
{
    list_t* llist = (list_t*)xmalloc(sizeof(list_t));
    llist->data = -1;
    llist->next = NULL;
    return(llist);
}

status_t insert_start(list_t* p_list, data_t data)
{
    generic_insert(p_list, get_node(data) , p_list->next);
    return (SUCCESS);
}

status_t insert_end(list_t* p_list,data_t data)
{
    node_t* last_node = NULL;
    get_last_node(p_list, &last_node);
    generic_insert(last_node,get_node(data),last_node);
    return (SUCCESS);
}

status_t insert_after(list_t* p_list, data_t after_data, data_t data)
{
    node_t* p_existing_node = search_node(p_list, after_data);
    if(p_existing_node == NULL)
    {
        return(LIST_DATA_NOT_FOUND);
    }
    generic_insert(p_existing_node, get_node(data), p_existing_node->next);
    return(SUCCESS);

}

status_t insert_before(list_t* p_list, data_t before_data, int data)
{
    node_t* p_prev_node = NULL;
    node_t* p_node = NULL;
    get_node_and_prev(p_list,before_data,&p_node, &p_prev_node);
    if(p_node == NULL)
        return LIST_DATA_NOT_FOUND;
    generic_insert(p_prev_node, get_node(data), p_node);
    return (SUCCESS);
}

status_t get_start(list_t* p_list, data_t* get_data)
{
    if(is_empty(p_list)== TRUE)
        return (LIST_EMPTY);
    *get_data = p_list->next->data;
    return (SUCCESS);
}

status_t get_end(list_t* p_list, data_t* get_end_data)
{
    node_t* p_last_node = NULL; 
	if (is_empty(p_list) == TRUE)
		return (LIST_EMPTY);
    get_last_node(p_list, &p_last_node);
    *get_end_data = p_last_node->data;
    return (SUCCESS);

}

status_t pop_start(list_t* p_list, data_t* get_start_data)
{
    if (is_empty(p_list) == TRUE)
		return (LIST_EMPTY);
	*get_start_data = p_list->next->data;
	generic_delete(p_list, p_list->next); 
	return (SUCCESS);
}

status_t pop_end(list_t* p_list, data_t* get_end_data)
{
    if (is_empty(p_list) == TRUE)
		return (LIST_EMPTY);
    node_t* last_node = NULL;
    node_t* prev_node = NULL;
    get_last_node_and_prev(p_list, &prev_node, &last_node);
    *get_end_data = last_node->data;
    generic_delete(prev_node, last_node);
    return(SUCCESS);
}

status_t remove_start(list_t* p_list)
{
    if (is_empty(p_list) == TRUE)
		return (LIST_EMPTY);
    generic_delete(p_list,p_list->next);
    return(SUCCESS);
}

status_t remove_end(list_t* p_list)
{
    if(is_empty(p_list) == TRUE)
        return(LIST_EMPTY);
    node_t* p_node = NULL;
    node_t* p_prev_node = NULL;
    get_last_node_and_prev(p_list, &p_prev_node, &p_node);
    generic_delete(p_prev_node, p_node);
    return(SUCCESS);
}

status_t remove_data(list_t* p_list, data_t data)
{
    node_t* p_data_node = NULL; 
	node_t* p_data_node_prev = NULL; 
	
	get_node_and_prev(p_list, data, &p_data_node, &p_data_node_prev);
	if (p_data_node == NULL)
		return (LIST_DATA_NOT_FOUND); 
	generic_delete(p_data_node_prev, p_data_node); 
	return (SUCCESS); 
}

length_t get_length(list_t* p_list)
{
    node_t* p_run = NULL; 
	length_t len = 0; 
	p_run = p_list->next; 
	while (p_run != NULL)
	{
		++len; 
		p_run = p_run->next; 
	}

	return (len);
}

Bool is_empty(list_t* p_list)
{
    return(p_list->next == NULL);
}

Bool is_member(list_t* p_list, data_t s_data)
{
    node_t* p_node = NULL; 
	p_node = search_node(p_list, s_data); 
	if (p_node == NULL)
		return (FALSE); 
	return (TRUE); 
}

void show(list_t* p_list, const char* msg)
{
    node_t* p_run = NULL; 
	if (msg)
		puts(msg); 

	printf("[START]->"); 
	p_run = p_list->next; 
	while (p_run != NULL)
	{
		printf("[%d]->", p_run->data); 
		p_run = p_run->next; 
	}
	puts("[END]"); 
}

list_t* concat(list_t* p_list1, list_t* p_list2)
{
    list_t* new_list = create_list();
    node_t* p_run = NULL;
    for(p_run = p_list1->next ; p_run != NULL ; p_run = p_run->next)
        insert_end(new_list,  p_run->data);
    for(p_run = p_list2->next ; p_run != NULL ; p_run = p_run->next)
        insert_end(new_list, p_run->data);
    return (new_list);
}

list_t* get_reversed_list(list_t* p_list)
{
    list_t* p_reversed_list = NULL; 
	node_t* p_run = NULL; 
	
	p_reversed_list = create_list(); 
	for (p_run = p_list->next; p_run != NULL; p_run = p_run->next)
		insert_start(p_reversed_list, p_run->data); 

	return (p_reversed_list);
}

list_t* merge(list_t* p_list1, list_t* p_list2)
{
    node_t* p_run1 = NULL;
    node_t* p_run2 = NULL;
    list_t* merged_list = NULL;

    merged_list = create_list();
    p_run1 = p_list1->next;
    p_run2 = p_list2->next;

    while(TRUE)
    {
        if(p_run1 == NULL)
        {
            for(;p_run2 != NULL; p_run2 = p_run1 ->next)
                insert_end(merged_list,p_run2->data);
            break;
        }

        
		if (p_run2 == NULL)
		{
			for (; p_run1 != NULL; p_run1 = p_run1->next)
				insert_end(merged_list, p_run1->data); 
			
			break; 
		}

        if(p_run1->data <= p_run2->data)
        {
            insert_end(merged_list, p_run1->data);
            p_run1 = p_run1->next;
        }
        else
        {
            insert_end(merged_list, p_run2->data);
            p_run2 = p_run2->next;
        }

    }
    return(merged_list);
}

status_t append(list_t* p_list1, list_t* p_list2)
{
    node_t* list1_end_node = NULL;
    get_last_node(p_list1, &list1_end_node);

    list1_end_node->next = p_list2->next;
    return(SUCCESS);
}

status_t reverse_list(list_t* p_list)
{
    node_t* p_run = NULL;
    node_t* p_run_next = NULL;
    p_run = p_list->next->next;
    p_list->next->next = NULL;
    while(p_run != NULL)
    {
        p_run_next = p_run->next;
        generic_insert(p_list, p_run, p_list->next );
        p_run = p_run_next;
    }

    return (SUCCESS);
}

void to_array(list_t* p_list, data_t** p_arr, size_t* p_size);
list_t* to_list(data_t* p_array, size_t size);

status_t destroy_list(list_t** p_list)
{
    node_t* p_run = NULL;
    node_t* p_cur = NULL;
    list_t* p_lst = NULL;
    p_lst  = *p_list;

    for(p_run = p_lst->next ; p_run != NULL ; p_run = p_cur)
    {
        p_cur = p_run->next;
        free(p_run);
    }
    free(p_lst);
    *p_list = NULL;
    return(SUCCESS);
}