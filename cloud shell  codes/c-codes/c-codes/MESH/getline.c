
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include<string.h>

#define MAX_LINE_LENGTH 255 

/* Retrieves a line of text from the stream provided
 * and places it into @buf until a new line character is
 * reached or the number of characters read is > @size - 1.
 * This function will null-terminate the provided buffer.
 *
 * @param[in] -- stream -- the stream
 * @param[in] -- buf -- a buffer big enough for @size chars.
 * @param[in] -- size -- the maximum number of chars to read (must
 *    include room for a null terminator
 * @return -- the number of characters read from the stream.
 */
// size_t getline1(FILE *stream, char *buf, size_t size)
// {
//     size_t count = 0;
//     char c;
//     while ((c = (char)getc(stream)) != '\n' && count < size - 1) {
//         buf[count++] = c;
//     }
//     buf[count] = '\0';
//     return count;
// }
typedef struct Co_ordinator
{
    float x;
    float y;
    float z;
}Co_ordinator;

typedef struct Co_ordinate_vector
{
    Co_ordinator** coordinate_array;
    int size;
}Co_ordinate_vector;

void FillCoOrdinatorVector(Co_ordinate_vector* vec , char** StringArray)
{
    vec->coordinate_array = (Co_ordinator**)realloc(vec->coordinate_array, (vec->size + 1) * sizeof(Co_ordinator*));
    if(vec->coordinate_array == NULL)
    {
        fprintf(stderr, "realloc():fatal:out of memory\n"); 
        exit(EXIT_FAILURE);
    }
    printf("realloc successful\n");

    vec->size = vec->size + 1;
    printf("Size :: %d\n",vec->size);
    vec->coordinate_array[vec->size - 1] = (Co_ordinator*)malloc(sizeof(Co_ordinator));
    printf("%f, %f , %f \n",atof(StringArray[1]), atof(StringArray[2]),atof(StringArray[3]));
    vec->coordinate_array[vec->size - 1]->x = atof(StringArray[1]);
    vec->coordinate_array[vec->size - 1]->y = atof(StringArray[2]);
    vec->coordinate_array[vec->size - 1]->z = atof(StringArray[3]);
    printf("Addition Success\n");

    
}

void FillAppropriateVector(Co_ordinate_vector* vec, char** StringArray)
{
    if(strcmp(StringArray[0],"v")==0)
    {
        FillCoOrdinatorVector(vec, StringArray);
    }
}

int getline1(FILE *stream, char *buf, size_t size)
{
    int count = 0;
    char c;
    while ((c = (char)getc(stream)) != '\n' && count < size - 1) {
        if(c == EOF)
            return -1;
        buf[count++] = c;
    }
    buf[count] = '\0';
    return count;
}

char** TokeniseStringAndStoreIntoArray(char* line,int* size)
{
    char *p = strtok (line, " ");
    char** array = NULL;
    *size = 0;
    while(p != NULL)
    {   
        (*size)++;
        array = (char**)realloc(array,sizeof(char*)*  (*size));
        array[*size - 1]  = (char*)malloc(strlen(p));
        strcpy(array[*size - 1],p);
        p = strtok(NULL," ");
    }
    printf("Line read succesfully\n");
    return array;

}

void Printa(Co_ordinate_vector* vec)
{
    size_t i;
    for(i = 0 ; i < vec->size ; i++)
    {
        printf("%f  :  %f  :  %f \n" , vec->coordinate_array[i]->x, vec->coordinate_array[i]->y, vec->coordinate_array[i]->y);
    }
}

int main()
{
   char line[MAX_LINE_LENGTH];
   FILE *inFile = fopen("sample.txt", "r");
   int count = 0 ;
   char** array;
   int i; 
   int size;
   Co_ordinate_vector* vec = (Co_ordinate_vector*)malloc(sizeof(Co_ordinate_vector));
   if(vec == NULL)
   {
        fprintf(stderr,"FAILED");
   }
   vec->coordinate_array= NULL;
   vec->size = 0;
   while ((count = getline1(inFile, line, MAX_LINE_LENGTH)) != -1) {
        //printf("The line gotten was \"%s\" and was %d chars long.\n", line, count);
        printf("count = %d\n",count);
        array = TokeniseStringAndStoreIntoArray(line,&size);
        FillAppropriateVector(vec,array);
        free(array);
        for(i = 0 ; i < 4 ; i++)
        {
            printf("%s/t", array[i]);
        }
    
    }

    Printa(vec);
    
    printf("count = %d\n",count);
}