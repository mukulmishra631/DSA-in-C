#include<stdio.h>

int linearSearch(int arr[], int size, int element){
    for(int i = 0; i< size; i++)
    {
        if(arr[i]==element){
            return i;
        }
    }
    return -1;  
}

int main() {
int arr[] = {1,2,3,4,56,67,43,24,354};
int size = sizeof(arr)/sizeof(int);
int element  = 67 ;
int searchIndex = linearSearch(arr, size, element);
printf("The element %d was found at index %d \n", element, searchIndex);
    return 0;
}