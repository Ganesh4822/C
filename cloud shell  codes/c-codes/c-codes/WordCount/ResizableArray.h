#pragma once

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MaxWordSize 50

typedef struct vector
{
    char** Array;
    int size;
}vector;

/*
@input:     Node

@output:    Address of newly allocated instance of 
                struct vector

To Allocate New Instance of string vector 
*/

vector* createVector()
{
    vector* newVec = (vector*)malloc(sizeof(vector));

    newVec->Array = NULL;
    newVec->size = 0;
    return (newVec);
}

/*
@input:     Address of the vector Instance user wants to delete.

@output:    None

Delete the memory allocated to the Vector instance
*/
void DeleteVector(vector** vec)
{
    int i;
    for(i = 0 ; i < (*vec) ->size ; i++)
    {
        free((*vec)->Array[i]);
        (*vec)->Array[i] = NULL;
    }
    free((*vec)->Array);
    (*vec)->Array =NULL;
    free((*vec));
    vec = NULL;
}

/*
@input - 1:  pointer to the String vector instance

@input - 2: string instance which needs to be added to the vector

@output:    None

Insert the element at the end of vector
*/
void pushBack(vector* vec,  char* word)
{
    vec->Array = (char**)realloc(vec->Array,(vec->size + 1) * sizeof(char*));
    if(vec->Array == NULL)
    {
        fprintf(stderr, "realloc():fatal:out of memory\n"); 
        exit(EXIT_FAILURE);
    }


    vec->size = vec->size + 1;
    vec->Array[vec->size -1] = (char*)malloc(strlen(word)*sizeof(char));
    if(vec->Array[vec->size -1] == NULL)
    {
        fprintf(stderr, "malloc():fatal:out of memory\n"); 
        exit(EXIT_FAILURE);
    }
    strcpy(vec->Array[vec->size -1],word);
}

/*
@input:     pointer to the vector instance.

@output:    Node

Prints the Vector Elements.
*/

void showVector(vector* vec)
{
    int i = 0 ;
    for(i = 0 ; i < vec->size ; i++)
    {
         printf("p_vector->p_arr[%d]:%s\n", i, vec->Array[i]);
    }
}

/*
@input-1 :    Pointer to the vector instance.

@input-2 :    searchTerm user wants to search in the vector

@output :     Count of the total occurrences of the searchTerm.

return the count of occurrences of input string.
*/
int searchWord(vector* vec,const char* searchTerm)
{
    int i = 0 ;
    int count = 0;
    for( i = 0 ; i < vec ->size ; i++)
    {
        if(strcmp(searchTerm,vec->Array[i]) == 0)
        {
           count++;
        }
    }
    return count;
}

/*
@input-1 : Pointer to the Vector Instance

@input-2: Pointer to the File Instance 

@Output : None

Recieves the File pointer and Adds words to the vector instance.
*/

void ReadFileAndFillVector(vector* vec,FILE* fp)
{
    char c;
    char* buffer = (char*)malloc(sizeof(char)*MaxWordSize);
    int i,j;
    while(fscanf(fp,"%c",&c) != EOF)
    {
        if(c == ' ' || c == '.' || c == ',' || c == 47 || c == '-'||c == '\n')
        {
            pushBack(vec,buffer);
            j = 0;
            memset(buffer,0,MaxWordSize*sizeof(char));
        }
        else {
            buffer[j] = c;
            ++j;      
        }
        
    }
    free(buffer);
}