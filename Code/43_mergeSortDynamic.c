#include <stdio.h>
#include <stdlib.h> 

void printArray(int *A, int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d ", A[i]);
    }
    printf("\n");
}

void merge(int A[], int mid, int low, int high)
{
    int i, j, k;
    i = low;
    j = mid + 1;
    k = 0;
    // Dynamically allocate size for temporary array B 
    int size = high - low + 1;
    int *B = (int *)malloc(size*sizeof(int));

    if(B == NULL){
        printf("Memory allocation failed!\n");
        return ;
    }

    while (i <= mid && j <= high)
    {
        if (A[i] < A[j])
        {
            B[k++] = A[i++];
        }
        else
        {
            B[k++] = A[j++];
        }
    }
    while (i <= mid)
    {
        B[k++] = A[i++];
    }
    while (j <= high)
    {
        B[k++] = A[j++];
    }

    // Copy back to original array
    for (int i = low; i <= high; i++)
    {
        A[low + i] = B[i];
    }
    free(B); // Free dynamically allocated memory
}

void mergeSort(int A[], int low, int high)
{
    int mid;
    if (low < high)
    {
        mid = (low + high) / 2;
        // mid = low + (high - low) / 2;
        mergeSort(A, low, mid);
        mergeSort(A, mid + 1, high);
        merge(A, mid, low, high);
    }
}
int main()
{

    int A[] = {3, 6, 2, 13, 12};
    int n = 5;
    printf("Before sorting:\n");
    printArray(A, n);
    mergeSort(A, 0, 4);
    printf("After sorting:\n");
    printArray(A, n);
    return 0;
}