#include <stdio.h>

void printArray(int *arr, int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void selctionSort(int *arr, int n)
{
    int indexOfMin, temp;
    printf("Running Selection sort...\n");
    for(int i = 0; i < n - 1 ; i++)
    {
        indexOfMin = i;
        for(int j = i+1; j<n; j++)
        {
            if(arr[j] < arr[indexOfMin]){
                indexOfMin = j;
            }
        }
        // Swap arr[i] and arr [ indexOfMin]
        temp = arr[i];
        arr[i] = arr[indexOfMin];
        arr[indexOfMin] = temp;
    }
}

int main()
{
// Input Array (There will be total n-1 passes. 5-1 = 4 in this case!)
    //  00  01  02  03  04
    // |03, 05, 02, 13, 12

    // After first pass
    //  00  01  02  03  04
    //  02,|05, 03, 13, 12

    // After second pass
    // 00  01  02  03  04
    // 02, 03,|05, 13, 12

    // After third pass
    // 00  01  02  03  04
    // 02, 03, 05,|13, 12

    // After fourth pass
    // 00  01  02  03  04
    // 02, 03, 05, 12,|13

    int arr[] = {3, 5, 2, 13, 12};
    int n = 5;
    printArray(arr, n);
    selctionSort(arr, n);
    printArray(arr, n);
    return 0;
}