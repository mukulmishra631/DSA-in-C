#include <stdio.h>

int binarySearch(int arr[], int size, int element)
{
    int low, mid, high;
    low = 0;
    high = size-1;
    // Keep searching until low <= high
    while (low <= high)
    {
        mid = (low + high) / 2; // C automatically takes the greatest integer function
        if (arr[mid] == element)
        {
            return mid;
        }
        if (arr[mid] < element)
        {
            low = mid + 1; // mid isiliye nhi kiye kyuki mid to element hai hi nhi isiliye mid+1 krenge
        }
        else
        {
            high = mid - 1; // again mid inclusive nhi hoga kyuki mid element nhi hai to use high nhi bnayenge , mid-1 ko high bnayenge
        }
    }
    //Searching ends
    return -1;
    
}

int main()
{
    // Sorted array for binary search
    int arr[] = {1,3,5,7,8,23,35,46,56,68,79,89,354,654};
    int size = sizeof(arr)/sizeof(int);
    int element;
    printf("Enter the element to be searched : \n");
    scanf("%d", &element);
    // int element = 79;
    int searchIndex = binarySearch(arr, size, element);
    printf("The element %d was found at index %d using binary search algorithm.", element, searchIndex);
    return 0;
}