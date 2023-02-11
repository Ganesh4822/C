#include<stdio.h>
#include<string.h>
#include<stdlib.h>

//#defines
#define MAX_LINE_LENGTH 255 
//Structs
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

// typedef struct point
// {
//     Co_ordinator* co_ordinate;
//     Texture* tex;
//     Normal* normal;
// }Point;

typedef struct point
{
    size_t index_Co_ordinator;
    size_t index_texture;
    size_t index_normal;
}Point;

typedef struct Triangle
{
    Point* point1;
    Point* point2;
    Point* point3;

}Traigle;

//Vectors
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

// typedef struct Point_vector
// {
//     Point** point_array;
//     int size;
// }Point_vector;

typedef struct Triagle_vector
{
    Triangle**  traigle_array;
    int size;
}Triagle_vector;

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

Triagle_vector* createTriangleVector()
{
    Triagle_vector* new_vec = (Triagle_vector*)malloc(sizeof(Triagle_vector));
    new_vec->traigle_array = NULL;
    
    
}

size_t getline1(FILE *stream, char *buf, size_t size)
{
    size_t count = 0;
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
        array = (char**)realloc(array, sizeof(char*)* (*size));
        array[*size - 1]  = (char*)malloc(strlen(p));
        strcpy(array[*size - 1],p);
        p = strtok(NULL," ");
    }
    return array;

}



// void AnalysizeLineandFillApropriateVector(char* line)
// {
//     char c;
//     while((c = (char)scanf(line,"%c",&c) != '\n')
//     {
        
//     }
// }
void FillCoOrdinatorVector(Co_ordinate_vector* vec , char** StringArray)
{
    vec->coordinate_array = (Co_ordinator**)realloc(vec->coordinate_array, (vec->size + 1) * sizeof(Co_ordinator*));
    if(vec->coordinate_array == NULL)
    {
        fprintf(stderr, "realloc():fatal:out of memory\n"); 
        exit(EXIT_FAILURE);
    }

    vec->size = vec->size + 1;
    vec->coordinate_array[vec->size - 1] = (Co_ordinator*)malloc(sizeof(Co_ordinator));
    if(vec->coordinate_array == NULL)
    {
        fprintf(stderr, "realloc():fatal:out of memory\n"); 
        exit(EXIT_FAILURE);
    }
    vec->coordinate_array[vec->size - 1]->x = atof(StringArray[1]);
    vec->coordinate_array[vec->size - 1]->y = atof(StringArray[2]);
    vec->coordinate_array[vec->size - 1]->z = atof(StringArray[3]);


}

void FillAppropriateVector(VectorofAllVectors* vec, char** StringArray)
{
    if(strcmp(StringArray[0],"v")==0)
    {
        FillCoOrdinatorVector(vec->coord_vec, StringArray);
    }
}

void ReadMeshFileAndFillTraingleVector(VectorofAllVectors* vec,FILE* file)
{
    char line[MAX_LINE_LENGTH];
    int count = 0;
    char** stringArray = NULL;
    while((count = getline1(file, line, MAX_LINE_LENGTH)) != -1)
    {
        stringArray = TokeniseStringAndStoreIntoArray(line,&count);
        //Todo Pass this char** array as an parameter so that the same array can be used again and Again 
        // and can be refreshed with memset
        //OR you can free the array here so that there will be NO memery leak
        FillAppropriateVector(vec,stringArray);
        //Free(stringArray)
    }

}