#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include<string.h>
#include<dirent.h>
char* concat(char* dir_name, char * base_name);
int main(int argc , char** argv)
{
    DIR* dp = NULL;
    struct dirent* dentry = NULL;

    if(argc != 2)
    {
        fprintf(stderr,"Usage error: %s ,dir path ", argv[0]);
        exit(EXIT_FAILURE);
    }

    dp = opendir(argv[1]);
    assert(dp);

    
}

char* concat(char* dir_name, char * base_name)
{
    char* buffer = NULL;
    int len = strlen(dir_name)+1+strlen(base_name);
    buffer = (char*)malloc(strlen(dir_name)+1+strlen(base_name));
    char c;
    
    int i=0;
    c = dir_name[0];
    // while(c != '\0')
    // {
    //     buffer[i] = c;
    //     c= dir_name[++i];
    // }
    // buffer[i]  = '/';
    // c = 
    //strcpy()
    return "";

}


