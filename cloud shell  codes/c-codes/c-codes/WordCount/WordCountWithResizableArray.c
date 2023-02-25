#include "ResizableArray.h"
#include <stdlib.h>

void FillVector(vector* vec,char * line);

int main(int argc , char** argv)
{
    if(argc != 2)
    {
        printf("Please Enter Correct Number if Arguments\n");
        exit(EXIT_FAILURE);
    }
    FILE *inFile = fopen(argv[1], "r");
    vector* WordVec = createVector();
    if(inFile == NULL)
    {
        printf("Unable to open File\n");
        return -1;
    }
    char* line = NULL;
    size_t length =0;
    int read;
    int count = 0;
    // while((read = getline(&line,&length, inFile)) != -1)
    // {
    //     FillVector(WordVec,line);        
    // }
    ReadFileAndFillVector(WordVec, inFile);
    //showVector(WordVec);
    char searchString[20];
    while(1)
    {
        printf("Enter the String you want to search\n");
        scanf("%s",searchString);
        int count = searchWord(WordVec,searchString);
        printf("string %s is present %d time\n",searchString,count);
    }
    
    DeleteVector(&WordVec);
    //printf("Total  words in File are : %d", count);
}

void FillVector(vector* vec,char * line)
{
    char c = line[0];
    int count;
    int i = 0;
    int j = 0;
     
    char* buffer = (char*)malloc(sizeof(char)*MaxWordSize);
    while(c != '\n')
    {
        
        if(c == ' ' || c == '.' || c == ',' || c == 47 || c == '-')
        {
            pushBack(vec,buffer);
            j = 0;
            memset(buffer,0,20*sizeof(char));
        }
        else
        {
            buffer[j] = c;
            ++j;
        }
        c = line[++i];   
    }
    free(buffer);
    
}