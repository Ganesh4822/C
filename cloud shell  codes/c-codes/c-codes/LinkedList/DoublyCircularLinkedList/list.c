#include "list.h"



list_t* create_list()
{
    list_t* new_list = get_node(-1);
    return new_list;
}

status_t insert_start(list_t* p_list, data_t data)
{
    generic_insert(p_list, get_node(data), p_list->next);
    return (SUCCESS);
}

status_t insert_end(list_t* p_list, data_t data)
{
    generic_insert(p_list->prev,get_node(data) , p_list);
    return(SUCCESS);
}

status_t insert_after(list_t* p_list,data_t s_data, data_t data)
{
    node_t* p_enode = NULL; 

    if((p_enode = search_node(p_list, s_data)) == NULL)
        return (LIST_DATA_NOT_FOUND); 

    generic_insert(p_enode, get_node(data), p_enode->next); 
    return (SUCCESS); 
}

status_t insert_before(list_t* p_list, data_t s_data, data_t data)
{
    node_t* p_enode = NULL; 

    if((p_enode = search_node(p_list, s_data)) == NULL)
        return (LIST_DATA_NOT_FOUND); 

    generic_insert(p_enode->prev, get_node(data), p_enode); 
    return (SUCCESS);
}

status_t get_start(list_t* p_list, data_t* get_data)
{
    if(is_empty(p_list))
        return (LIST_EMPTY); 

    *get_data = p_list->next->data; 
    return (SUCCESS); 
}

status_t get_end(list_t* p_list, data_t* get_data)
{
    if(is_empty(p_list))
        return (LIST_EMPTY); 
    *get_data = p_list->prev->data;
    return(SUCCESS);
}

status_t pop_start(list_t* p_list, data_t* get_data)
{
    if(is_empty(p_list))
        return (LIST_EMPTY); 

    *get_data = p_list->next->data; 
    generic_delete(p_list->next); 
    
    return (SUCCESS); 
}

status_t pop_end(list_t* p_list, data_t* get_data)
{
    if(is_empty(p_list))
        return (LIST_EMPTY); 

    *get_data = p_list->prev->data; 
    generic_delete(p_list->prev); 
    
    return (SUCCESS); 
}

status_t remove_start(list_t* p_list)
{
     if(is_empty(p_list))
        return (LIST_EMPTY); 

    generic_delete(p_list->next); 
    return (SUCCESS);
}

status_t remove_end(list_t* p_list)
{
    if(is_empty(p_list))
        return (LIST_EMPTY); 
    
    generic_delete(p_list->prev); 
    return (SUCCESS); 
}

status_t remove_data(list_t* p_list, data_t r_data)
{
    node_t* p_rnode = NULL; 
 
    p_rnode = search_node(p_list, r_data); 
    if(p_rnode == NULL)
        return (LIST_DATA_NOT_FOUND); 
    generic_delete(p_rnode); 
    
    return (SUCCESS);
}

length_t get_length(list_t* p_list)
{
    length_t count = 0;
    node_t* p_run = NULL;
    for(p_run = p_list->next ; p_run != p_list ; p_run = p_run ->next)
        count++;
    return count;
}

Bool is_empty(list_t* p_list)
{
    return(p_list->next == NULL);
}

Bool is_member(list_t* p_list, data_t s_data)
{
    node_t* p_run = NULL;
    for(p_run = p_list->next; p_run != p_list ; p_run = p_run->next)
    {
        if(p_run ->data == s_data)
            return TRUE;
    }
    return FALSE;
}

void show(list_t* p_list, const char* msg)
{
    node_t* p_run = NULL; 

    if(msg)
        puts(msg); 

    printf("[START]<->"); 
    for(p_run = p_list->next; p_run != p_list; p_run = p_run->next)
        printf("[%d]<->", p_run->data); 
    puts("[END]"); 
}

list_t* concat(list_t* p_list1, list_t* p_list2)
{
    list_t* p_new_list = NULL;
    node_t* p_run = NULL;
    p_new_list = create_list();
    for(p_run = p_list1 ->next ; p_run != p_list1 ; p_run = p_run->next )
        insert_end(p_new_list, p_run->data);
    for(p_run = p_list2 ->next ; p_run != p_list2; p_run = p_run->next)
        insert_end(p_new_list, p_run->data);
    return p_new_list;

}

list_t* get_reversed_list(list_t* p_list_1)
{
    list_t* p_reversed_list = NULL;
    node_t* p_run = NULL;
    p_reversed_list = create_list();
    for(p_run = p_list_1->next ; p_run != p_list_1 ; p_run = p_run ->next)
        insert_start(p_reversed_list, p_run->data);
    return (p_reversed_list);
}

list_t* merge(list_t* p_list1, list_t* p_list2)
{
    node_t* p_run_1 = NULL;
    node_t* p_run_2 = NULL;

    list_t* p_merged_list = NULL;
    p_merged_list = create_list();

    p_run_1 = p_list1->next;
    p_run_2 = p_list2->next;

    while(TRUE)
    {
        if(p_run_1 == NULL)
        {
            while(p_run_2 != p_list2)
            {
                insert_end(p_merged_list, p_run_2-> data);
                p_run_2 = p_run_2 ->next;
            }
        }

        if(p_run_2 == NULL)
        {
            while(p_run_1 != p_list1 )
            {
                insert_end(p_merged_list, p_run_1 ->data);
                p_run_1 = p_run_1->next;
            }
        }

        if(p_run_1 -> data <= p_run_2 -> data)
        {
            insert_end(p_merged_list, p_run_1->data);
            p_run_1 = p_run_1->next;
        }
        else {
            insert_end(p_merged_list, p_run_2->data);
            p_run_2 = p_run_2 -> next; 
        }
    }
    return p_merged_list;
}

status_t append_list(list_t* list1 , list_t* list2)
{
    return (SUCCESS);
}

status_t reverse_list(list_t* p_list)
{
    node_t* original_first_node = NULL;
    node_t* p_run = NULL;
    node_t* p_next_run = NULL;

    original_first_node = p_list->next;
    
    for(p_run = p_list->next->next ; p_run != p_list ; p_run = p_next_run )
    {
        p_next_run = p_run->next;
        generic_insert(p_list, p_run, p_list->next);
    }
    original_first_node->next = p_list;
    p_list->prev = original_first_node;
    return (SUCCESS);
}

status_t destroy_list(list_t** destroy_list)
{
    node_t* p_node = NULL;
    node_t* p_next_node = NULL;
    list_t* p_list = *destroy_list;
    p_node = p_list->next;
    while(p_node != *destroy_list)
    {
        p_next_node = p_node->next;
        free(p_node);
        p_node = p_next_node;
    }

    free(p_list);
    *destroy_list = NULL;
    return (SUCCESS);
    
}

static void generic_insert(node_t* p_beg, node_t* p_mid, node_t* p_end)
{
    p_beg->next = p_mid;
    p_end->prev = p_mid;
    p_mid->next = p_end;
    p_mid->prev = p_beg;
} 

static void generic_delete(node_t* p_delete_node)
{
    p_delete_node->prev->next = p_delete_node->next;
    p_delete_node->next->prev = p_delete_node->prev;
    free(p_delete_node);
} 

static node_t* search_node(list_t* p_list, data_t s_data)
{
    node_t* p_node = NULL;
    for(p_node = p_list->next ;p_node != p_list; p_node = p_node->next)
    {
        if(p_node->data == s_data)
            return p_node;
    }
    return NULL;

} 

static node_t* get_node(data_t new_data)
{
    node_t* new_node = xcalloc(1, sizeof(node_t));
    new_node->data = new_data;
    new_node->next = NULL;
    new_node->prev = NULL;
    return new_node;
} 

static void* xcalloc(size_t nr_elements, size_t size_per_element)
{
    void* p;
    p = calloc(nr_elements,size_per_element);
    return p;
}
