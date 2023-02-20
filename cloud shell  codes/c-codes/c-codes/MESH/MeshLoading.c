#include "MeshLoading.h"

/*
Assigns memory to all the Vectors
and return pointer to the 
*/
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
    return NULL;
    
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

char** TokeniseStringAndStoreIntoArray(char* line,int* size, int count)
{
    char** array = NULL;
    if(count > 0)
    {
        char *p = strtok (line, " ");
        *size = 0;
        while(p != NULL)
        {   
            (*size)++;
            array = (char**)realloc(array, sizeof(char*)* (*size));
            array[*size - 1]  = (char*)malloc(strlen(p));
            strcpy(array[*size - 1],p);
            p = strtok(NULL," ");
        }
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
    if(vec->coordinate_array[vec->size - 1] == NULL)
    {
        fprintf(stderr, "malloc():fatal:out of memory\n"); 
        exit(EXIT_FAILURE);
    }
    vec->coordinate_array[vec->size - 1]->x = atof(StringArray[1]);
    vec->coordinate_array[vec->size - 1]->y = atof(StringArray[2]);
    vec->coordinate_array[vec->size - 1]->z = atof(StringArray[3]);
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
        return ;
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

void ReadMeshFileAndFillTraingleVector(VectorofAllVectors* vec,FILE* file)
{
    char line[MAX_LINE_LENGTH];
    int count = 0;
    int size = 0;
    char** stringArray = NULL;
    while((count = getline1(file, line, MAX_LINE_LENGTH)) != -1)
    {
        stringArray = TokeniseStringAndStoreIntoArray(line,&size,count);
        //Todo Pass this char** array as an parameter so that the same array can be used again and Again 
        // and can be refreshed with memset
        //OR you can free the array here so that there will be NO memery leak
        FillAppropriateVector(vec,stringArray);
        if(stringArray != NULL)
            free(stringArray);
    }

}