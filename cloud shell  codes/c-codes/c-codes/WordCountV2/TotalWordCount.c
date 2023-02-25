#include<stdio.h>
void calculateWordCount(char* line, size_t* count);
int main(int argc, char** argv)
{
    FILE* fp = fopen(argv[1],"r");

    char* line = NULL;
    size_t length =0;
    int read;
    size_t count = 0;
    while((read = getline(&line,&length, fp)) != -1)
    {
        //FillVector(WordVec,line);
        calculateWordCount(line, &count);
    }

    printf("Number of words present in given file: %ld \n",count);
    fclose(fp);
    fp = NULL;
}

void calculateWordCount(char* line, size_t* count)
{
    char c = line[0];
    int i = 0;
    while(c != '\n')
    {
        if(c == ' ')
            (*count) = *count + 1;
        c = line[++i];
    }
}