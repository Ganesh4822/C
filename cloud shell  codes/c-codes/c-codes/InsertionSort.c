
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

void FillArray(int* arr, size_t N);
void showArray(int *arr, size_t N ,char* msg);
void sort(int *arr, ssize_t N);
void insert_at_sorting_position(int *arr, ssize_t N);

int main(int argc, char** argv)
{
    if(argc != 2)
    {
        fprintf(stderr,"Wrong Number of Arguments");
        exit(EXIT_FAILURE);
    }
    size_t N = atoll(argv[1]);

    int *arr = (int*)calloc(N,sizeof(int));
    if(arr == NULL)
    {
        fprintf(stderr, "calloc():fatal:out of memory\n"); 
        exit(EXIT_FAILURE); 
    }
    FillArray(arr,N);

    showArray(arr,N,"Before sorting");
    sort(arr, N);
    showArray(arr,N,"After sorting");

    free(arr);

}

void FillArray(int* arr, size_t N)
{
    ssize_t i ;
    srand(time(0));

    for(i = 0 ; i < N ; i++)
    {
        arr[i] = rand() % 100;
    }
}

void showArray(int *arr, size_t N ,char* msg)
{
     ssize_t i; 

    if(msg)
        puts(msg); 

    for(i = 0; i < N; ++i)
        printf("p[%ld]:%d\n", i, arr[i]); 
}

// void insert_at_sorting_position(int *arr, ssize_t N)
// {
//     int key;
//     ssize_t i;
//     i = N-2;
//     key = arr[N-1];

//     while(i > -1 && arr[i] > key)
//     {
//         arr[i+1] = arr[i];
//         i = i -1;
//     }
//     arr[i + 1] = key;
// }

void sort(int *arr, ssize_t N)
{
    ssize_t i;
    for(i = 2 ; i <= N ;i++)
    {
        insert_at_sorting_position(arr , i);
    }
}


void insert_at_sorting_position(int *arr, ssize_t N)
{
    ssize_t i;
    int key = arr[N-1];
    i = N -2;

    while(i > -1 && arr[i] > key)
    {
        arr[i+1] = arr[i];
        i = i-1;
    }
    arr[i+1] = key;
}


