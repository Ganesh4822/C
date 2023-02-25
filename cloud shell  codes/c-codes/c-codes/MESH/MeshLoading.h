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
    struct Triangle**  traigle_array;
    int size;
}Triagle_vector;

typedef struct VectorofAllVectors
{
    Co_ordinate_vector* coord_vec;
    Normal_vector* norm_vec;
    Texture_vector* tex_vec;
    
}VectorofAllVectors;

VectorofAllVectors* initialize();
void Destroy(VectorofAllVectors** vec);
Triagle_vector* createTriangleVector();
//File Routines
size_t getline1(FILE *stream, char *buf, size_t size);
char** TokeniseStringAndStoreIntoArray(char* line,int* size,char* token);
//Vector Routines
void FillCoOrdinatorVector(Co_ordinate_vector* vec , char** StringArray);
void FillTextureVector(Texture_vector* vec , char** StringArray);
void FillNormalVector(Normal_vector* vec , char** StringArray);
void FillAppropriateVector(VectorofAllVectors* vec, char** StringArray);
void ReadMeshFileAndFillTraingleVector(VectorofAllVectors* vec,FILE* file);
void PrintCoordinateWithIndex(Co_ordinate_vector* vec,int index);
void PrintTriangle(VectorofAllVectors* vec , FILE* fp);
void PrintTextureWithIndex(Texture_vector* vec, int index);

//Helper
void destroyCoordinateVector(Co_ordinate_vector* vec);
void destroyTextureVector(Texture_vector* vec);
void destroyNormalVector(Normal_vector* vec);