#include<stdio.h>
#include<stdlib.h>

//PRACTICE No 1

#define TRUE 1
void merge(int * arr, int p,int q,int r)
{
    int *a1;
    int *a2;
    int N1;
    int N2;

    N1 = q - p + 1;
    N2 = r - q;

    a1 = (int*)calloc(N1,sizeof(int));
    if(a1 == NULL)
    {
        fprintf(stderr,"calloc():fetal():out of memory\n");
        exit(EXIT_FAILURE);
    }

    a2 = (int*)calloc(N2,sizeof(int)*N2);
    if(a2 == NULL)
    {
        fprintf(stderr,"calloc():fetal():out of memory\n");
        exit(EXIT_FAILURE);
    }

    int index;
    for(index = 0 ; index < N1 ; index++)
    {
        a1[index] = arr[p + index];
    }

    for(index = 0 ; index < N2 ; index++)
    {
        a2[index] = arr[q+1+index];
    }

    int  i  = 0;
    int  j = 0;
    int k = 0;

    while(TRUE)
    {
        if(a1[i] <= a2[j])
        {
            arr[p+k] = a1[i];
            i++;
            k++;
            if(i == N1)
            {
                while(j < N2)
                {
                    arr[p+k] = a2[j];
                    j++;
                    k++;
                }
                break;
                
            } 
        }
        else
        {
            arr[p+k] = a2[j];
            j++;
            k++;
            if(j == N2)
            {
                while(i < N1)
                {
                    arr[p+k] = a1[i];
                    i++;
                    k++;
                }
                break;
            }
        }
    }

    free(a1);
    a1 = NULL;
    free(a2);
    a2 = NULL;

}

void mergesort(int *arr , int l , int r)
{
    int mid;
    if(r > l)
    {
        mid = l + (r - l)/2;

        mergesort(arr,l,mid);
        mergesort(arr, mid + 1 ,r);

        merge(arr,l ,mid,r);
    }
}

void showArray(int *arr, int N,const char* imsg)
{
    if(imsg)
        printf("%s\n",imsg);
    int i = 0;
    for( i = 0 ; i < N ; i++)
    {
        printf("arr[%d] = %d\n",i,arr[i]);
    }
}

void TestMerge()
{
    int arr[14] = {1,2,12,43,23,123312,2341,5,2,62,1,4,63,12};
    showArray(arr, 14,"before sort");
    mergesort(arr,0, 13);
    showArray(arr,14,"after sort");

}


int main()
{
    TestMerge();
}

