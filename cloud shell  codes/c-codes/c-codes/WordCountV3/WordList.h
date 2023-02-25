#pragma once
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
//#defines
#define MaxWordSize 50

struct WordNode
{
    char* word;
    size_t wordNumber;
    size_t LineNumber;
    struct WordNode* next;
    struct WordNode* prev;
};

struct list
{
    struct WordNode* head;
    size_t size;
    size_t wordSize;
};

typedef struct WordNode node_t;
typedef struct list list_t;

static void generic_insert(node_t* p_beg, node_t* p_mid, node_t* p_end)
{
    p_mid->next = p_end;
    p_mid->prev = p_beg;
    p_beg->next = p_mid;
    p_end->prev = p_mid;
}

node_t* get_node()
{
    node_t* p_new_node = NULL;
    p_new_node = (node_t*)malloc(sizeof(node_t));

    p_new_node->word = NULL;
    p_new_node->wordNumber = 0;
    p_new_node->LineNumber = 0;
    p_new_node->next = NULL;
    p_new_node->prev = NULL;

    return (p_new_node);
}

list_t* creatList()
{
    list_t* new_list = (list_t*)malloc(sizeof(list_t));
    new_list ->head = get_node();
    new_list->head->word = NULL;
    new_list->head->LineNumber = 0;
    new_list ->size = 0;
    new_list->wordSize = 0;
    new_list->head->next = new_list->head;
    new_list->head->prev = new_list->head;
    return (new_list);
}

void destroyList(list_t** p_list)
{
    list_t* d_list = *p_list;
    node_t* p_run = NULL;
    node_t* p_next = NULL;
    for(p_run = d_list->head->next ; p_run != d_list->head ; p_run = p_next)
    {   
        p_next = p_run->next;
        free(p_run->word);
        free(p_run);
    }

    free(d_list);
    *p_list = NULL;
}

node_t* searchWord(list_t* p_list, char* word)
{
    node_t* p_run = NULL;
    if(p_list->size == 0)
    {
        return NULL;
    }
    p_run = p_list->head->next;
    while(p_run != p_list->head)
    {
        if(strcmp(p_run ->word, word) == 0)
            return p_run;
        p_run = p_run->next;
    }
    return NULL;
}

void push_back(list_t* p_list, char* word, int LineNumber)
{
    node_t* e_node = NULL;
    e_node = searchWord(p_list, word);
    if(e_node == NULL)
    {
        
        e_node = get_node();
        if(e_node == NULL)
        {
            fprintf(stderr, "malloc():fatal:out of memory:pushBack\n"); 
            exit(EXIT_FAILURE); 
        }

        e_node->word = (char*)malloc(strlen(word));
        if(e_node->word == NULL)
        {
            fprintf(stderr, "malloc():fatal:out of memory for word:pushBack\n"); 
            exit(EXIT_FAILURE);
        }

        strcpy(e_node->word, word);
        e_node->wordNumber = 1;
        e_node->LineNumber = LineNumber;
        generic_insert(p_list->head, e_node, p_list->head->next);
        p_list->size = p_list->size + 1;
        p_list->wordSize = p_list->wordSize + 1;
    }
    else {
        e_node->wordNumber = e_node->wordNumber + 1;
        p_list->wordSize = p_list->wordSize + 1; 
    }
}

void ReadFileAndFillList(list_t* p_list , FILE* fp)
{
    int i,j;
    char c;
    size_t LineNumber = 0;
    char* buffer = (char*)malloc(MaxWordSize);
    while(fscanf(fp,"%c",&c) != EOF)
    {
        if(c == ' ' || c == '.' || c == ',' || c == 47 || c == '-')
        {
            printf("%s\n",buffer);
            push_back(p_list,buffer,LineNumber);
            j = 0;
            memset(buffer,0,MaxWordSize*sizeof(char));
        }
        else if(c == '\n')
        {
            LineNumber++;
            printf("%s\n",buffer);
            push_back(p_list,buffer,LineNumber);
            j = 0;
            memset(buffer,0,MaxWordSize*sizeof(char));
        }
        else
        {
            buffer[j] = c;
            ++j;    
        }
    }
}

void insertNode(list_t* p_list , char* word)
{

}

size_t get_size(list_t* p_list)
{
    return p_list->size;
}

size_t getWordCount(list_t* p_list, char* word)
{
    node_t* p_run = NULL;
    p_run = p_list->head->next;
    while(p_run != p_list->head)
    {
        if(strcmp(p_run->word, word) == 0)
            return p_run->wordNumber;
        p_run = p_run->next;
    }
    return 0;
}

size_t get_total_words(list_t* wordlist)
{
    return wordlist->wordSize;
}

