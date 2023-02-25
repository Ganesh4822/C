#include "MeshLoading.h"
#include <stdlib.h>

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

    VectorofAllVectors* vec = initialize();
    ReadMeshFileAndFillTraingleVector(vec, inFile);
    inFile = fopen(argv[1], "r");
    //Reassignment of FilePointer is Necessory Heere
    
    PrintTriangle(vec, inFile);

    Destroy(&vec);
    printf("SUCCESS\n");
    

}   