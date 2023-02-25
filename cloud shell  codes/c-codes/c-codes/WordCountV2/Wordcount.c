#include"ResizableArray.h"

void FillVector(vector* vec, char* line,size_t lineCount);
static size_t lineCount;

int main(int argc, char** argv)
{
    if(argc != 2)
    {
        printf("Please Enter Correct Number if Arguments\n");
        exit(EXIT_FAILURE);
    }

    FILE* inFile = fopen(argv[1],"r");
    if(inFile == NULL)
    {
         printf("Unable to open File\n");
        return -1;
    }
    vector* wordVec = createVector();
    
    char* line = NULL;
    size_t length;
    int read;
    ReadFileAndFillVector(wordVec,inFile);
    //ShowVector(wordVec);
    printf("Size of vector is %ld\n",getSize(wordVec));
    printf("Total Words in File = %ld\n",getTotalWordCount(wordVec));
    char searchString[20];
    while(1)
    {
        printf("Enter the String you want to search\n");
        scanf("%s",searchString);
        int count = searchWordcount(wordVec,searchString);
        printf("string %s is present %d time\n",searchString,count);
    }

    DestroyVector(&wordVec);
    fclose(inFile);
}

void FillVector(vector* vec,char * line,size_t LineNumber)
{
    char c = line[0];
    int count;
    int i = 0;
    int j = 0;
     
    char* buffer = (char*)malloc(sizeof(char)*20);
    while(c != 10)
    {
        
        if(c == 32 || c == 46 || c == 44 || c == 47 ||c == 45)
        {
            //printf("%s\n",buffer);
            //pushBack(vec,buffer);
            pushBackVersionV3(vec,buffer,LineNumber);
            j = 0;
            memset(buffer,0,20*sizeof(char));
        }
        //if(c != 32)
        else
        {
            buffer[j] = c;
            ++j;
        }
        c = line[++i];   
    }
    free(buffer);
    //pushBack(vec,buffer);
}