
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


typedef struct texture
{
    float u1;
    float u2;
}Texture;

typedef struct normal
{
    float nx;
    float ny;
    float nz;
}Normal;

typedef struct Co_ordinate_vector
{
    Co_ordinator** coordinate_array;
    int size;
}Co_ordinate_vector;

typedef struct normal_vector
{
    Normal** normal_array;
    int size;
}Normal_vector;

typedef struct texture_vector
{
    Texture** texture_array;
    int size;
}Texture_vector;

typedef struct VectorofAllVectors
{
    Co_ordinate_vector* coord_vec;
    Normal_vector* norm_vec;
    Texture_vector* tex_vec;
    
}VectorofAllVectors;

VectorofAllVectors* initialize()
{
    VectorofAllVectors* all_vectors = (VectorofAllVectors*)malloc(sizeof(VectorofAllVectors));
    all_vectors->coord_vec = (Co_ordinate_vector*)malloc(sizeof(Co_ordinate_vector));
    all_vectors->norm_vec = (Normal_vector*)malloc(sizeof(Normal_vector));
    all_vectors->tex_vec = (Texture_vector*)malloc(sizeof(Texture_vector));
    
    all_vectors->coord_vec->coordinate_array = NULL;
    all_vectors->coord_vec->size = 0;

    all_vectors->norm_vec->normal_array = NULL;
    all_vectors->norm_vec->size = 0;

    all_vectors->tex_vec->texture_array = NULL;
    all_vectors->tex_vec->size = 0;

    return all_vectors; 
}

void FillCoOrdinatorVector(Co_ordinate_vector* vec , char** StringArray)
{
    vec->coordinate_array = (Co_ordinator**)realloc(vec->coordinate_array, (vec->size + 1) * sizeof(Co_ordinator*));
    if(vec->coordinate_array == NULL)
    {
        fprintf(stderr, "realloc():fatal:out of memory\n"); 
        exit(EXIT_FAILURE);
    }
    //printf("realloc successful\n");

    vec->size = vec->size + 1;
    //printf("Size :: %d\n",vec->size);
    vec->coordinate_array[vec->size - 1] = (Co_ordinator*)malloc(sizeof(Co_ordinator));
    //printf("%f, %f , %f \n",atof(StringArray[1]), atof(StringArray[2]),atof(StringArray[3]));
    vec->coordinate_array[vec->size - 1]->x = atof(StringArray[1]);
    vec->coordinate_array[vec->size - 1]->y = atof(StringArray[2]);
    vec->coordinate_array[vec->size - 1]->z = atof(StringArray[3]);
    //printf("Addition Success\n");

    
}

void FillTextureVector(Texture_vector* vec , char** StringArray)
{
    vec->texture_array = (Texture**)realloc(vec->texture_array, (vec->size + 1) * sizeof(Texture*));
    if(vec->texture_array == NULL)
    {
        fprintf(stderr, "realloc():fatal:out of memory\n"); 
        exit(EXIT_FAILURE);
    }

    vec->size = vec->size + 1;
    vec->texture_array[vec->size - 1] = (Texture*)malloc(sizeof(Texture));
    if(vec->texture_array[vec->size - 1] == NULL)
    {
        fprintf(stderr, "malloc():fatal:out of memory::FillTextureArray\n"); 
        exit(EXIT_FAILURE);
    }
    vec->texture_array[vec->size - 1]->u1 = atof(StringArray[1]);
    vec->texture_array[vec->size - 1]->u2 = atof(StringArray[2]);
    
}

void FillNormalVector(Normal_vector* vec , char** StringArray)
{
    vec->normal_array = (Normal**)realloc(vec->normal_array, (vec->size + 1)* sizeof(Normal*));
    if(vec->normal_array == NULL)
    {
        fprintf(stderr, "realloc():fatal:out of memory::FillNormalVector\n"); 
        exit(EXIT_FAILURE);
    }
    vec->size = vec->size + 1;
    vec->normal_array[vec->size - 1] = (Normal*)malloc(sizeof(Normal));
    if(vec->normal_array[vec->size - 1] == NULL)
    {
         fprintf(stderr, "malloc():fatal:out of memory::FillNormalArray\n"); 
        exit(EXIT_FAILURE);
    }
    vec->normal_array[vec->size - 1]->nx = atof(StringArray[1]);
    vec->normal_array[vec->size - 1]->ny = atof(StringArray[2]);
    vec->normal_array[vec->size - 1]->nz = atof(StringArray[3]);
}

void FillAppropriateVector(VectorofAllVectors* vec, char** StringArray)
{
    if(StringArray == NULL)
        return; 
    if(strcmp(StringArray[0],"v")==0)
    {
        FillCoOrdinatorVector(vec->coord_vec, StringArray);
    }
    else if(strcmp(StringArray[0],"vt") == 0)
    {
        FillTextureVector(vec->tex_vec,StringArray);
    }
    else if(strcmp(StringArray[0],"vn")== 0)
    {
        FillNormalVector(vec->norm_vec, StringArray);
    }
     else
    {
        return;
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

char** TokeniseStringAndStoreIntoArray(char* line,int* size,char* token)
{   
    
    char** array = NULL;
    *size = 0;
    
    char *p = strtok (line, token);
    
    while(p != NULL)
    {   
        (*size)++;
        array = (char**)realloc(array,sizeof(char*)*  (*size));
        array[*size - 1]  = (char*)malloc(strlen(p));
        strcpy(array[*size - 1],p);
        p = strtok(NULL,token);
    }
    
    
    //printf("Line read succesfully\n");
    return array;

}

void Printa(Co_ordinate_vector* vec)
{
    size_t i;
    printf("count of Cordinate vec :%d\n",vec->size);
    for(i = 0 ; i < vec->size ; i++)
    {
        printf("C :%f  :  %f  :  %f \n" , vec->coordinate_array[i]->x, vec->coordinate_array[i]->y, vec->coordinate_array[i]->y);
    }
}

void Printb(Normal_vector* vec)
{
    size_t i;
    printf("count of Normal vec :%d\n",vec->size);
    for(i = 0 ; i < vec->size ; i++)
    {
        printf("N : %f  :  %f  :  %f \n" , vec->normal_array[i]->nx, vec->normal_array[i]->ny, vec->normal_array[i]->nz);
    }
}

void Printc(Texture_vector* vec)
{
    size_t i;
    printf("count of Texture vec :%d\n",vec->size);
    for(i = 0 ; i < vec->size ; i++)
    {
        printf("Tx : %f  :  %f\n" , vec->texture_array[i]->u1, vec->texture_array[i]->u2);
    }
}


void PrintCoordinateWithIndex(Co_ordinate_vector* vec,int index)
{
    printf("x :: %f, y :: %f , z :: %f \n", vec->coordinate_array[index - 1]->x
    ,vec->coordinate_array[index - 1]->y,vec->coordinate_array[index - 1]->z);
}

void PrintTextureWithIndex(Texture_vector* vec, int index)
{
    printf("u1 :: %f, u2 :: %f \n",vec->texture_array[index-1]->u1 , vec->texture_array[index-1]->u2);
}

void PrintVectorWithIndex(Normal_vector* vec , int index)
{
    printf("nx :: %f, ny :: %f, nz :: %f\n", vec->normal_array[index-1]->nx,
    vec->normal_array[index-1]->ny, vec->normal_array[index-1]->nz);
}

void PrintTriangle(VectorofAllVectors* vec , FILE* fp)
{
    char line[MAX_LINE_LENGTH];
    int count = 0;
    int size = 0;
    char** stringArray = NULL;
    char** triangleArray = NULL;
    int trianlgeCount = 0;
    int size2 = 0;
    while((count = getline1(fp,line,MAX_LINE_LENGTH)) > 0)
    {
        
        stringArray = TokeniseStringAndStoreIntoArray(line,&size," ");
        if(strcmp(stringArray[0],"f")==0)
        {
            printf("Traingle number :: %d->\n",++trianlgeCount);
            int i;
            for(i = 1 ; i < size ; i++)
            {
                triangleArray = TokeniseStringAndStoreIntoArray(stringArray[i],&size2,"/");
                printf("Coordinate No :: %d->\n",i);
                PrintCoordinateWithIndex(vec->coord_vec,atoi(triangleArray[0]));
                PrintTextureWithIndex(vec->tex_vec,atoi(triangleArray[1]));
                PrintVectorWithIndex(vec->norm_vec,atoi(triangleArray[2]));

            }
            /*
                todo
                for(int i = 1 ; i < stringArray.size() ;i++)
                {
                    triangleArray = TokeniseStringAndStoreIntoArray(stringArray[i],&size,count,"/")  
                    print(vec->CoordinateVec->coordinateArray[atoi(triangleArray[0]) + 1]);
                    print(vec->NormalVec->NormalArray[atoi(triangleArray[1]) + 1]);
                    printf(vec->TextureVec->textureArray[atoi(triangleArray[i]) + 1]);
                }
            */
        }
        
    }
}


int main()
{
   char line[MAX_LINE_LENGTH];
   FILE *inFile = fopen("MonkeyHeadFinal.OBJ", "r");
   int count = 0 ;
   char** array;
   int i; 
   int size;
   int trianlgeCount = 0;
//    Co_ordinate_vector* vec = (Co_ordinate_vector*)malloc(sizeof(Co_ordinate_vector));
//    if(vec == NULL)
//    {
//         fprintf(stderr,"FAILED");
//    }
//    vec->coordinate_array= NULL;
//    vec->size = 0;

   VectorofAllVectors* newvec = initialize();
   while ((count = getline1(inFile, line, MAX_LINE_LENGTH)) != -1) {
        //printf("The line gotten was \"%s\" and was %d chars long.\n", line, count);
        //printf("count = %d\n",count);
        array = TokeniseStringAndStoreIntoArray(line,&size," ");
        FillAppropriateVector(newvec,array);
        
        // for(i = 0 ; i < 3 ; i++)
        // {
        //     printf("%s\t", array[i]);
        // // }
        // if(strcmp(array[0],"f")==0)
        // {
        //      printf("Traingle number :: %d\n",++trianlgeCount);
        // }
        int i = 0;
        if(array!= NULL)
        {
            for(i = 0 ; i < size ;i++)
            {
                free(array[i]);
            }
            free(array);
        }
        

        
    
    }

    // Printa(newvec->coord_vec);
    // Printb(newvec->norm_vec);
    // Printc(newvec->tex_vec);
    printf("size of c vector = %d\n",newvec->coord_vec->size);
    printf("size of N vector = %d\n",newvec->norm_vec->size);
    printf("size of T vector = %d\n",newvec->tex_vec->size);
    printf("count = %d\n",count);
    inFile = fopen("MonkeyHeadFinal.OBJ", "r");
    //Reassignment of FilePointer is Necessory Heere
    
    PrintTriangle(newvec, inFile);
    printf("SUCCESS\n");
}
/*
client

*/