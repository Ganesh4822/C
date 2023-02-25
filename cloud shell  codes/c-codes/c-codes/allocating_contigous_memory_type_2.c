#include<stdio.h>
#include<stdlib.h>

int main(void)
{
    int rows =2;
    int columns = 5;
    int i;
    int *matrix  = (int*)malloc(rows*columns*sizeof(int));
    // as memory is allocateed at once we cannot use the subscript
    //operater directly. We need to manually calculate indexes.
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < columns; j++) {
            *(matrix + (i*columns) + j) = i*j;
        }
    }
    free(matrix);
    matrix = NULL;
    return 0;


    
}
