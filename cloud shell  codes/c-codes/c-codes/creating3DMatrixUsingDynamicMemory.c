#include<stdio.h>
#include<stdlib.h>
#include<time.h>

typedef long long sssize_t;
int*** returnMatrix(sssize_t x, sssize_t y , sssize_t z);
void FillMatrix(int*** M,sssize_t x, sssize_t y , sssize_t z);
void ShowMatrix(int*** M,sssize_t x, sssize_t y , sssize_t z);
void FreeMatrix(int ***M,sssize_t x, sssize_t y , sssize_t z);
int main(int argc, char** argv)
{
    if(argc != 4)
    {
        printf("please Enter the corrrect number of arguments\n");
        return -1;
    }
    sssize_t x = atoll(argv[1]);
    sssize_t y = atoll(argv[2]);
    ssize_t z = atoll(argv[3]);

    int*** M = returnMatrix(x,y,z);
    FillMatrix(M,x,y,z);
    ShowMatrix(M,x,y,z);
    FreeMatrix(M,x,y,z);
    printf("SUCCESS\n");

}
//2*3*5
int*** returnMatrix(sssize_t x, sssize_t y , sssize_t z)
{
    sssize_t i , j;
    int*** M = (int***)malloc(x*sizeof(int**));
    for(i = 0; i<x ; i++)
    {
        M[i] = (int**)malloc(y*sizeof(int*));
        for(j = 0 ; j < y ; j++)
        {
            M[i][j] = (int*)malloc(sizeof(int)*z);
        }
    }
    return M;
}

void FillMatrix(int*** M,sssize_t x, sssize_t y , sssize_t z)
{
    srand(time(0));
    sssize_t i,j,k;
    for(i = 0 ; i < x ;i++)
    {
        for(j = 0 ; j < y ; j++)
        {
            for(k = 0 ; k < z ; k++)
            {
                M[i][j][k] = rand();
            }
        }
    }
}

void ShowMatrix(int*** M,sssize_t x, sssize_t y , sssize_t z)
{
    sssize_t i,j,k;
    for(i = 0 ; i < x ;i++)
    {
        for(j = 0 ; j < y ; j++)
        {
            for(k = 0 ; k < z ; k++)
            {
                printf("M[%lld][%lld][%lld] : %d\n",i,j,k,M[i][j][k]);
            }
        }
    }

}

void FreeMatrix(int ***M,sssize_t x, sssize_t y , sssize_t z)
{
    sssize_t i,j,k;
    for(i = 0 ; i < x; i++)
    {
        for( j = 0 ; j < y ; j++)
        {
            free(M[i][j]);
        }
        free(M[i]);
    }

    free(M);
    M = NULL;
}


