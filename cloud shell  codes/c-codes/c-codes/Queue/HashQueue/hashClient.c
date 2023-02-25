#include <stdio.h> 
#include <stdlib.h> 
#include <assert.h> 
#include <time.h> 
#include "HashQueue.h"

int main(int argc, char* argv[])
{
    size_t bucket_size; 
    size_t nr_elements; 
    key_t* keys = NULL; 
    key_t key; 
    hashq_t* p_hashq = NULL; 
    status_t status; 
    size_t i; 

    if(3 != argc)
    {
        fprintf(stderr, "UsageError:%s bucket_size nr_elements\n", argv[0]); 
        exit(EXIT_FAILURE); 
    }
    
    bucket_size = atoll(argv[1]); 
    nr_elements = atoll(argv[2]); 

    assert(bucket_size && nr_elements); 

    srand(time(0)); 

    keys = (key_t*)xcalloc(nr_elements, sizeof(size_t)); 
    for(i = 0; i < nr_elements; ++i)
        keys[i] = rand(); 

    p_hashq = createHqueue(bucket_size); 
    for(i = 0; i < nr_elements; ++i)
    {
        status = add_key(p_hashq, keys[i]); 
        if(SUCCESS != status)
        {
            fprintf(stderr, "Unexpected error\n"); 
            exit(EXIT_FAILURE); 
        }
    }

    hashstat(p_hashq); 

    puts("Search key test : SUCCESS CASES"); 

    for(i = 0; i < 5; ++i)
    {
        key = keys[rand() % nr_elements]; 
        printf("Searching for key:%d\n", key); 
        status = search_key(p_hashq, key); 
        if(TRUE == status)
            printf("Key:%d found\n", key); 
        else
        {
            fprintf(stderr, "Unexpected error\n"); 
            exit(EXIT_FAILURE); 
        }
    }
    
    puts("Search key test : RANDOM CASES : SHOULD BE FALSE MOSTLY"); 
    for(i = 0; i < 5; ++i)
    {
        key = rand(); 
        printf("Searching for key:%d\n", key); 
        status = search_key(p_hashq, key); 
        if(TRUE == status)
            printf("Key:%d found\n", key); 
        else 
            printf("key:%d not found\n", key); 
    }

    key = keys[rand() % nr_elements]; 
    printf("Key to be removed:%d\n", key); 
    status = remove_key(p_hashq, key);
    assert(status);  
    assert(search_key(p_hashq, key) == FALSE); 

    status = destroy(&p_hashq); 
    assert(status == SUCCESS && !p_hashq); 

    free(keys); 
    keys = NULL; 

    exit(EXIT_SUCCESS); 
}