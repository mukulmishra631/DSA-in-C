#include <stdio.h>
#include <limits.h>
#include <stdlib.h>

void printArray(int *arr, int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int maximum(int arr[], int n)
{
    int max = INT_MIN;
    for (int i = 0; i < n; i++)
    {
        if (max < arr[i])
        {
            max = arr[i];
        }
    }
    return max;
}
void countSort(int *arr, int n)
{
    int i, j;
    // Find the maximum element in arr
    int max = maximum(arr, n);

    // Create the count array
    int *count = (int *)malloc((max + 1) * sizeof(int));

    // Initialize the array elements to 0
    for (i = 0; i < max+1; i++)
    {
        count[i] = 0;
    }

    // Increment the corresponding index in the count array
    for (i = 0; i < n; i++)
    {
        count[arr[i]] = count[arr[i]]+1;
    }
    i = 0; // Counter for count array
    j = 0; // Counter for main array arr[]
    while (i < max + 1)
    {
        if (count[i] > 0)
        {
            arr[j] = i;
            count[i] = count[i] - 1; // count[i]-- ;
            j++;
        }
        else
            i++;
    }
}

int main()
{
    int arr[] = {3, 6, 2, 13, 12};
    int n = 5;
    printf("Before sorting:\n");
    printArray(arr, n);
    countSort(arr, n);
    printf("After sorting:\n");
    printArray(arr, n);
    return 0;
}

// Analysis
// Takes extra space (max + 1)
// Time complexity : O(m+n)