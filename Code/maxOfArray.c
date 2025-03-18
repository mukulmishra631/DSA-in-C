// Code for finding maximum from an array

#include <stdio.h>

// Function to display the elements of the array
void display(int arr[], int n)
{
    // Array traversal
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

// Function to find the maximum element of the array
int maxOfArray(int arr[], int size, int *index)
{
    int max = arr[0];              // Assume the first element to be the maximum
    *index = 0;                    // Index of first element
    for (int i = 1; i < size; i++) // start from 1 since 0 is assumed to be the maximum
    {
        if (arr[i] > max)
        {
            max = arr[i];
            *index = i; // Store index of max
        }
    }
    return max; // Return the maximum value and this should be after the loop otherwise the code will just compare starting two values and print the answer which is wrong , so put this return after the loop such that the code traverse and compares the full array and then prints the result
}

int main()
{
    int arr[] = {5, 9, 1, 17, 11, 13, 6};
    int size = sizeof(arr) / sizeof(arr[0]);
    int index, max;
    display(arr, size);
    printf("Now we are searching the maximum value !\n");
    max = maxOfArray(arr, size, &index);
    printf("The maximum value is %d , found at index %d\n", max, index);
    return 0;
}