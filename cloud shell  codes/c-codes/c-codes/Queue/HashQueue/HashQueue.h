#ifndef _HASHQUEUE_
#define _HASHQUEUE_

#define TRUE 1 
#define FALSE 0 
#define SUCCESS 1 
#define LIST_DATA_NOT_FOUND 2 
#define BAD_KEY LIST_DATA_NOT_FOUND

typedef int  key_t  ;
typedef int len_t ;
typedef int status_t;
typedef struct node node_t;
typedef node_t list_t;
typedef struct hashq hashq_t;

struct node
{
    key_t key;
    struct node* next;
    struct node* prev;
};

struct hashq
{
    list_t** pp_list_arr;
    int bucket_size;
};

hashq_t* createHqueue(int bucket_size);
status_t add_key(hashq_t* p_hqueue, key_t key);
status_t remove_key(hashq_t* p_hqueue, key_t key);
status_t search_key(hashq_t* p_hqueue, key_t key);
status_t destroy(hashq_t** p_hqueue);
void hashstat(hashq_t* p_hqueue);

list_t* create_list(void); 
status_t insert_end(list_t* p_list, key_t key); 
status_t remove_data(list_t* p_list, key_t key); 
status_t search_data(list_t* p_list, key_t key); 
len_t get_list_length(list_t* p_list); 
status_t destroy_list(list_t* p_list); 

void generic_insert(node_t* p_beg, node_t* p_mid, node_t* p_end); 
void generic_delete(node_t* p_delete); 
node_t* search_node(list_t* p_list, key_t key); 
node_t* get_node(key_t key); 

void* xcalloc(int nr_elements, int size_per_element); 

int hash_it(key_t key, int bucket_size);


#endif


