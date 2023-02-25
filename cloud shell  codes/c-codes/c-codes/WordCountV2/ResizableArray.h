#pragma once
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

//#defines
#define MaxWordSize 50

//Structs 
typedef struct structWord
{
    char* word;
    size_t line_number;
    size_t word_number;
}structWord;

typedef struct vector
{
    structWord** pp;
    size_t size;
    size_t totalWordCount;
}vector;

/*
@input:     Node

@output:    Address of newly allocated instance of 
                struct vector

To Allocate New Instance of string vector 
*/

vector* createVector()
{
    vector* WordVec = (vector*)malloc(sizeof(vector));
    WordVec->pp = NULL;
    WordVec->size = 0;
    WordVec->totalWordCount = 0;

    return WordVec;
}

/*
@input:     Address of the  pointer to the vector Instance user wants to delete.

@output:    None

Delete the memory allocated to the Vector instance
*/

void DestroyVector(vector** vecobj)
{
    size_t i =0 ;
    for(i = 0 ; i < (*vecobj)->size ; i++)
    {
        free((*vecobj)->pp[i]->word);
        free((*vecobj)->pp[i]);
    }
    free((*vecobj)->pp);
    free((*vecobj));
    *vecobj= NULL;
}

/*
@input-1 : Address of the vector instance

@input-2 : Address of the structWord user wants to push to the vector. 

@output : None

*/
void pushBack(vector* vec, structWord* obj)
{
    vec->pp = (structWord**)realloc(vec->pp,(vec->size + 1) * sizeof(structWord*));

    if(vec->pp == NULL)
    {
        fprintf(stderr, "realloc():fatal:out of memory\n"); 
        exit(EXIT_FAILURE);
    }

    vec->size = vec->size + 1;
    vec->totalWordCount = vec->totalWordCount + 1;
    vec->pp[vec->size - 1] = obj;
}

/*
@input-1 : Address of the Vector instance.

@input-2 : string user wants to searc in the vector.

@output : Count of the word in the vector.

*/
size_t searchWordcount(vector* vec , char* word)
{
    int i;
    size_t count = 0;
    for(i = vec->size - 1 ; i >= 0 ; i--)
    {
        if(strcmp(vec->pp[i]->word,word) == 0)
            return vec->pp[i]->word_number;
    }

    return 0;
}

/*
@input-1 : Address of the vector instance.

@input-2 : string user wants to searc in the vector.

@output : pointer to the StructWord instance which has the searchTerm.
*/
structWord* searchWord(vector* vec , char* word)
{
    size_t i ;
    size_t count = 0;

    for(i = 0 ; i < vec->size ; i++)
    {
        if(strcmp(vec->pp[i]->word, word) == 0)
            return vec->pp[i];
    }
    return NULL;
}

/*
@input-1 : Address of the vector instance.

@input-2 : String user wants to insert in vector.

@input-3 : LineNumber 

@output : None

creates the structword instance and adds the structword to vector.
*/
void pushBackVersionV2(vector* vec, char* word, int LineNumber)
{
    structWord* wordv = (structWord*)malloc(sizeof(structWord));
    if(wordv == NULL)
    {
        fprintf(stderr, "malloc():fatal:out of memory:pushBackV2\n"); 
        exit(EXIT_FAILURE); 
    }

    wordv->word = (char*)malloc(strlen(word));
    if(wordv->word == NULL)
    {
        fprintf(stderr, "malloc():fatal:out of memory:pushBackV2\n"); 
        exit(EXIT_FAILURE); 
    }
    
    strcpy(wordv->word ,word);
    //A more efficient algorithm can be implementated for this by getting the latest word number and
    //Incrementing it by one for the latest word
    size_t count = searchWordcount(vec,word);

    wordv->word_number = count+1;
    wordv->line_number = LineNumber;
    
    vec->pp = (structWord**)realloc(vec->pp,(vec->size + 1) * sizeof(structWord*));
    
    if(vec->pp == NULL)
    {
        fprintf(stderr, "realloc():fatal:out of memory\n"); 
        exit(EXIT_FAILURE);
    }

    vec->size = vec->size + 1;
    vec->totalWordCount = vec->totalWordCount + 1;
    vec->pp[vec->size - 1] = wordv;

}

/*
@input-1 : pointer to the vector instance.

@input-2 : string which user wants to store in the vector.

@input-3 : LineNumber 

@output : None

checks if the word is already present in the vector 
if present increments the wordcount.
if not present add the vector to the vector.
*/
void pushBackVersionV3(vector* vec, char* word, int LineNumber)
{
   structWord* pWord = searchWord(vec, word);
   if(pWord == NULL)
   {
       pWord = (structWord*)malloc(sizeof(structWord));
       if(pWord == NULL)
        {
            fprintf(stderr, "malloc():fatal:out of memory:pushBackV3\n"); 
            exit(EXIT_FAILURE); 
        }

        pWord->word = (char*)malloc(strlen(word));
        if(pWord->word == NULL)
        {
            fprintf(stderr, "malloc():fatal:out of memory:pushBackV3\n"); 
            exit(EXIT_FAILURE); 
        }
        
        strcpy(pWord->word, word);
        pWord->word_number = 1;
        pWord->line_number = LineNumber;

        vec->pp = (structWord**)realloc(vec->pp,(vec->size+1)*sizeof(structWord*));
        if(vec->pp == NULL)
        {
            fprintf(stderr, "realloc():fatal:out of memory\n"); 
            exit(EXIT_FAILURE);
        }

        vec->size = vec->size + 1;
        //*(vec->pp + (vec->size -1)) = wordv;
        vec->totalWordCount = vec->totalWordCount + 1;
        vec->pp[vec->size - 1] = pWord;
   }
    else {
        pWord->word_number = pWord->word_number + 1;
        vec->totalWordCount = vec->totalWordCount + 1;   
    }
}

/*
@input-1 : Address of the vector instance.

@output : None

Prints the Word , WordCount , LineNumber
*/
void ShowVector(vector* vec)
{
    size_t i ;

    for(i = 0 ; i < vec->size ; i++)
    {
        printf("Pvector->arr[%zu] = %s , wordNUmber = %zu , LineNumber = %zu\n",
        i,vec->pp[i]->word,vec->pp[i]->word_number,vec->pp[i]->line_number);
    }
}

/*
@input-1 : Address of the the vector instance

@output : Size of the Vector.
*/
ssize_t getSize(vector* vec)
{   
    return vec->size;
}

/*
@input-1 : pointer to the Vector instance.

@input-2 : address of the File.

@output : None

Reads the file character by charactor and Adds the words into the 
vector using helper routine PushBackVersionV3.
*/
void ReadFileAndFillVector(vector* vec,FILE* fp)
{
    int i , j;
    char c;
    size_t LineNumber = 0;
    char* buffer = (char*)malloc(sizeof(char)*MaxWordSize);
    while(fscanf(fp,"%c",&c) != EOF)
    {
        if(c == ' ' || c == '.' || c == ',' || c == 47 || c == '-')
        {
            pushBackVersionV3(vec,buffer,LineNumber);
            j = 0;
            memset(buffer,0,MaxWordSize*sizeof(char));
        }
        else if(c == '\n')
        {
            LineNumber++;
            pushBackVersionV3(vec,buffer,LineNumber);
            j = 0;
            memset(buffer,0,MaxWordSize*sizeof(char));
        }
        else
        {
            buffer[j] = c;
            ++j;    
        }

    }
    free(buffer);
}

size_t getTotalWordCount(vector* vec)
{
    return vec->totalWordCount;
}

