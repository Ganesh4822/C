#include "list.h"


list_t* create_list()
{
    list_t* new_list = get_node(-1);
}

status_t insert_start(list_t* p_list, data_t data)
{

}

status_t insert_end(list_t* p_list, data_t data)
{

}

status_t insert_after(list_t* p_list,data_t s_data, data_t data)
{

}

status_t insert_before(list_t* p_list, data_t s_data, data_t data)
{

}

status_t get_start(list_t* p_list, data_t* get_data)
{

}

status_t get_end(list_t* p_list, data_t* get_data)
{

}

status_t pop_start(list_t* p_list, data_t* get_data)
{

}

status_t pop_end(list_t* p_list, data_t* get_data)
{

}

status_t remove_start(list_t* p_list)
{

}

status_t remove_end(list_t* p_list)
{

}

status_t remove_data(list_t* p_list, data_t r_data)
{

}

length_t get_length(list_t* p_list)
{

}

Bool is_empty(list_t* p_list)
{

}

Bool is_member(list_t* p_list, data_t s_data)
{

}

void show(list_t* p_list, const char* msg)
{

}

list_t* concat(list_t* p_list1, list_t* p_list2)
{

}

list_t* get_reversed_list(list_t* p_list_1)
{

}

list_t* merge(list_t* p_list1, list_t* p_list2)
{

}

status_t append_list(list_t* list1 , list_t* list2)
{

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
